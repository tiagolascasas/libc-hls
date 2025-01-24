#include "libc-hls-async-kernel.h"
void hls_abort(char* buf, async_kernel_info* info, bool is_last) {
   if(info->idx == -1) {
      info->idx = 0;
   }
   if(is_last) {
      info->is_closed = true;
   }
}

void hls_assert(char* buf, async_kernel_info* info, bool is_last, int expression) {
   if(info->idx == -1) {
      info->idx = 0;
   }
   *((int *)(buf + info->idx)) = (int)expression;
   info->idx += sizeof(int);
   if(is_last) {
      info->is_closed = true;
   }
}
