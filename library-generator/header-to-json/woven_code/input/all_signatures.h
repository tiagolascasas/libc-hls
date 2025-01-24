#ifndef _ALL_SIGNATURES_H_
#define _ALL_SIGNATURES_H_

#include <features-time64.h>
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
void hls_abort(); // Stops a program abnormally.
int hls_abs(int n);
double hls_acos(double x);
char * hls_asctime(struct tm const *time);
char * hls_asctime_r(struct tm const *tm, char *buf);
double hls_asin(double x);
void hls_assert(int expression);
double hls_atan(double x);
double hls_atan2(double y, double x);
int hls_atexit(void (*func) ());
double hls_atof(char const *string);
int hls_atoi(char const *string);
long hls_atol(char const *string);
void * hls_bsearch(void const *key, void const *base, size_t num, size_t size, int (*compare) (void const *, void const *));
wint_t hls_btowc(int c);
void * hls_calloc(size_t num, size_t size);
int hls_catclose(nl_catd catd);
char * hls_catgets(nl_catd catd, int set_id, int msg_id, char const *s);
nl_catd hls_catopen(char const *name, int oflag);
double hls_ceil(double x);
void hls_clearerr(FILE *stream);
clock_t hls_clock(); // Returns the processor time that has elapsed since the job was started.
double hls_cos(double x);
double hls_cosh(double x);
char * hls_ctime(time_t const *time);
char * hls_ctime64(time_t const *time);
char * hls_ctime_r(time_t const *time, char *buf);
char * hls_ctime64_r(time_t const *time, char *buf);
double hls_difftime(time_t time2, time_t time1);
double hls_difftime64(time_t time2, time_t time1);
div_t hls_div(int numerator, int denominator);
double hls_erf(double x);
double hls_erfc(double x);
void hls_exit(int status);
double hls_exp(double x);
double hls_fabs(double x);
int hls_fclose(FILE *stream);
FILE * hls_fdopen(int handle, char const *type);
int hls_feof(FILE *stream);
int hls_ferror(FILE *stream);
int hls_fflush(FILE *stream);
int hls_fgetc(FILE *stream);
int hls_fgetpos(FILE *stream, fpos_t *pos);
char * hls_fgets(char *string, int n, FILE *stream);
wint_t hls_fgetwc(FILE *stream);
wchar_t * hls_fgetws(wchar_t *wcs, int n, FILE *stream);
int hls_fileno(FILE *stream);
double hls_floor(double x);
double hls_fmod(double x, double y);
FILE * hls_fopen(char const *filename, char const *mode);
int hls_fprintf(FILE *stream, char const *format, ...);
int hls_fputc(int c, FILE *stream);
int hls_fputs(char const *string, FILE *stream);
wint_t hls_fputwc(wchar_t wc, FILE *stream);
int hls_fputws(wchar_t const *wcs, FILE *stream);
size_t hls_fread(void *buffer, size_t size, size_t count, FILE *stream);
void hls_free(void *ptr);
FILE * hls_freopen(char const *filename, char const *mode, FILE *stream);
double hls_frexp(double x, int *expptr);
int hls_fscanf(FILE *stream, char const *format, ...);
int hls_fseek(FILE *stream, long offset, int origin);
int hls_fsetpos(FILE *stream, fpos_t const *pos);
long hls_ftell(FILE *stream);
int hls_fwide(FILE *stream, int mode);
int hls_fwprintf(FILE *stream, wchar_t const *format, ...);
size_t hls_fwrite(void const *buffer, size_t size, size_t count, FILE *stream);
int hls_fwscanf(FILE *stream, wchar_t const *format, ...);
double hls_gamma(double x);
int hls_getc(FILE *stream);
int hls_getchar(); // Reads a single character from stdin.
char * hls_getenv(char const *varname);
char * hls_gets(char *buffer);
wint_t hls_getwc(FILE *stream);
wint_t hls_getwchar(); // Reads the next multibyte character from stdin, converts it to a wide character, and advances the associated file position indicator for stdin.
struct tm * hls_gmtime(time_t const *time);
struct tm * hls_gmtime64(time_t const *time);
struct tm * hls_gmtime_r(time_t const *time, struct tm *result);
struct tm * hls_gmtime64_r(time_t const *time, struct tm *result);
double hls_hypot(double side1, double side2);
int hls_isalnum(int c);
int hls_isalpha(int c);
int hls_isascii(int c);
int hls_isblank(int c);
int hls_iscntrl(int c);
int hls_isdigit(int c);
int hls_isgraph(int c);
int hls_islower(int c);
int hls_isprint(int c);
int hls_ispunct(int c);
int hls_isspace(int c);
int hls_isupper(int c);
int hls_iswalnum(wint_t wc);
int hls_iswalpha(wint_t wc);
int hls_iswblank(wint_t wc);
int hls_iswcntrl(wint_t wc);
int hls_iswctype(wint_t wc, wctype_t wc_prop);
int hls_iswdigit(wint_t wc);
int hls_iswgraph(wint_t wc);
int hls_iswlower(wint_t wc);
int hls_iswprint(wint_t wc);
int hls_iswpunct(wint_t wc);
int hls_iswspace(wint_t wc);
int hls_iswupper(wint_t wc);
int hls_iswxdigit(wint_t wc);
int hls_isxdigit(int c);
double hls_j0(double x);
double hls_j1(double x);
double hls_jn(int n, double x);
long hls_labs(long n);
double hls_ldexp(double x, int exp);
ldiv_t hls_ldiv(long numerator, long denominator);

struct lconv;

struct lconv * hls_localeconv(); // Formats numeric quantities in struct lconv according to the current locale.
struct tm * hls_localtime(time_t const *timeval);
struct tm * hls_localtime64(time_t const *timeval);
struct tm * hls_localtime_r(time_t const *timeval, struct tm *result);
struct tm * hls_localtime64_r(time_t const *timeval, struct tm *result);
double hls_log(double x);
double hls_log10(double x);
void hls_longjmp(jmp_buf env, int value);
void * hls_malloc(size_t size);
int hls_mblen(char const *string, size_t n);
int hls_mbrlen(char const *s, size_t n, mbstate_t *ps);
int hls_mbrtowc(wchar_t *pwc, char const *s, size_t n, mbstate_t *ps);
int hls_mbsinit(mbstate_t const *ps);
size_t hls_mbsrtowc(wchar_t *dst, char const **src, size_t len, mbstate_t *ps);
size_t hls_mbstowcs(wchar_t *pwc, char const *string, size_t n);
int hls_mbtowc(wchar_t *pwc, char const *string, size_t n);
void * hls_memchr(void const *buf, int c, size_t count);
int hls_memcmp(void const *buf1, void const *buf2, size_t count);
void * hls_memcpy(void *dest, void const *src, size_t count);
void * hls_memmove(void *dest, void const *src, size_t count);
void * hls_memset(void *dest, int c, size_t count);
time_t hls_mktime(struct tm *time);
time_t hls_mktime64(struct tm *time);
double hls_modf(double x, double *intptr);
double hls_nextafter(double x, double y);
long double hls_nextafterl(long double x, long double y);
double hls_nexttoward(double x, long double y);
long double hls_nexttowardl(long double x, long double y);
char * hls_nl_langinfo(nl_item item);
void hls_perror(char const *string);
double hls_pow(double x, double y);
int hls_printf(char const *format, ...);
int hls_putc(int c, FILE *stream);
int hls_putchar(int c);
int * hls_putenv(char const *varname);
int hls_puts(char const *string);
wint_t hls_putwchar(wchar_t wc);
void hls_qsort(void *base, size_t num, size_t width, int (*compare) (void const *, void const *));
float hls_quantized32(float x, float y);
float hls_quantized64(float x, float y);
double hls_quantized128(double x, double y);
int hls_quantexpd32(float x);
int hls_quantexpd64(float x);
int hls_quantexpd128(double x);
bool hls_samequantumd32(float x, float y);
bool hls_samequantumd64(float x, float y);
bool hls_samequantumd128(double x, double y);
int hls_raise(int sig);
int hls_rand(); // Returns a pseudo-random integer.
int hls_rand_r(); // Returns a pseudo-random integer. (Restartable version)
void * hls_realloc(void *ptr, size_t size);
int hls_regcomp(regex_t *preg, char const *pattern, int cflags);
size_t hls_regerror(int errcode, regex_t const *preg, char *errbuf, size_t errbuf_size);
int hls_regexec(regex_t const *preg, char const *string, size_t nmatch, regmatch_t *pmatch, int eflags);
void hls_regfree(regex_t *preg);
int hls_remove(char const *filename);
int hls_rename(char const *oldname, char const *newname);
void hls_rewind(FILE *stream);
int hls_scanf(char const *format, ...);
void hls_setbuf(FILE *stream, char *buffer);
int hls_setjmp(jmp_buf env);
char * hls_setlocale(int category, char const *locale);
int hls_setvbuf(FILE *stream, char *buf, int type, size_t size);
void (*) (int) hls_signal(int sig, void (*func) (int));
double hls_sin(double x);
double hls_sinh(double x);
int hls_snprintf(char *outbuf, size_t n, char const *, ...);
int hls_sprintf(char *buffer, char const *format, ...);
double hls_sqrt(double x);
void hls_srand(unsigned int seed);
int hls_sscanf(char const *buffer, char const *format, ...);
int hls_srtcasecmp(char const *string1, char const *string2);
char * hls_strcat(char *string1, char const *string2);
char * hls_strchr(char const *string, int c);
int hls_strcmp(char const *string1, char const *string2);
int hls_strcoll(char const *string1, char const *string2);
char * hls_strcpy(char *string1, char const *string2);
size_t hls_strcspn(char const *string1, char const *string2);
char * hls_strerror(int errnum);
int hls_strfmon(char *s, size_t maxsize, char const *format, ...);
size_t hls_strftime(char *dest, size_t maxsize, char const *format, struct tm const *timeptr);
size_t hls_strlen(char const *string);
int hls_strncasecmp(char const *string1, char const *string2, size_t count);
char * hls_strncat(char *string1, char const *string2, size_t count);
int hls_strncmp(char const *string1, char const *string2, size_t count);
char * hls_strncpy(char *string1, char const *string2, size_t count);
char * hls_strpbrk(char const *string1, char const *string2);
char * hls_strptime(char const *buf, char const *format, struct tm *tm);
char * hls_strrchr(char const *string, int c);
size_t hls_strspn(char const *string1, char const *string2);
char * hls_strstr(char const *string1, char const *string2);
double hls_strtod(char const *nptr, char **endptr);
float hls_strtod32(char const *nptr, char **endptr);
float hls_strtod64(char const *nptr, char **endptr);
double hls_strtod128(char const *nptr, char **endptr);
float hls_strtof(char const *nptr, char **endptr);
char * hls_strtok(char *string1, char const *string2);
char * hls_strtok_r(char *string, char const *seps, char **lasts);
long hls_strtol(char const *nptr, char **endptr, int base);
long double hls_strtold(char const *nptr, char **endptr);
unsigned long hls_strtoul(char const *string1, char **string2, int base);
size_t hls_strxfrm(char *string1, char const *string2, size_t count);
int hls_swprintf(wchar_t *wcsbuffer, size_t n, wchar_t const *format, ...);
int hls_swscanf(wchar_t const *buffer, wchar_t const *format, ...);
int hls_system(char const *string);
double hls_tan(double x);
double hls_tanh(double x);
time_t hls_time(time_t *timeptr);
time_t hls_time64(time_t *timeptr);
FILE * hls_tmpfile(); // Creates a temporary binary file and opens it.
char * hls_tmpnam(char *string);
int hls_toascii(int c);
int hls_tolower(int c);
int hls_toupper(int c);
wint_t hls_towctrans(wint_t wc, wctrans_t desc);
wint_t hls_towlower(wint_t wc);
wint_t hls_towupper(wint_t wc);
int hls_ungetc(int c, FILE *stream);
wint_t hls_ungetwc(wint_t wc, FILE *stream);
// type              hls_va_arg(va_list arg_ptr, type);                                                         // Returns the value of one argument and modifies arg_ptr to point to the next argument.
void hls_va_copy(va_list dest, va_list src);
void hls_va_end(va_list arg_ptr);
void hls_va_start(va_list arg_ptr, ...);
int hls_vfprintf(FILE *stream, char const *format, va_list arg_ptr);
int hls_vfscanf(FILE *stream, char const *format, va_list arg_ptr);
int hls_vfwprintf(FILE *stream, wchar_t const *format, va_list arg);
int hls_vfwscanf(FILE *stream, wchar_t const *format, va_list arg_ptr);
int hls_vprintf(char const *format, va_list arg_ptr);
int hls_vscanf(char const *format, va_list arg_ptr);
int hls_vsprintf(char *target, char const *format, va_list arg_ptr);
int hls_vsnprintf(char *outbuf, size_t n, char const *, va_list);
int hls_vsscanf(char const *buffer, char const *format, va_list arg_ptr);
int hls_vswprintf(wchar_t *wcsbuffer, size_t n, wchar_t const *format, va_list arg);
int hls_vswscanf(wchar_t const *buffer, wchar_t const *format, va_list arg_ptr);
int hls_vwprintf(wchar_t const *format, va_list arg);
int hls_vwscanf(wchar_t const *format, va_list arg_ptr);
int hls_wcrtomb(char *s, wchar_t wchar, mbstate_t *pss);
wchar_t * hls_wcscat(wchar_t *string1, wchar_t const *string2);
wchar_t * hls_wcschr(wchar_t const *string, wchar_t character);
int hls_wcscmp(wchar_t const *string1, wchar_t const *string2);
int hls_wcscoll(wchar_t const *wcs1, wchar_t const *wcs2);
wchar_t * hls_wcscpy(wchar_t *string1, wchar_t const *string2);
size_t hls_wcscspn(wchar_t const *string1, wchar_t const *string2);
size_t hls_wcsftime(wchar_t *wdest, size_t maxsize, wchar_t const *format, struct tm const *timeptr);
size_t hls_wcslen(wchar_t const *string);

struct wcslconv;

struct wcslconv * hls_wcslocaleconv(); // Formats numeric quantities in struct wcslconv according to the current locale.
wchar_t * hls_wcsncat(wchar_t *string1, wchar_t const *string2, size_t count);
int hls_wcsncmp(wchar_t const *string1, wchar_t const *string2, size_t count);
wchar_t * hls_wcsncpy(wchar_t *string1, wchar_t const *string2, size_t count);
wchar_t * hls_wcspbrk(wchar_t const *string1, wchar_t const *string2);
wchar_t * hls_wcsptime(wchar_t const *buf, wchar_t const *format, struct tm *tm);
wchar_t * hls_wcsrchr(wchar_t const *string, wchar_t character);
size_t hls_wcsrtombs(char *dst, wchar_t const **src, size_t len, mbstate_t *ps);
size_t hls_wcsspn(wchar_t const *string1, wchar_t const *string2);
wchar_t * hls_wcsstr(wchar_t const *wcs1, wchar_t const *wcs2);
double hls_wcstod(wchar_t const *nptr, wchar_t **endptr);
float hls_wcstod32(wchar_t const *nptr, wchar_t **endptr);
float hls_wcstod64(wchar_t const *nptr, wchar_t **endptr);
double hls_wcstod128(wchar_t const *nptr, wchar_t **endptr);
float hls_wcstof(wchar_t const *nptr, wchar_t **endptr);
wchar_t * hls_wcstok(wchar_t *wcs1, wchar_t const *wcs2, wchar_t **ptr);
long hls_wcstol(wchar_t const *nptr, wchar_t **endptr, int base);
long double hls_wcstold(wchar_t const *nptr, wchar_t **endptr);
size_t hls_wcstombs(char *dest, wchar_t const *string, size_t count);
unsigned long hls_wcstoul(wchar_t const *nptr, wchar_t **endptr, int base);
size_t hls_wcsxfrm(wchar_t *wcs1, wchar_t const *wcs2, size_t n);
int hls_wctob(wint_t wc);
//
int hls_wctomb(char *string, wchar_t character);
wctrans_t hls_wctrans(char const *property);
wctype_t hls_wctype(char const *property);
int hls_wcswidth(wchar_t const *pwcs, size_t n);
wchar_t * hls_wmemchr(wchar_t const *s, wchar_t c, size_t n);
int hls_wmemcmp(wchar_t const *s1, wchar_t const *s2, size_t n);
wchar_t * hls_wmemcpy(wchar_t *s1, wchar_t const *s2, size_t n);
wchar_t * hls_wmemmove(wchar_t *s1, wchar_t const *s2, size_t n);
wchar_t * hls_wmemset(wchar_t *s, wchar_t c, size_t n);
int hls_wprintf(wchar_t const *format, ...);
int hls_wscanf(wchar_t const *format, ...);
double hls_y0(double x);
double hls_y1(double x);
double hls_yn(int n, double x);
#endif
