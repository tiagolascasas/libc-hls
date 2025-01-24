#ifndef _LIBC_HLS_SYNTHESIZABLE_H_
#define _LIBC_HLS_SYNTHESIZABLE_H_

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
int hls_abs(int n);
double hls_acos(double x);
double hls_asin(double x);
double hls_atan(double x);
double hls_atan2(double y, double x);
#endif
