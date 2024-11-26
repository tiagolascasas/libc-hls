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

    async_call_buf *putchar0 = create_async_buf_fixed(PUTCHAR, 1);

    auto bo_v1 = xrt::bo(device, size * sizeof(int), kernel.group_id(0));
    auto bo_v2 = xrt::bo(device, size * sizeof(int), kernel.group_id(0));
    auto bo_vo = xrt::bo(device, size * sizeof(int), kernel.group_id(0));
    auto bo_putchar0_buf = xrt::bo(device, putchar0->info->size, kernel.group_id(0));
    auto bo_putchar0_info = xrt::bo(device, sizeof(async_info), kernel.group_id(0));

    int *host_ptr_v1 = bo_v1.map<int *>();
    int *host_ptr_v2 = bo_v2.map<int *>();
    int *host_ptr_vo = bo_vo.map<int *>();
    int8_t *host_ptr_putchar0_buf = bo_putchar0_buf.map<int8_t *>();
    async_info *host_ptr_putchar0_info = bo_putchar0_info.map<async_info *>();

    std::cout << "Created buffers\n";

    std::memcpy(host_ptr_v1, v1, size * sizeof(int));
    std::memcpy(host_ptr_v2, v2, size * sizeof(int));
    std::memcpy(host_ptr_vo, vo, size * sizeof(int));
    std::memcpy(host_ptr_putchar0_buf, putchar0->buffer, putchar0->info->size);
    std::memcpy(host_ptr_putchar0_info, putchar0->info, sizeof(async_info));

    std::cout << "Copied data into buffers\n";

    bo_v1.sync(XCL_BO_SYNC_BO_TO_DEVICE);
    bo_v2.sync(XCL_BO_SYNC_BO_TO_DEVICE);
    bo_putchar0_buf.sync(XCL_BO_SYNC_BO_TO_DEVICE);
    bo_putchar0_info.sync(XCL_BO_SYNC_BO_TO_DEVICE);

    std::cout << "Synced buffers to FPGA, executing kernel...\n";

    auto kernel_execution = kernel(bo_v1, bo_v2, bo_vo, size, bo_putchar0_buf, bo_putchar0_info);

    std::cout << "Kernel is executing\n";

    std::cout << "Polling for asynchronous calls using a rate of " << polling_rate << "ms\n";
    bool valid;
    do
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(polling_rate));
        bo_putchar0_buf.sync(XCL_BO_SYNC_BO_TO_DEVICE);
        bo_putchar0_info.sync(XCL_BO_SYNC_BO_TO_DEVICE);
        valid = listen_async_putchar(host_ptr_putchar0_buf, host_ptr_putchar0_info);
    } while (valid);
    std::cout << "\nAll async calls processed\n";

    kernel_execution.wait();

    std::cout << "Kernel finished executing\n";

    bo_vo.sync(XCL_BO_SYNC_BO_FROM_DEVICE);
    bo_putchar0_buf.sync(XCL_BO_SYNC_BO_FROM_DEVICE);
    bo_putchar0_info.sync(XCL_BO_SYNC_BO_FROM_DEVICE);

    std::cout << "Synced data back to host\n";

    std::memcpy(vo, host_ptr_vo, size * sizeof(int));
}

int main(int argc, char **argv)
{
    int v1[DATA_SIZE] = {0};
    int v2[DATA_SIZE] = {0};
    int vo[DATA_SIZE] = {0};
    int reference[DATA_SIZE] = {0};
    unsigned int polling_rate = (argc > 1) ? std::stoi(argv[1]) : 200;

    for (int i = 0; i < DATA_SIZE; ++i)
    {
        v1[i] = i;
        v2[i] = i;
        reference[i] = v1[i] + v2[i];
    }
    wrapped_vadd(v1, v2, vo, DATA_SIZE, polling_rate);

    std::cout << (std::memcmp(vo, reference, DATA_SIZE) ? "Checksum failed" : "Checksum passed") << std::endl;
    return 0;
}
