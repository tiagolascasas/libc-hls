#include "libc-hls-async-kernel.h.h"
void hls_abort(int8_t* buf, hls_async_info* info, bool is_last) {
   if(info->idx == -1) {
      info->idx = 0;
   }
   if(is_last) {
      info->is_closed = true;
   }
}

void hls_assert(int8_t* buf, hls_async_info* info, bool is_last, int expression) {
   if(info->idx == -1) {
      info->idx = 0;
   }
   *((int *)(buf + info->idx)) = (int)expression;
   info->idx += sizeof(int);
   if(is_last) {
      info->is_closed = true;
   }
}
