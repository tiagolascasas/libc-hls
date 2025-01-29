#include "experimental/xrt_bo.h"
#include "experimental/xrt_device.h"
#include "experimental/xrt_kernel.h"
#include "synthcalls.h"
#include <chrono>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <thread>

const auto program_start_time = std::chrono::steady_clock::now();

std::ostream& timestamp(std::ostream& os)
{
    auto   now             = std::chrono::steady_clock::now();
    double elapsed_seconds = std::chrono::duration<double>(now - program_start_time).count();

    os << "[" << std::setw(8) << std::fixed << std::setprecision(3) << elapsed_seconds << "] ";
    return os;
}

void wrapped_vadd(int* v1, int* v2, int* vo, int size, unsigned int polling_rate, int c1, int c2, int c3, unsigned int max_iter)
{
    auto device = xrt::device(0);
    auto uuid   = device.load_xclbin("./vadd.xclbin");
    auto kernel = xrt::kernel(device, uuid, "vadd");

    async_call* putchar0 = create_async_call_fixed(PUTCHAR, 1);
    async_call* assert0  = create_async_call_fixed(ASSERT, 1);
    async_call* printf0  = create_async_call_variadic(PRINTF, 1, 1);

    std::cout << timestamp << "Creating CPU-FPGA buffers\n";
    auto bo_v1            = xrt::bo(device, size * sizeof(int), kernel.group_id(0));
    auto bo_v2            = xrt::bo(device, size * sizeof(int), kernel.group_id(1));
    auto bo_vo            = xrt::bo(device, size * sizeof(int), kernel.group_id(2));
    auto bo_putchar0_buf  = xrt::bo(device, putchar0->kernel_info->size, kernel.group_id(4));
    auto bo_putchar0_info = xrt::bo(device, sizeof(async_kernel_info), kernel.group_id(5));
    auto bo_assert0_buf   = xrt::bo(device, assert0->kernel_info->size, kernel.group_id(6));
    auto bo_assert0_info  = xrt::bo(device, sizeof(async_kernel_info), kernel.group_id(7));
    auto bo_printf0_buf   = xrt::bo(device, printf0->kernel_info->size, kernel.group_id(8));
    auto bo_printf0_info  = xrt::bo(device, sizeof(async_kernel_info), kernel.group_id(9));

    std::cout << timestamp << "Copying data into buffers\n";
    bo_v1.write(v1);
    bo_v1.sync(XCL_BO_SYNC_BO_TO_DEVICE);

    bo_v2.write(v2);
    bo_v2.sync(XCL_BO_SYNC_BO_TO_DEVICE);

    bo_putchar0_info.write(putchar0->kernel_info);
    bo_putchar0_info.sync(XCL_BO_SYNC_BO_TO_DEVICE);

    bo_assert0_info.write(assert0->kernel_info);
    bo_assert0_info.sync(XCL_BO_SYNC_BO_TO_DEVICE);

    std::cout << timestamp << "Preparing kernel run\n";
    auto kernel_run = xrt::run(kernel);
    kernel_run.set_arg(0, bo_v1);
    kernel_run.set_arg(1, bo_v2);
    kernel_run.set_arg(2, bo_vo);
    kernel_run.set_arg(3, size);
    kernel_run.set_arg(4, bo_putchar0_buf);
    kernel_run.set_arg(5, bo_putchar0_info);
    kernel_run.set_arg(6, bo_assert0_buf);
    kernel_run.set_arg(7, bo_assert0_info);
    kernel_run.set_arg(8, bo_printf0_buf);
    kernel_run.set_arg(9, bo_printf0_info);
    kernel_run.set_arg(10, c1);
    kernel_run.set_arg(11, c2);
    kernel_run.set_arg(12, c3);

    std::cout << timestamp << "Starting kernel run\n";

    std::cout << timestamp << "Polling for asynchronous calls using a rate of " << polling_rate << "ms\n";
    bool         valid;
    unsigned int i = 0;
    do
    {
        valid = false;

        bo_putchar0_info.sync(XCL_BO_SYNC_BO_TO_DEVICE);
        bo_putchar0_info.read(putchar0->kernel_info);

        bo_putchar0_buf.sync(XCL_BO_SYNC_BO_TO_DEVICE);
        bo_putchar0_buf.read(putchar0->buffer);

        bo_assert0_info.sync(XCL_BO_SYNC_BO_TO_DEVICE);
        bo_assert0_info.read(assert0->kernel_info);

        bo_assert0_buf.sync(XCL_BO_SYNC_BO_TO_DEVICE);
        bo_assert0_buf.read(assert0->buffer);

        bo_printf0_info.sync(XCL_BO_SYNC_BO_TO_DEVICE);
        bo_printf0_info.read(printf0->kernel_info);

        bo_printf0_buf.sync(XCL_BO_SYNC_BO_TO_DEVICE);
        bo_printf0_buf.read(printf0->buffer);

        std::this_thread::sleep_for(std::chrono::milliseconds(polling_rate));
        auto is_finished = kernel_run.state() == ERT_CMD_STATE_COMPLETED;
        std::cout << timestamp << "Polling access " << i << (is_finished ? ", kernel has finished" : ", kernel is still running") << std::endl;

        std::cout << timestamp << " " << printf0->kernel_info->idx << " " << printf0->host_info->idx << std::endl;
        valid = valid || listen_async_putchar(putchar0);
        valid = valid || listen_async_assert(assert0);
        valid = valid || listen_async_printf(printf0, "This is a printf() from the FPGA, at iteration %d\n");

        if (i == 0)
        {
            kernel_run.start();
        }
        if (i == max_iter)
        {
            std::cout << timestamp << "Reached maximum number of iterations, exiting polling loop\n";
            valid = false;
        }
        i++;
    } while (valid);

    if (kernel_run.state() != ERT_CMD_STATE_COMPLETED)
    {
        std::cout << timestamp << "All async calls processed, waiting for kernel to finish...\n";
        kernel_run.wait();
        std::cout << timestamp << "Kernel has finished\n";
    }
    else
    {
        std::cout << timestamp << "All async calls processed, kernel has finished\n";
    }

    std::cout << timestamp << "Syncing the output buffer from the FPGA back to the CPU\n";
    bo_vo.sync(XCL_BO_SYNC_BO_FROM_DEVICE);
    bo_vo.read(vo);
}

int main(int argc, char** argv)
{
    unsigned int polling_rate = (argc > 1) ? std::stoi(argv[1]) : 100;
    int          data_size    = (argc > 2) ? std::stoi(argv[2]) : 256;
    int          c1           = (argc > 3) ? std::stoi(argv[3]) : 50;
    int          c2           = (argc > 4) ? std::stoi(argv[4]) : 150;
    int          c3           = (argc > 5) ? std::stoi(argv[5]) : 200;
    unsigned int max_iter     = (argc > 6) ? std::stoi(argv[6]) : 1000;

    int v1[data_size]        = {0};
    int v2[data_size]        = {0};
    int vo[data_size]        = {0};
    int reference[data_size] = {0};

    for (int i = 0; i < data_size; ++i)
    {
        v1[i]        = i;
        v2[i]        = i;
        reference[i] = v1[i] + v2[i];
    }
    wrapped_vadd(v1, v2, vo, data_size, polling_rate, c1, c2, c3, max_iter);

    std::cout << timestamp << (std::memcmp(vo, reference, data_size) ? "Vadd output is incorrect" : "Vadd output is correct") << std::endl;
    return 0;
}
