#include "libc_hls_async_kernel.h"
void hls_abort(char* buf, hls_async_info* info, bool is_last) {
   if(info->idx == -1) {
      info->idx = 0;
   }
   *((int8_t *)(buf + info->idx)) = (int8_t)true;
   info->idx += sizeof(int8_t);
   if(is_last) {
      info->is_closed = true;
   }
}

void hls_assert(char* buf, hls_async_info* info, bool is_last, int expression) {
   if(info->idx == -1) {
      info->idx = 0;
   }
   *((int *)(buf + info->idx)) = (int)expression;
   info->idx += sizeof(int);
   if(is_last) {
      info->is_closed = true;
   }
}

void hls_exit(char* buf, hls_async_info* info, bool is_last, int status) {
   if(info->idx == -1) {
      info->idx = 0;
   }
   *((int *)(buf + info->idx)) = (int)status;
   info->idx += sizeof(int);
   if(is_last) {
      info->is_closed = true;
   }
}

int hls_fclose(char* buf, hls_async_info* info, bool is_last) {
   if(info->idx == -1) {
      info->idx = 0;
   }
   *((int8_t *)(buf + info->idx)) = (int8_t)true;
   info->idx += sizeof(int8_t);
   if(is_last) {
      info->is_closed = true;
   }
}

int hls_fflush(char* buf, hls_async_info* info, bool is_last) {
   if(info->idx == -1) {
      info->idx = 0;
   }
   *((int8_t *)(buf + info->idx)) = (int8_t)true;
   info->idx += sizeof(int8_t);
   if(is_last) {
      info->is_closed = true;
   }
}

int hls_fprintf_int(char* buf, hls_async_info* info, bool is_last, int num) {
   if(info->idx == -1) {
      info->idx = 0;
   }
   *((int *)(buf + info->idx)) = (int)num;
   info->idx += sizeof(int);
   if(is_last) {
      info->is_closed = true;
   }
}

int hls_fprintf_str(char* buf, hls_async_info* info, bool is_last, char[128] str) {
   if(info->idx == -1) {
      info->idx = 0;
   }
   *((char[128] *)(buf + info->idx)) = (char[128])str;
   info->idx += sizeof(char[128]);
   if(is_last) {
      info->is_closed = true;
   }
}

int hls_fputc(char* buf, hls_async_info* info, bool is_last, int c) {
   if(info->idx == -1) {
      info->idx = 0;
   }
   *((int *)(buf + info->idx)) = (int)c;
   info->idx += sizeof(int);
   if(is_last) {
      info->is_closed = true;
   }
}

int hls_fputs(char* buf, hls_async_info* info, bool is_last, char const * string) {
   if(info->idx == -1) {
      info->idx = 0;
   }
   *((char const * *)(buf + info->idx)) = (char const *)string;
   info->idx += sizeof(char const *);
   if(is_last) {
      info->is_closed = true;
   }
}

void hls_close_async(hls_async_info* info) {
   info->is_closed = true;
}
