#include "libc_hls_async_host_alloc.h"
hls_async_call* hls_abort_alloc(unsigned int n_calls) {
   size_t buf_size = (1) * n_calls;
   int8_t* buf = (int8_t*)malloc(buf_size);

   hls_async_call* call = (hls_async_call*)malloc(sizeof(hls_async_call));
   call->kernel_info->size = buf_size;
   call->kernel_info->idx = -1;
   call->kernel_info->is_closed = false;
   call->buffer = buf;
   call->host_idx = -1;

   return call;
}

hls_async_call* hls_assert_alloc(unsigned int n_calls) {
   size_t buf_size = (sizeof(int)) * n_calls;
   int8_t* buf = (int8_t*)malloc(buf_size);

   hls_async_call* call = (hls_async_call*)malloc(sizeof(hls_async_call));
   call->kernel_info->size = buf_size;
   call->kernel_info->idx = -1;
   call->kernel_info->is_closed = false;
   call->buffer = buf;
   call->host_idx = -1;

   return call;
}
