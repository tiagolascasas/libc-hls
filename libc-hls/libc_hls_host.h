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
void * hls_calloc(size_t num, size_t size);
int hls_catclose(nl_catd catd);
char * hls_catgets(nl_catd catd, int set_id, int msg_id, char const * s);
nl_catd hls_catopen(char const * name, int oflag);
void hls_clearerr(FILE * stream);
clock_t hls_clock();
FILE * hls_fdopen(int handle, char const * type);
int hls_feof(FILE * stream);
int hls_ferror(FILE * stream);
int hls_fgetc(FILE * stream);
int hls_fgetpos(FILE * stream, fpos_t * pos);
char * hls_fgets(char * string, int n, FILE * stream);
wint_t hls_fgetwc(FILE * stream);
wchar_t * hls_fgetws(wchar_t * wcs, int n, FILE * stream);
int hls_fileno(FILE * stream);
FILE * hls_fopen(char const * filename, char const * mode);
#endif
