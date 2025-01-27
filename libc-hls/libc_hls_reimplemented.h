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
wint_t btowc(int c);
char * ctime(time_t const * time);
char * ctime64(time_t const * time);
char * ctime_r(time_t const * time, char * buf);
char * ctime64_r(time_t const * time, char * buf);
double difftime(time_t time2, time_t time1);
double difftime64(time_t time2, time_t time1);
#endif
