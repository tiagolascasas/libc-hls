#include <iostream>
#include <thread>
#include <cstring>
#include "experimental/xrt_bo.h"
#include "experimental/xrt_device.h"
#include "experimental/xrt_kernel.h"
#include "synthcalls.h"

#define DATA_SIZE 256

void wrapped_vadd(int *v1, int *v2, int *vo, int size, unsigned int polling_rate)
{
    auto device = xrt::device(0);
    auto uuid = device.load_xclbin("./vadd.xclbin");
    auto kernel = xrt::kernel(device, uuid, "vadd");

    async_call *printf0 = create_async_call_variadic(PRINTF, 1, 7);

    std::cout << "Creating CPU-FPGA buffers\n";
    auto bo_v1 = xrt::bo(device, size * sizeof(int), kernel.group_id(0));
    auto bo_v2 = xrt::bo(device, size * sizeof(int), kernel.group_id(0));
    auto bo_vo = xrt::bo(device, size * sizeof(int), kernel.group_id(0));
    auto bo_printf0_buf = xrt::bo(device, printf0->kernel_info->size, kernel.group_id(0));
    auto bo_printf0_info = xrt::bo(device, sizeof(async_kernel_info), kernel.group_id(0));

    int *host_ptr_v1 = bo_v1.map<int *>();
    int *host_ptr_v2 = bo_v2.map<int *>();
    int *host_ptr_vo = bo_vo.map<int *>();
    int8_t *host_ptr_printf0_buf = bo_printf0_buf.map<int8_t *>();
    async_kernel_info *host_ptr_printf0_info = bo_printf0_info.map<async_kernel_info *>();

    std::cout << "Copying data into buffers\n";
    std::memcpy(host_ptr_v1, v1, size * sizeof(int));
    std::memcpy(host_ptr_v2, v2, size * sizeof(int));
    std::memcpy(host_ptr_vo, vo, size * sizeof(int));
    std::memcpy(host_ptr_printf0_buf, printf0->buffer, printf0->kernel_info->size);
    std::memcpy(host_ptr_printf0_info, printf0->kernel_info, sizeof(async_kernel_info));

    std::cout << "Replacing the buffer in the async call\n";
    replace_async_buf(printf0, host_ptr_printf0_buf, host_ptr_printf0_info);

    std::cout << "Syncing buffers from the CPU to the FPGA\n";
    bo_v1.sync(XCL_BO_SYNC_BO_TO_DEVICE);
    bo_v2.sync(XCL_BO_SYNC_BO_TO_DEVICE);
    bo_printf0_buf.sync(XCL_BO_SYNC_BO_TO_DEVICE);
    bo_printf0_info.sync(XCL_BO_SYNC_BO_TO_DEVICE);

    std::cout << "Starting kernel...\n";
    auto kernel_execution = kernel(bo_v1, bo_v2, bo_vo, size,
                                   bo_printf0_buf, bo_printf0_info);

    std::cout << "Polling for asynchronous calls using a rate of " << polling_rate << "ms\n";
    bool valid;
    unsigned int i = 0;
    do
    {
        i++;
        valid = false;

        std::this_thread::sleep_for(std::chrono::milliseconds(polling_rate));
        auto is_finished = kernel_execution.state() == ERT_CMD_STATE_COMPLETED;
        std::cout << "Polling access " << i << (is_finished ? ", kernel has finished" : ", kernel is still running") << std::endl;

        bo_printf0_info.sync(XCL_BO_SYNC_BO_TO_DEVICE);
        bo_printf0_buf.sync(XCL_BO_SYNC_BO_TO_DEVICE);
        valid = valid || listen_async_printf(printf0, "This is a printf() from the FPGA, at iteration %d\n");
    } while (valid);

    if (kernel_execution.state() != ERT_CMD_STATE_COMPLETED)
    {
        std::cout << "All async calls processed, waiting for kernel to finish...\n";
        kernel_execution.wait();
        std::cout << "Kernel has finished\n";
    }
    else
    {
        std::cout << "All async calls processed, kernel has finished\n";
    }

    std::cout << "Syncing the outout buffer from the FPGA back to the CPU\n";
    bo_vo.sync(XCL_BO_SYNC_BO_FROM_DEVICE);

    std::cout << "Copying output data from buffer into the output array\n";
    std::memcpy(vo, host_ptr_vo, size * sizeof(int));
}

int main(int argc, char **argv)
{
    unsigned int polling_rate = (argc > 1) ? std::stoi(argv[1]) : 200;

    int v1[DATA_SIZE] = {0};
    int v2[DATA_SIZE] = {0};
    int vo[DATA_SIZE] = {0};
    int reference[DATA_SIZE] = {0};

    for (int i = 0; i < DATA_SIZE; ++i)
    {
        v1[i] = i;
        v2[i] = i;
        reference[i] = v1[i] + v2[i];
    }
    wrapped_vadd(v1, v2, vo, DATA_SIZE, polling_rate);

    std::cout << (std::memcmp(vo, reference, DATA_SIZE) ? "Vadd output is incorrect" : "Vadd output is correct") << std::endl;
    return 0;
}
