#ifndef _LIBC_HLS_REIMPLEMENTED_H_
#define _LIBC_HLS_REIMPLEMENTED_H_

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
double hls_atof(char const * string);
int atoi(char const * string);
long atol(char const * string);
void * bsearch(void const * key, void const * base, size_t num, size_t size);
#endif
