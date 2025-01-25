#ifndef _LIBC_HLS_HOST_H_
#define _LIBC_HLS_HOST_H_

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
char * hls_asctime(struct tm const * time);
char * hls_asctime_r(struct tm const * tm, char * buf);
int hls_atexit(void (*) () func);
#endif
