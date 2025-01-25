#include "libc_hls_async_host_listener.h"
bool hls_abort_listen(hls_async_call* call) {
   if(call->host_idx >= call->kernel_info->idx) {
      return !call->kernel_info->is_closed;
   }
   if(call->host_idx == -1) {
      call->host_idx = 0;
   }
   int8_t *curr_ptr ;
   abort();
   return true;
}

bool hls_assert_listen(hls_async_call* call) {
   if(call->host_idx >= call->kernel_info->idx) {
      return !call->kernel_info->is_closed;
   }
   if(call->host_idx == -1) {
      call->host_idx = 0;
   }
   int8_t *curr_ptr ;
   int8_t *curr_ptr = call->buffer + sizeof(int);
   int expression = *((int *)curr_ptr);
   call->host_idx += sizeof(int);
   assert(expression);
   return true;
}

bool hls_fflush_listen(hls_async_call* call, FILE * stream) {
   if(call->host_idx >= call->kernel_info->idx) {
      return !call->kernel_info->is_closed;
   }
   if(call->host_idx == -1) {
      call->host_idx = 0;
   }
   int8_t *curr_ptr ;
   fflush(stream);
   return true;
}
