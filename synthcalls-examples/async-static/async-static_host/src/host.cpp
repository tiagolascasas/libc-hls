#include <cstring>
#include <iostream>

// XRT includes
#include "experimental/xrt_bo.h"
#include "experimental/xrt_device.h"
#include "experimental/xrt_kernel.h"

#include "synthcalls.h"

#define DATA_SIZE 4096

void wrapped_vadd(int *v1, int *v2, int *vo, int size) {
  auto device = xrt::device(0);
  auto uuid = device.load_xclbin("./vadd.xclbin");
  auto kernel = xrt::kernel(device, uuid, "vadd");

  auto bo_v1 = xrt::bo(device, size * sizeof(int), kernel.group_id(0));
  auto bo_v2 = xrt::bo(device, size * sizeof(int), kernel.group_id(0));
  auto bo_vo = xrt::bo(device, size * sizeof(int), kernel.group_id(0));

  int *host_ptr_v1 = bo_v1.map<int *>();
  int *host_ptr_v2 = bo_v2.map<int *>();
  int *host_ptr_vo = bo_vo.map<int *>();

  std::memcpy(host_ptr_v1, v1, size * sizeof(int));
  std::memcpy(host_ptr_v2, v2, size * sizeof(int));
  std::memcpy(host_ptr_vo, vo, size * sizeof(int));

  bo_v1.sync(XCL_BO_SYNC_BO_TO_DEVICE);
  bo_v2.sync(XCL_BO_SYNC_BO_TO_DEVICE);

  auto kernel_execution = kernel(bo_v1, bo_v2, bo_vo, size);
  kernel_execution.wait();

  bo_vo.sync(XCL_BO_SYNC_BO_FROM_DEVICE);

  std::memcpy(vo, host_ptr_vo, size * sizeof(int));
}

int main() {

  int v1[DATA_SIZE] = {0};
  int v2[DATA_SIZE] = {0};
  int vo[DATA_SIZE] = {0};
  int reference[DATA_SIZE] = {0};

  for (int i = 0; i < DATA_SIZE; ++i) {
    v1[i] = i;
    v2[i] = i;
    reference[i] = v1[i] + v2[i];
  }
  wrapped_vadd(v1, v2, vo, DATA_SIZE);

  std::cout << (std::memcmp(vo, reference, DATA_SIZE) ? "Checksum failed" : "Checksum passed") << std::endl;
  return 0;
}
