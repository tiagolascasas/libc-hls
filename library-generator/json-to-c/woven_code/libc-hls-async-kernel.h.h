#ifndef _LIBC_HLS_ASYNC_KERNEL_H_H_
#define _LIBC_HLS_ASYNC_KERNEL_H_H_

#include <features-time64.h>
#include <math.h>
#include <nl_types.h>
#include <regex.h>
#include <setjmp.h>
#include <signal.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>
#include <wchar.h>
#include <wctype.h>
#include "libc-hls-types.h"
void hls_abort(int8_t* buf, hls_async_info* info, bool is_last);
void hls_assert(int8_t* buf, hls_async_info* info, bool is_last, int expression);
#endif
