#include "libc_hls_passthrough.h"
wint_t hls_fputwc(wchar_t wc, FILE * stream) {
   
   return fputwc(wc, stream);
}

int hls_fputws(wchar_t const * wcs, FILE * stream) {
   
   return fputws(wcs, stream);
}

size_t hls_fread(void * buffer, size_t size, size_t count, FILE * stream) {
   
   return fread(buffer, size, count, stream);
}

void hls_free(void * ptr) {
   
   return free(ptr);
}

FILE * hls_freopen(char const * filename, char const * mode, FILE * stream) {
   
   return freopen(filename, mode, stream);
}

double hls_frexp(double x, int * expptr) {
   
   return frexp(x, expptr);
}

int hls_fscanf(FILE * stream, char const * format) {
   
   return fscanf(stream, format);
}

int hls_fseek(FILE * stream, long offset, int origin) {
   
   return fseek(stream, offset, origin);
}

int hls_fsetpos(FILE * stream, fpos_t const * pos) {
   
   return fsetpos(stream, pos);
}

long hls_ftell(FILE * stream) {
   
   return ftell(stream);
}

int hls_fwide(FILE * stream, int mode) {
   
   return fwide(stream, mode);
}

int hls_fwprintf(FILE * stream, wchar_t const * format) {
   
   return fwprintf(stream, format);
}

size_t hls_fwrite(void const * buffer, size_t size, size_t count, FILE * stream) {
   
   return fwrite(buffer, size, count, stream);
}

int hls_fwscanf(FILE * stream, wchar_t const * format) {
   
   return fwscanf(stream, format);
}

double hls_gamma(double x) {
   
   return gamma(x);
}

int hls_getc(FILE * stream) {
   
   return getc(stream);
}

int hls_getchar() {
   
   return getchar();
}

char * hls_getenv(char const * varname) {
   
   return getenv(varname);
}

char * hls_gets(char * buffer) {
   
   return gets(buffer);
}

wint_t hls_getwc(FILE * stream) {
   
   return getwc(stream);
}

wint_t hls_getwchar() {
   
   return getwchar();
}

struct tm * hls_gmtime(time_t const * time) {
   
   return gmtime(time);
}

struct tm * hls_gmtime64(time_t const * time) {
   
   return gmtime64(time);
}

struct tm * hls_gmtime_r(time_t const * time, struct tm * result) {
   
   return gmtime_r(time, result);
}

struct tm * hls_gmtime64_r(time_t const * time, struct tm * result) {
   
   return gmtime64_r(time, result);
}

double hls_hypot(double side1, double side2) {
   
   return hypot(side1, side2);
}

int hls_isalnum(int c) {
   
   return isalnum(c);
}

int hls_isalpha(int c) {
   
   return isalpha(c);
}

int hls_isascii(int c) {
   
   return isascii(c);
}

int hls_isblank(int c) {
   
   return isblank(c);
}

int hls_iscntrl(int c) {
   
   return iscntrl(c);
}

int hls_isdigit(int c) {
   
   return isdigit(c);
}

int hls_isgraph(int c) {
   
   return isgraph(c);
}

int hls_islower(int c) {
   
   return islower(c);
}

int hls_isprint(int c) {
   
   return isprint(c);
}

int hls_ispunct(int c) {
   
   return ispunct(c);
}

int hls_isspace(int c) {
   
   return isspace(c);
}

int hls_isupper(int c) {
   
   return isupper(c);
}

int hls_iswalnum(wint_t wc) {
   
   return iswalnum(wc);
}

int hls_iswalpha(wint_t wc) {
   
   return iswalpha(wc);
}

int hls_iswblank(wint_t wc) {
   
   return iswblank(wc);
}

int hls_iswcntrl(wint_t wc) {
   
   return iswcntrl(wc);
}

int hls_iswctype(wint_t wc, wctype_t wc_prop) {
   
   return iswctype(wc, wc_prop);
}

int hls_iswdigit(wint_t wc) {
   
   return iswdigit(wc);
}

int hls_iswgraph(wint_t wc) {
   
   return iswgraph(wc);
}

int hls_iswlower(wint_t wc) {
   
   return iswlower(wc);
}

int hls_iswprint(wint_t wc) {
   
   return iswprint(wc);
}

int hls_iswpunct(wint_t wc) {
   
   return iswpunct(wc);
}

int hls_iswspace(wint_t wc) {
   
   return iswspace(wc);
}

int hls_iswupper(wint_t wc) {
   
   return iswupper(wc);
}

int hls_iswxdigit(wint_t wc) {
   
   return iswxdigit(wc);
}

int hls_isxdigit(int c) {
   
   return isxdigit(c);
}

double hls_j0(double x) {
   
   return j0(x);
}

double hls_j1(double x) {
   
   return j1(x);
}

double hls_jn(int n, double x) {
   
   return jn(n, x);
}

long hls_labs(long n) {
   
   return labs(n);
}

double hls_ldexp(double x, int exp) {
   
   return ldexp(x, exp);
}

ldiv_t hls_ldiv(long numerator, long denominator) {
   
   return ldiv(numerator, denominator);
}

struct lconv * hls_localeconv() {
   
   return localeconv();
}

struct tm * hls_localtime(time_t const * timeval) {
   
   return localtime(timeval);
}

struct tm * hls_localtime64(time_t const * timeval) {
   
   return localtime64(timeval);
}

struct tm * hls_localtime_r(time_t const * timeval, struct tm * result) {
   
   return localtime_r(timeval, result);
}

struct tm * hls_localtime64_r(time_t const * timeval, struct tm * result) {
   
   return localtime64_r(timeval, result);
}

double hls_log(double x) {
   
   return log(x);
}

double hls_log10(double x) {
   
   return log10(x);
}

void hls_longjmp(jmp_buf env, int value) {
   
   return longjmp(env, value);
}

void * hls_malloc(size_t size) {
   
   return malloc(size);
}

int hls_mblen(char const * string, size_t n) {
   
   return mblen(string, n);
}

int hls_mbrlen(char const * s, size_t n, mbstate_t * ps) {
   
   return mbrlen(s, n, ps);
}

int hls_mbrtowc(wchar_t * pwc, char const * s, size_t n, mbstate_t * ps) {
   
   return mbrtowc(pwc, s, n, ps);
}

int hls_mbsinit(mbstate_t const * ps) {
   
   return mbsinit(ps);
}

size_t hls_mbsrtowc(wchar_t * dst, char const ** src, size_t len, mbstate_t * ps) {
   
   return mbsrtowc(dst, src, len, ps);
}

size_t hls_mbstowcs(wchar_t * pwc, char const * string, size_t n) {
   
   return mbstowcs(pwc, string, n);
}

int hls_mbtowc(wchar_t * pwc, char const * string, size_t n) {
   
   return mbtowc(pwc, string, n);
}

void * hls_memchr(void const * buf, int c, size_t count) {
   
   return memchr(buf, c, count);
}

int hls_memcmp(void const * buf1, void const * buf2, size_t count) {
   
   return memcmp(buf1, buf2, count);
}

void * hls_memcpy(void * dest, void const * src, size_t count) {
   
   return memcpy(dest, src, count);
}

void * hls_memmove(void * dest, void const * src, size_t count) {
   
   return memmove(dest, src, count);
}

void * hls_memset(void * dest, int c, size_t count) {
   
   return memset(dest, c, count);
}

time_t hls_mktime(struct tm * time) {
   
   return mktime(time);
}

time_t hls_mktime64(struct tm * time) {
   
   return mktime64(time);
}

double hls_modf(double x, double * intptr) {
   
   return modf(x, intptr);
}

double hls_nextafter(double x, double y) {
   
   return nextafter(x, y);
}

long double hls_nextafterl(long double x, long double y) {
   
   return nextafterl(x, y);
}

double hls_nexttoward(double x, long double y) {
   
   return nexttoward(x, y);
}

long double hls_nexttowardl(long double x, long double y) {
   
   return nexttowardl(x, y);
}

char * hls_nl_langinfo(nl_item item) {
   
   return nl_langinfo(item);
}

void hls_perror(char const * string) {
   
   return perror(string);
}

double hls_pow(double x, double y) {
   
   return pow(x, y);
}

int hls_printf(char const * format) {
   
   return printf(format);
}

int hls_putc(int c, FILE * stream) {
   
   return putc(c, stream);
}

int hls_putchar(int c) {
   
   return putchar(c);
}

int * hls_putenv(char const * varname) {
   
   return putenv(varname);
}

int hls_puts(char const * string) {
   
   return puts(string);
}

wint_t hls_putwchar(wchar_t wc) {
   
   return putwchar(wc);
}

void hls_qsort(void * base, size_t num, size_t width, int (*) (void const *, void const *) compare) {
   
   return qsort(base, num, width, compare);
}

float hls_quantized32(float x, float y) {
   
   return quantized32(x, y);
}

float hls_quantized64(float x, float y) {
   
   return quantized64(x, y);
}

double hls_quantized128(double x, double y) {
   
   return quantized128(x, y);
}

int hls_quantexpd32(float x) {
   
   return quantexpd32(x);
}

int hls_quantexpd64(float x) {
   
   return quantexpd64(x);
}

int hls_quantexpd128(double x) {
   
   return quantexpd128(x);
}

bool hls_samequantumd32(float x, float y) {
   
   return samequantumd32(x, y);
}

bool hls_samequantumd64(float x, float y) {
   
   return samequantumd64(x, y);
}

bool hls_samequantumd128(double x, double y) {
   
   return samequantumd128(x, y);
}

int hls_raise(int sig) {
   
   return raise(sig);
}

int hls_rand() {
   
   return rand();
}

int hls_rand_r() {
   
   return rand_r();
}

void * hls_realloc(void * ptr, size_t size) {
   
   return realloc(ptr, size);
}

int hls_regcomp(regex_t * preg, char const * pattern, int cflags) {
   
   return regcomp(preg, pattern, cflags);
}

size_t hls_regerror(int errcode, regex_t const * preg, char * errbuf, size_t errbuf_size) {
   
   return regerror(errcode, preg, errbuf, errbuf_size);
}

int hls_regexec(regex_t const * preg, char const * string, size_t nmatch, regmatch_t * pmatch, int eflags) {
   
   return regexec(preg, string, nmatch, pmatch, eflags);
}

void hls_regfree(regex_t * preg) {
   
   return regfree(preg);
}

int hls_remove(char const * filename) {
   
   return remove(filename);
}

int hls_rename(char const * oldname, char const * newname) {
   
   return rename(oldname, newname);
}

void hls_rewind(FILE * stream) {
   
   return rewind(stream);
}

int hls_scanf(char const * format) {
   
   return scanf(format);
}

void hls_setbuf(FILE * stream, char * buffer) {
   
   return setbuf(stream, buffer);
}

int hls_setjmp(jmp_buf env) {
   
   return setjmp(env);
}

char * hls_setlocale(int category, char const * locale) {
   
   return setlocale(category, locale);
}

int hls_setvbuf(FILE * stream, char * buf, int type, size_t size) {
   
   return setvbuf(stream, buf, type, size);
}

void (*) (int) hls_signal(int sig, void (*) (int) func) {
   
   return signal(sig, func);
}

double hls_sin(double x) {
   
   return sin(x);
}

double hls_sinh(double x) {
   
   return sinh(x);
}

int hls_snprintf(char * outbuf, size_t n, char const * format) {
   
   return snprintf(outbuf, n, format);
}

int hls_sprintf(char * buffer, char const * format) {
   
   return sprintf(buffer, format);
}

double hls_sqrt(double x) {
   
   return sqrt(x);
}

void hls_srand(unsigned int seed) {
   
   return srand(seed);
}

int hls_sscanf(char const * buffer, char const * format) {
   
   return sscanf(buffer, format);
}

int hls_srtcasecmp(char const * string1, char const * string2) {
   
   return srtcasecmp(string1, string2);
}

char * hls_strcat(char * string1, char const * string2) {
   
   return strcat(string1, string2);
}

char * hls_strchr(char const * string, int c) {
   
   return strchr(string, c);
}

int hls_strcmp(char const * string1, char const * string2) {
   
   return strcmp(string1, string2);
}

int hls_strcoll(char const * string1, char const * string2) {
   
   return strcoll(string1, string2);
}

char * hls_strcpy(char * string1, char const * string2) {
   
   return strcpy(string1, string2);
}

size_t hls_strcspn(char const * string1, char const * string2) {
   
   return strcspn(string1, string2);
}

char * hls_strerror(int errnum) {
   
   return strerror(errnum);
}

int hls_strfmon(char * s, size_t maxsize, char const * format) {
   
   return strfmon(s, maxsize, format);
}

size_t hls_strftime(char * dest, size_t maxsize, char const * format, struct tm const * timeptr) {
   
   return strftime(dest, maxsize, format, timeptr);
}

size_t hls_strlen(char const * string) {
   
   return strlen(string);
}

int hls_strncasecmp(char const * string1, char const * string2, size_t count) {
   
   return strncasecmp(string1, string2, count);
}

char * hls_strncat(char * string1, char const * string2, size_t count) {
   
   return strncat(string1, string2, count);
}

int hls_strncmp(char const * string1, char const * string2, size_t count) {
   
   return strncmp(string1, string2, count);
}

char * hls_strncpy(char * string1, char const * string2, size_t count) {
   
   return strncpy(string1, string2, count);
}

char * hls_strpbrk(char const * string1, char const * string2) {
   
   return strpbrk(string1, string2);
}

char * hls_strptime(char const * buf, char const * format, struct tm * tm) {
   
   return strptime(buf, format, tm);
}

char * hls_strrchr(char const * string, int c) {
   
   return strrchr(string, c);
}

size_t hls_strspn(char const * string1, char const * string2) {
   
   return strspn(string1, string2);
}

char * hls_strstr(char const * string1, char const * string2) {
   
   return strstr(string1, string2);
}

double hls_strtod(char const * nptr, char ** endptr) {
   
   return strtod(nptr, endptr);
}

float hls_strtod32(char const * nptr, char ** endptr) {
   
   return strtod32(nptr, endptr);
}

float hls_strtod64(char const * nptr, char ** endptr) {
   
   return strtod64(nptr, endptr);
}

double hls_strtod128(char const * nptr, char ** endptr) {
   
   return strtod128(nptr, endptr);
}

float hls_strtof(char const * nptr, char ** endptr) {
   
   return strtof(nptr, endptr);
}

char * hls_strtok(char * string1, char const * string2) {
   
   return strtok(string1, string2);
}

char * hls_strtok_r(char * string, char const * seps, char ** lasts) {
   
   return strtok_r(string, seps, lasts);
}

long hls_strtol(char const * nptr, char ** endptr, int base) {
   
   return strtol(nptr, endptr, base);
}

long double hls_strtold(char const * nptr, char ** endptr) {
   
   return strtold(nptr, endptr);
}

unsigned long hls_strtoul(char const * string1, char ** string2, int base) {
   
   return strtoul(string1, string2, base);
}

size_t hls_strxfrm(char * string1, char const * string2, size_t count) {
   
   return strxfrm(string1, string2, count);
}

int hls_swprintf(wchar_t * wcsbuffer, size_t n, wchar_t const * format) {
   
   return swprintf(wcsbuffer, n, format);
}

int hls_swscanf(wchar_t const * buffer, wchar_t const * format) {
   
   return swscanf(buffer, format);
}

int hls_system(char const * string) {
   
   return system(string);
}

double hls_tan(double x) {
   
   return tan(x);
}

double hls_tanh(double x) {
   
   return tanh(x);
}

time_t hls_time(time_t * timeptr) {
   
   return time(timeptr);
}

time_t hls_time64(time_t * timeptr) {
   
   return time64(timeptr);
}

FILE * hls_tmpfile() {
   
   return tmpfile();
}

char * hls_tmpnam(char * string) {
   
   return tmpnam(string);
}

int hls_toascii(int c) {
   
   return toascii(c);
}

int hls_tolower(int c) {
   
   return tolower(c);
}

int hls_toupper(int c) {
   
   return toupper(c);
}

wint_t hls_towctrans(wint_t wc, wctrans_t desc) {
   
   return towctrans(wc, desc);
}

wint_t hls_towlower(wint_t wc) {
   
   return towlower(wc);
}

wint_t hls_towupper(wint_t wc) {
   
   return towupper(wc);
}

int hls_ungetc(int c, FILE * stream) {
   
   return ungetc(c, stream);
}

wint_t hls_ungetwc(wint_t wc, FILE * stream) {
   
   return ungetwc(wc, stream);
}

void hls_va_copy(va_list dest, va_list src) {
   
   return va_copy(dest, src);
}

void hls_va_end(va_list arg_ptr) {
   
   return va_end(arg_ptr);
}

void hls_va_start(va_list arg_ptr) {
   
   return va_start(arg_ptr);
}

int hls_vfprintf(FILE * stream, char const * format, va_list arg_ptr) {
   
   return vfprintf(stream, format, arg_ptr);
}

int hls_vfscanf(FILE * stream, char const * format, va_list arg_ptr) {
   
   return vfscanf(stream, format, arg_ptr);
}

int hls_vfwprintf(FILE * stream, wchar_t const * format, va_list arg) {
   
   return vfwprintf(stream, format, arg);
}

int hls_vfwscanf(FILE * stream, wchar_t const * format, va_list arg_ptr) {
   
   return vfwscanf(stream, format, arg_ptr);
}

int hls_vprintf(char const * format, va_list arg_ptr) {
   
   return vprintf(format, arg_ptr);
}

int hls_vscanf(char const * format, va_list arg_ptr) {
   
   return vscanf(format, arg_ptr);
}

int hls_vsprintf(char * target, char const * format, va_list arg_ptr) {
   
   return vsprintf(target, format, arg_ptr);
}

int hls_vsnprintf(char * outbuf, size_t n, char const * format, va_list arg_ptr) {
   
   return vsnprintf(outbuf, n, format, arg_ptr);
}

int hls_vsscanf(char const * buffer, char const * format, va_list arg_ptr) {
   
   return vsscanf(buffer, format, arg_ptr);
}

int hls_vswprintf(wchar_t * wcsbuffer, size_t n, wchar_t const * format, va_list arg) {
   
   return vswprintf(wcsbuffer, n, format, arg);
}

int hls_vswscanf(wchar_t const * buffer, wchar_t const * format, va_list arg_ptr) {
   
   return vswscanf(buffer, format, arg_ptr);
}

int hls_vwprintf(wchar_t const * format, va_list arg) {
   
   return vwprintf(format, arg);
}

int hls_vwscanf(wchar_t const * format, va_list arg_ptr) {
   
   return vwscanf(format, arg_ptr);
}

int hls_wcrtomb(char * s, wchar_t wchar, mbstate_t * pss) {
   
   return wcrtomb(s, wchar, pss);
}

wchar_t * hls_wcscat(wchar_t * string1, wchar_t const * string2) {
   
   return wcscat(string1, string2);
}

wchar_t * hls_wcschr(wchar_t const * string, wchar_t character) {
   
   return wcschr(string, character);
}

int hls_wcscmp(wchar_t const * string1, wchar_t const * string2) {
   
   return wcscmp(string1, string2);
}

int hls_wcscoll(wchar_t const * wcs1, wchar_t const * wcs2) {
   
   return wcscoll(wcs1, wcs2);
}

wchar_t * hls_wcscpy(wchar_t * string1, wchar_t const * string2) {
   
   return wcscpy(string1, string2);
}

size_t hls_wcscspn(wchar_t const * string1, wchar_t const * string2) {
   
   return wcscspn(string1, string2);
}

size_t hls_wcsftime(wchar_t * wdest, size_t maxsize, wchar_t const * format, struct tm const * timeptr) {
   
   return wcsftime(wdest, maxsize, format, timeptr);
}

size_t hls_wcslen(wchar_t const * string) {
   
   return wcslen(string);
}

struct wcslconv * hls_wcslocaleconv() {
   
   return wcslocaleconv();
}

wchar_t * hls_wcsncat(wchar_t * string1, wchar_t const * string2, size_t count) {
   
   return wcsncat(string1, string2, count);
}

int hls_wcsncmp(wchar_t const * string1, wchar_t const * string2, size_t count) {
   
   return wcsncmp(string1, string2, count);
}

wchar_t * hls_wcsncpy(wchar_t * string1, wchar_t const * string2, size_t count) {
   
   return wcsncpy(string1, string2, count);
}

wchar_t * hls_wcspbrk(wchar_t const * string1, wchar_t const * string2) {
   
   return wcspbrk(string1, string2);
}

wchar_t * hls_wcsptime(wchar_t const * buf, wchar_t const * format, struct tm * tm) {
   
   return wcsptime(buf, format, tm);
}

wchar_t * hls_wcsrchr(wchar_t const * string, wchar_t character) {
   
   return wcsrchr(string, character);
}

size_t hls_wcsrtombs(char * dst, wchar_t const ** src, size_t len, mbstate_t * ps) {
   
   return wcsrtombs(dst, src, len, ps);
}

size_t hls_wcsspn(wchar_t const * string1, wchar_t const * string2) {
   
   return wcsspn(string1, string2);
}

wchar_t * hls_wcsstr(wchar_t const * wcs1, wchar_t const * wcs2) {
   
   return wcsstr(wcs1, wcs2);
}

double hls_wcstod(wchar_t const * nptr, wchar_t ** endptr) {
   
   return wcstod(nptr, endptr);
}

float hls_wcstod32(wchar_t const * nptr, wchar_t ** endptr) {
   
   return wcstod32(nptr, endptr);
}

float hls_wcstod64(wchar_t const * nptr, wchar_t ** endptr) {
   
   return wcstod64(nptr, endptr);
}

double hls_wcstod128(wchar_t const * nptr, wchar_t ** endptr) {
   
   return wcstod128(nptr, endptr);
}

float hls_wcstof(wchar_t const * nptr, wchar_t ** endptr) {
   
   return wcstof(nptr, endptr);
}

wchar_t * hls_wcstok(wchar_t * wcs1, wchar_t const * wcs2, wchar_t ** ptr) {
   
   return wcstok(wcs1, wcs2, ptr);
}

long hls_wcstol(wchar_t const * nptr, wchar_t ** endptr, int base) {
   
   return wcstol(nptr, endptr, base);
}

long double hls_wcstold(wchar_t const * nptr, wchar_t ** endptr) {
   
   return wcstold(nptr, endptr);
}

size_t hls_wcstombs(char * dest, wchar_t const * string, size_t count) {
   
   return wcstombs(dest, string, count);
}

unsigned long hls_wcstoul(wchar_t const * nptr, wchar_t ** endptr, int base) {
   
   return wcstoul(nptr, endptr, base);
}

size_t hls_wcsxfrm(wchar_t * wcs1, wchar_t const * wcs2, size_t n) {
   
   return wcsxfrm(wcs1, wcs2, n);
}

int hls_wctob(wint_t wc) {
   
   return wctob(wc);
}

int hls_wctomb(char * string, wchar_t character) {
   
   return wctomb(string, character);
}

wctrans_t hls_wctrans(char const * property) {
   
   return wctrans(property);
}

wctype_t hls_wctype(char const * property) {
   
   return wctype(property);
}

int hls_wcswidth(wchar_t const * pwcs, size_t n) {
   
   return wcswidth(pwcs, n);
}

wchar_t * hls_wmemchr(wchar_t const * s, wchar_t c, size_t n) {
   
   return wmemchr(s, c, n);
}

int hls_wmemcmp(wchar_t const * s1, wchar_t const * s2, size_t n) {
   
   return wmemcmp(s1, s2, n);
}

wchar_t * hls_wmemcpy(wchar_t * s1, wchar_t const * s2, size_t n) {
   
   return wmemcpy(s1, s2, n);
}

wchar_t * hls_wmemmove(wchar_t * s1, wchar_t const * s2, size_t n) {
   
   return wmemmove(s1, s2, n);
}

wchar_t * hls_wmemset(wchar_t * s, wchar_t c, size_t n) {
   
   return wmemset(s, c, n);
}

int hls_wprintf(wchar_t const * format) {
   
   return wprintf(format);
}

int hls_wscanf(wchar_t const * format) {
   
   return wscanf(format);
}

double hls_y0(double x) {
   
   return y0(x);
}

double hls_y1(double x) {
   
   return y1(x);
}

double hls_yn(int n, double x) {
   
   return yn(n, x);
}
