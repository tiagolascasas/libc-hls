#ifndef _LIBC_HLS_ASYNC_HOST_ALLOC_H_
#define _LIBC_HLS_ASYNC_HOST_ALLOC_H_

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
hls_async_call* hls_abort_alloc(unsigned int n_calls);
hls_async_call* hls_assert_alloc(unsigned int n_calls);
hls_async_call* hls_exit_alloc(unsigned int n_calls);
hls_async_call* hls_fclose_alloc(unsigned int n_calls);
hls_async_call* hls_fflush_alloc(unsigned int n_calls);
hls_async_call* hls_fprintf_int_alloc(unsigned int n_calls);
hls_async_call* hls_fprintf_str_alloc(unsigned int n_calls);
hls_async_call* hls_fputc_alloc(unsigned int n_calls);
hls_async_call* hls_fputs_alloc(unsigned int n_calls);
#endif
