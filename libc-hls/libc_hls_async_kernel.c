#include "libc_hls_async_kernel.h"
void hls_abort(char* buf, hls_async_info* info, bool is_last) {
   if(info->idx == -1) {
      info->idx = 0;
   }
   if(is_last) {
      info->is_closed = true;
   }
}

void hls_assert(char* buf, hls_async_info* info, bool is_last, int expression) {
   if(info->idx == -1) {
      info->idx = 0;
   }
   *((int *)(buf + info->idx)) = (int)expression;
   info->idx += sizeof(int);
   if(is_last) {
      info->is_closed = true;
   }
}

int hls_fflush(char* buf, hls_async_info* info, bool is_last) {
   if(info->idx == -1) {
      info->idx = 0;
   }
   if(is_last) {
      info->is_closed = true;
   }
}

void hls_close_async(hls_async_info* info) {
   info->is_closed = true;
}
