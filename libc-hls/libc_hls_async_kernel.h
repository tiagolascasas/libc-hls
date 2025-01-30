#ifndef _LIBC_HLS_ASYNC_KERNEL_H_
#define _LIBC_HLS_ASYNC_KERNEL_H_

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
void   hls_abort(char* buf, hls_async_info* info, bool is_last);
void   hls_assert(char* buf, hls_async_info* info, bool is_last, int expression);
void   hls_exit(char* buf, hls_async_info* info, bool is_last, int status);
int    hls_fclose(char* buf, hls_async_info* info, bool is_last);
int    hls_fflush(char* buf, hls_async_info* info, bool is_last);
int    hls_fprintf_int(char* buf, hls_async_info* info, bool is_last, int num);
int    hls_fprintf_str(char* buf, hls_async_info* info, bool is_last, char* str, size_t str_size);
int    hls_fputc(char* buf, hls_async_info* info, bool is_last, int c);
int    hls_fputs(char* buf, hls_async_info* info, bool is_last, char const* string);
wint_t fputwc(char* buf, hls_async_info* info, bool is_last, wchar_t wc);
void   hls_close_async(hls_async_info* info);
#endif
