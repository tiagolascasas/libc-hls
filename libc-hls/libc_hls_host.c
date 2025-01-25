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
