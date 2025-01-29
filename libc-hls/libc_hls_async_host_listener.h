#ifndef _LIBC_HLS_ASYNC_HOST_LISTENER_H_
#define _LIBC_HLS_ASYNC_HOST_LISTENER_H_

#include "libc_hls_types.h"
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
bool hls_abort_listen(hls_async_call* call);
bool hls_assert_listen(hls_async_call* call);
bool hls_exit_listen(hls_async_call* call);
bool hls_fclose_listen(hls_async_call* call, FILE* stream);
bool hls_fflush_listen(hls_async_call* call, FILE* stream);
bool hls_fprintf_int_listen(hls_async_call* call, FILE* stream);
bool hls_fprintf_str_listen(hls_async_call* call, FILE* stream);
bool hls_fputc_listen(hls_async_call* call, int c);
bool hls_fputs_listen(hls_async_call* call, char const* string);
#endif
