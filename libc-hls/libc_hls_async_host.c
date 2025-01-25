#include "libc_hls_async_host.h"
void hls_abort();
void hls_assert(int expression);
void hls_close_async(hls_async_info* info) {
   info->is_closed = true;
}
