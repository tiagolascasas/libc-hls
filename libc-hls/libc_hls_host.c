#include "libc_hls_host.h"
char * hls_asctime(struct tm const * time) {
   
   return asctime(time);
}

char * hls_asctime_r(struct tm const * tm, char * buf) {
   
   return asctime_r(tm, buf);
}

int hls_atexit(void (*) () func) {
   
   return atexit(func);
}

void * hls_calloc(size_t num, size_t size) {
   
   return calloc(num, size);
}

int hls_catclose(nl_catd catd) {
   
   return catclose(catd);
}

char * hls_catgets(nl_catd catd, int set_id, int msg_id, char const * s) {
   
   return catgets(catd, set_id, msg_id, s);
}

nl_catd hls_catopen(char const * name, int oflag) {
   
   return catopen(name, oflag);
}

void hls_clearerr(FILE * stream) {
   
   return clearerr(stream);
}

clock_t hls_clock() {
   
   return clock();
}

FILE * hls_fdopen(int handle, char const * type) {
   
   return fdopen(handle, type);
}

int hls_feof(FILE * stream) {
   
   return feof(stream);
}

int hls_ferror(FILE * stream) {
   
   return ferror(stream);
}

int hls_fgetc(FILE * stream) {
   
   return fgetc(stream);
}

int hls_fgetpos(FILE * stream, fpos_t * pos) {
   
   return fgetpos(stream, pos);
}

char * hls_fgets(char * string, int n, FILE * stream) {
   
   return fgets(string, n, stream);
}

wint_t hls_fgetwc(FILE * stream) {
   
   return fgetwc(stream);
}

wchar_t * hls_fgetws(wchar_t * wcs, int n, FILE * stream) {
   
   return fgetws(wcs, n, stream);
}

int hls_fileno(FILE * stream) {
   
   return fileno(stream);
}

FILE * hls_fopen(char const * filename, char const * mode) {
   
   return fopen(filename, mode);
}
