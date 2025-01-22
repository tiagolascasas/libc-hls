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

#define time64_t time_t
#define __bool__ bool

void          hls_abort(void);                                                                                                                     // Stops a program abnormally.
int           hls_abs(int n);                                                                                                                      // Calculates the absolute value of an integer argument n.
double        hls_acos(double x);                                                                                                                  // Calculates the arc cosine of x.
char*         hls_asctime(const struct tm* time);                                                                                                  // Converts the time that is stored as a structure to a character string.
char*         hls_asctime_r(const struct tm* tm, char* buf);                                                                                       // Converts tm that is stored as a structure to a character string. (Restartable version of asctime.)
double        hls_asin(double x);                                                                                                                  // Calculates the arc sine of x.
void          hls_assert(int expression);                                                                                                          // Prints a diagnostic message and ends the program if the expression is false.
double        hls_atan(double x);                                                                                                                  // Calculates the arc tangent of x.
double        hls_atan2(double y, double x);                                                                                                       // Calculates the arc tangent of y/x.
int           hls_atexit(void (*func)(void));                                                                                                      // Registers a function to be called at normal termination.
double        hls_atof(const char* string);                                                                                                        // Converts string to a double-precision floating-point value.
int           hls_atoi(const char* string);                                                                                                        // Converts string to an integer.
long int      hls_atol(const char* string);                                                                                                        // Converts string to a long integer.
void*         hls_bsearch(const void* key, const void* base, size_t num, size_t size, int (*compare)(const void* element1, const void* element2)); // Performs a binary search on an array of num elements, each of size bytes. The array must be sorted in ascending order by the function pointed to by compare.
wint_t        hls_btowc(int c);                                                                                                                    // Determines whether c constitues a valid multibyte character in the initial shift state.
void*         hls_calloc(size_t num, size_t size);                                                                                                 // Reserves storage space for an array of num elements, each of size size, and initializes the values of all elements to 0.
int           hls_catclose(nl_catd catd);                                                                                                          // Closes a previously opened message catalog.
char*         hls_catgets(nl_catd catd, int set_id, int msg_id, const char* s);                                                                    // Retrieves a message from an open message catalog.
nl_catd       hls_catopen(const char* name, int oflag);                                                                                            // Opens a message catalog, which must be done before a message can be retrieved.
double        hls_ceil(double x);                                                                                                                  // Calculates the double value representing the smallest integer that is greater than or equal to x.
void          hls_clearerr(FILE* stream);                                                                                                          // Resets the error indicators and the end-of-file indicator for stream.
clock_t       hls_clock(void);                                                                                                                     // Returns the processor time that has elapsed since the job was started.
double        hls_cos(double x);                                                                                                                   // Calculates the cosine of x.
double        hls_cosh(double x);                                                                                                                  // Calculates the hyperbolic cosine of x.
char*         hls_ctime(const time_t* time);                                                                                                       // Converts time to a character string.
char*         hls_ctime64(const time64_t* time);                                                                                                   // Converts time to a character string.
char*         hls_ctime_r(const time_t* time, char* buf);                                                                                          // Converts time to a character string. (Restartable version of ctime.)
char*         hls_ctime64_r(const time64_t* time, char* buf);                                                                                      // Converts time to a character string. (Restartable version of ctime64.)
double        hls_difftime(time_t time2, time_t time1);                                                                                            // Computes the difference between time2 and time1.
double        hls_difftime64(time64_t time2, time64_t time1);                                                                                      // Computes the difference between time2 and time1.
div_t         hls_div(int numerator, int denominator);                                                                                             // Calculates the quotient and remainder of the division of numerator by denominator.
double        hls_erf(double x);                                                                                                                   // Calculates the error function of x.
double        hls_erfc(double x);                                                                                                                  // Calculates the error function for large values of x.
void          hls_exit(int status);                                                                                                                // Ends a program normally.
double        hls_exp(double x);                                                                                                                   // Calculates the exponential function of a floating-point argument x.
double        hls_fabs(double x);                                                                                                                  // Calculates the absolute value of a floating-point argument x.
int           hls_fclose(FILE* stream);                                                                                                            // Closes the specified stream.
FILE*         hls_fdopen(int handle, const char* type);                                                                                            // Associates an input or output stream with the file identified by handle.
int           hls_feof(FILE* stream);                                                                                                              // Tests whether the end-of-file flag is set for a given stream.
int           hls_ferror(FILE* stream);                                                                                                            // Tests for an error indicator in reading from or writing to stream.
int           hls_fflush(FILE* stream);                                                                                                            // Writes the contents of the buffer associated with the output stream.
int           hls_fgetc(FILE* stream);                                                                                                             // Reads a single unsigned character from the input stream.
int           hls_fgetpos(FILE* stream, fpos_t* pos);                                                                                              // Stores the current position of the file pointer associated with stream into the object pointed to by pos.
char*         hls_fgets(char* string, int n, FILE* stream);                                                                                        // Reads a string from the input stream.
wint_t        hls_fgetwc(FILE* stream);                                                                                                            // Reads the next multibyte character from the input stream pointed to by stream.
wchar_t*      hls_fgetws(wchar_t* wcs, int n, FILE* stream);                                                                                       // Reads wide characters from the stream into the array pointed to by wcs.
int           hls_fileno(FILE* stream);                                                                                                            // Determines the file handle currently associated with stream.
double        hls_floor(double x);                                                                                                                 // Calculates the floating-point value representing the largest integer less than or equal to x.
double        hls_fmod(double x, double y);                                                                                                        // Calculates the floating-point remainder of x/y.
FILE*         hls_fopen(const char* filename, const char* mode);                                                                                   // Opens the specified file.
int           hls_fprintf(FILE* stream, const char* format, ...);                                                                                  // Formats and prints characters and values to the output stream.
int           hls_fputc(int c, FILE* stream);                                                                                                      // Prints a character to the output stream.
int           hls_fputs(const char* string, FILE* stream);                                                                                         // Copies a string to the output stream.
wint_t        hls_fputwc(wchar_t wc, FILE* stream);                                                                                                // Converts the wide character wc to a multibyte character and writes it to the output stream pointed to by stream at the current position.
int           hls_fputws(const wchar_t* wcs, FILE* stream);                                                                                        // Converts the wide-character string wcs to a multibyte-character string and writes it to stream as a multibyte character string.
size_t        hls_fread(void* buffer, size_t size, size_t count, FILE* stream);                                                                    // Reads up to count items of size length from the input stream, and stores them in buffer.
void          hls_free(void* ptr);                                                                                                                 // Frees a block of storage.
FILE*         hls_freopen(const char* filename, const char* mode, FILE* stream);                                                                   // Closes stream, and reassigns it to the file specified.
double        hls_frexp(double x, int* expptr);                                                                                                    // Separates a floating-point number into its mantissa and exponent.
int           hls_fscanf(FILE* stream, const char* format, ...);                                                                                   // Reads data from stream into locations given by arg-list.
int           hls_fseek(FILE* stream, long int offset, int origin);                                                                                // Changes the current file position associated with stream to a new location.
int           hls_fsetpos(FILE* stream, const fpos_t* pos);                                                                                        // Moves the current file position to a new location determined by pos.
long int      hls_ftell(FILE* stream);                                                                                                             // Gets the current position of the file pointer.
int           hls_fwide(FILE* stream, int mode);                                                                                                   // Determines the orientation of the stream pointed to by stream.
int           hls_fwprintf(FILE* stream, const wchar_t* format, ...);                                                                              // Writes output to the stream pointed to by stream.
size_t        hls_fwrite(const void* buffer, size_t size, size_t count, FILE* stream);                                                             // Writes up to count items of size length from buffer to stream.
int           hls_fwscanf(FILE* stream, const wchar_t* format, ...);                                                                               // Reads input from the stream pointed to by stream.
double        hls_gamma(double x);                                                                                                                 // Computes the Gamma Function
int           hls_getc(FILE* stream);                                                                                                              // Reads a single character from the input stream.
int           hls_getchar(void);                                                                                                                   // Reads a single character from stdin.
char*         hls_getenv(const char* varname);                                                                                                     // Searches environment variables for varname.
char*         hls_gets(char* buffer);                                                                                                              // Reads a string from stdin, and stores it in buffer.
wint_t        hls_getwc(FILE* stream);                                                                                                             // Reads the next multibyte character from stream, converts it to a wide character and advances the associated file position indicator for stream.
wint_t        hls_getwchar(void);                                                                                                                  // Reads the next multibyte character from stdin, converts it to a wide character, and advances the associated file position indicator for stdin.
struct tm*    hls_gmtime(const time_t* time);                                                                                                      // Converts a time value to a structure of type tm.
struct tm*    hls_gmtime64(const time64_t* time);                                                                                                  // Converts a time value to a structure of type tm.
struct tm*    hls_gmtime_r(const time_t* time, struct tm* result);                                                                                 // Converts a time value to a structure of type tm. (Restartable version of gmtime.)
struct tm*    hls_gmtime64_r(const time64_t* time, struct tm* result);                                                                             // Converts a time value to a structure of type tm. (Restartable version of gmtime64.)
double        hls_hypot(double side1, double side2);                                                                                               // Calculates the hypotenuse of a right-angled triangle with sides of length side1 and side2.
int           hls_isalnum(int c);                                                                                                                  // Tests if c is alphanumeric.
int           hls_isalpha(int c);                                                                                                                  // Tests if c is alphabetic.
int           hls_isascii(int c);                                                                                                                  // Tests if c is within the 7-bit US-ASCII range.
int           hls_isblank(int c);                                                                                                                  // Tests if c is a blank or tab character.
int           hls_iscntrl(int c);                                                                                                                  // Tests if c is a control character.
int           hls_isdigit(int c);                                                                                                                  // Tests if c is a decimal digit.
int           hls_isgraph(int c);                                                                                                                  // Tests if c is a printable character excluding the space.
int           hls_islower(int c);                                                                                                                  // Tests if c is a lowercase letter.
int           hls_isprint(int c);                                                                                                                  // Tests if c is a printable character including the space.
int           hls_ispunct(int c);                                                                                                                  // Tests if c is a punctuation character.
int           hls_isspace(int c);                                                                                                                  // Tests if c is a whitespace character.
int           hls_isupper(int c);                                                                                                                  // Tests if c is an uppercase letter.
int           hls_iswalnum(wint_t wc);                                                                                                             // Checks for any alphanumeric wide character.
int           hls_iswalpha(wint_t wc);                                                                                                             // Checks for any alphabetic wide character.
int           hls_iswblank(wint_t wc);                                                                                                             // Checks for any blank or tab wide character.
int           hls_iswcntrl(wint_t wc);                                                                                                             // Tests for any control wide character.
int           hls_iswctype(wint_t wc, wctype_t wc_prop);                                                                                           // Determines whether or not the wide character wc has the property wc_prop.
int           hls_iswdigit(wint_t wc);                                                                                                             // Checks for any decimal-digit wide character.
int           hls_iswgraph(wint_t wc);                                                                                                             // Checks for any printing wide character except for the wide-character space.
int           hls_iswlower(wint_t wc);                                                                                                             // Checks for any lowercase wide character.
int           hls_iswprint(wint_t wc);                                                                                                             // Checks for any printing wide character.
int           hls_iswpunct(wint_t wc);                                                                                                             // Test for a wide non-alphanumeric, non-space character.
int           hls_iswspace(wint_t wc);                                                                                                             // Checks for any wide character that corresponds to an implementation-defined set of wide characters for which iswalnum is false.
int           hls_iswupper(wint_t wc);                                                                                                             // Checks for any uppercase wide character.
int           hls_iswxdigit(wint_t wc);                                                                                                            // Checks for any hexadecimal digit character.
int           hls_isxdigit(int c);                                                                                                                 // Tests if c is a hexadecimal digit.
double        hls_j0(double x);                                                                                                                    // Calculates the Bessel function value of the first kind of order 0.
double        hls_j1(double x);                                                                                                                    // Calculates the Bessel function value of the first kind of order 1.
double        hls_jn(int n, double x);                                                                                                             // Calculates the Bessel function value of the first kind of order n.
long int      hls_labs(long int n);                                                                                                                // Calculates the absolute value of n.
double        hls_ldexp(double x, int exp);                                                                                                        // Returns the value of x multiplied by (2 to the power of exp).
ldiv_t        hls_ldiv(long int numerator, long int denominator);                                                                                  // Calculates the quotient and remainder of numerator/denominator.
struct lconv* hls_localeconv(void);                                                                                                                // Formats numeric quantities in struct lconv according to the current locale.
struct tm*    hls_localtime(const time_t* timeval);                                                                                                // Converts timeval to a structure of type tm.
struct tm*    hls_localtime64(const time64_t* timeval);                                                                                            // Converts timeval to a structure of type tm.
struct tm*    hls_localtime_r(const time_t* timeval, struct tm* result);                                                                           // Converts a time value to a structure of type tm. (Restartable version of localtime.)
struct tm*    hls_localtime64_r(const time64_t* timeval, struct tm* result);                                                                       // Converts a time value to a structure of type tm. (Restartable version of localtime64.)
double        hls_log(double x);                                                                                                                   // Calculates the natural logarithm of x.
double        hls_log10(double x);                                                                                                                 // Calculates the base 10 logarithm of x.
void          hls_longjmp(jmp_buf env, int value);                                                                                                 // Restores a stack environment previously set in env by the setjmp function.
void*         hls_malloc(size_t size);                                                                                                             // Reserves a block of storage.
int           hls_mblen(const char* string, size_t n);                                                                                             // Determines the length of a multibyte character string.
int           hls_mbrlen(const char* s, size_t n, mbstate_t* ps);                                                                                  // Determines the length of a multibyte character. (Restartable version of mblen.)
int           hls_mbrtowc(wchar_t* pwc, const char* s, size_t n, mbstate_t* ps);                                                                   // Convert a multibyte character to a wide character (Restartable version of mbtowc.)
int           hls_mbsinit(const mbstate_t* ps);                                                                                                    // Test state object *ps for initial state.
size_t        hls_mbsrtowc(wchar_t* dst, const char** src, size_t len, mbstate_t* ps);                                                             // Convert multibyte string to a wide character string. (Restartable version of mbstowcs.)
size_t        hls_mbstowcs(wchar_t* pwc, const char* string, size_t n);                                                                            // Converts the multibyte characters in string to their corresponding wchar_t codes, and stores not more than n codes in pwc.
int           hls_mbtowc(wchar_t* pwc, const char* string, size_t n);                                                                              // Stores the wchar_t code corresponding to the first n bytes of multibyte character string into the wchar_t character pwc.
void*         hls_memchr(const void* buf, int c, size_t count);                                                                                    // Searches the first count bytes of buf for the first occurrence of c converted to an unsigned character.
int           hls_memcmp(const void* buf1, const void* buf2, size_t count);                                                                        // Compares up to count bytes of buf1 and buf2.
void*         hls_memcpy(void* dest, const void* src, size_t count);                                                                               // Copies count bytes of src to dest.
void*         hls_memmove(void* dest, const void* src, size_t count);                                                                              // Copies count bytes of src to dest. Allows copying between objects that overlap.
void*         hls_memset(void* dest, int c, size_t count);                                                                                         // Sets count bytes of dest to a value c.
time_t        hls_mktime(struct tm* time);                                                                                                         // Converts local time into calendar time.
time64_t      hls_mktime64(struct tm* time);                                                                                                       // Converts local time into calendar time.
double        hls_modf(double x, double* intptr);                                                                                                  // Breaks down the floating-point value x into fractional and integral parts.
double        hls_nextafter(double x, double y);                                                                                                   // Calculates the next representable value after x in the direction of y.
long double   hls_nextafterl(long double x, long double y);                                                                                        // Calculates the next representable value after x in the direction of y.
double        hls_nexttoward(double x, long double y);                                                                                             // Calculates the next representable value after x in the direction of y.
long double   hls_nexttowardl(long double x, long double y);                                                                                       // Calculates the next representable value after x in the direction of y.
char*         hls_nl_langinfo(nl_item item);                                                                                                       // Retrieve from the current locale the string that describes the requested information specified by item.
void          hls_perror(const char* string);                                                                                                      // Prints an error message to stderr.
double        hls_pow(double x, double y);                                                                                                         // Calculates the value x to the power y.
int           hls_printf(const char* format, ...);                                                                                                 // Formats and prints characters and values to stdout.
int           hls_putc(int c, FILE* stream);                                                                                                       // Prints c to the output stream.
int           hls_putchar(int c);                                                                                                                  // Prints c to stdout.
int*          hls_putenv(const char* varname);                                                                                                     // Sets the value of an environment variable by altering an existing variable or creating a new one.
int           hls_puts(const char* string);                                                                                                        // Prints a string to stdout.
wint_t        hls_putwchar(wchar_t wc);                                                                                                            // Converts the wide character wc to a multibyte character and writes it to stdout.
void          hls_qsort(void* base, size_t num, size_t width, int (*compare)(const void* element1, const void* element2));                         // Performs a quick sort of an array of num elements, each of width bytes in size.
#ifdef __STDC_IEC_559__
_Decimal32 hls_quantized32(_Decimal32 x, _Decimal32 y);     // Compute the quantum exponent of a single-precision decimal floating-point value.
_Decimal64 hls_quantized64(_Decimal64 x, _Decimal64 y);     // Compute the quantum exponent of a double-precision decimal floating-point value.
_Decimal128 hls_quantized128(_Decimal128 x, _Decimal128 y); // Compute the quantum exponent of a quad-precision decimal floating-point value.
int      hls_quantexpd32(_Decimal32 x);                     // Set the quantum exponent of a single-precision decimal floating-point value to the quantum exponent of another single-precision decimal floating-point value.
int      hls_quantexpd64(_Decimal64 x);                     // Set the quantum exponent of a double-precision decimal floating-point value to the quantum exponent of another double-precision decimal floating-point value.
int      hls_quantexpd128(_Decimal128 x);                   // Set the quantum exponent of a quad-precision decimal floating-point value to the quantum exponent of another quad-precision decimal floating-point value.
__bool__ hls_samequantumd32(_Decimal32 x, _Decimal32 y);    // Determine if the quantum exponents of two single-precision decimal floating-point values are the same.
__bool__ hls_samequantumd64(_Decimal64 x, _Decimal64 y);    // Determine if the quantum exponents of two double-precision decimal floating-point values are the same.
__bool__ hls_samequantumd128(_Decimal128 x, _Decimal128 y); // Determine if the quantum exponents of two quad-precision decimal floating-point values are the same.
#endif
int    hls_raise(int sig);                                                                                  // Sends the signal sig to the running program.
int    hls_rand(void);                                                                                      // Returns a pseudo-random integer.
int    hls_rand_r(void);                                                                                    // Returns a pseudo-random integer. (Restartable version)
void*  hls_realloc(void* ptr, size_t size);                                                                 // Changes the size of a previously reserved storage block.
int    hls_regcomp(regex_t* preg, const char* pattern, int cflags);                                         // Compiles the source regular expression pointed to by pattern into an executable version and stores it in the location pointed to by preg.
size_t hls_regerror(int errcode, const regex_t* preg, char* errbuf, size_t errbuf_size);                    // Finds the description for the error code errcode for the regular expression preg.
int    hls_regexec(const regex_t* preg, const char* string, size_t nmatch, regmatch_t* pmatch, int eflags); // Compares the null-ended string string against the compiled regular expression preg to find a match between the two.
void   hls_regfree(regex_t* preg);                                                                          // Frees any memory that was allocated by regcomp to implement the regular expression preg.
int    hls_remove(const char* filename);                                                                    // Deletes the file specified by filename.
int    hls_rename(const char* oldname, const char* newname);                                                // Renames the specified file.
void   hls_rewind(FILE* stream);                                                                            // Repositions the file pointer associated with stream to the beginning of the file.
int    hls_scanf(const char* format, ...);                                                                  // Reads data from stdin into locations given by arg-list.
void   hls_setbuf(FILE* stream, char* buffer);                                                              // Controls buffering for stream.
int    hls_setjmp(jmp_buf env);                                                                             // Saves a stack environment that can be subsequently restored by longjmp.
char*  hls_setlocale(int category, const char* locale);                                                     // Changes or queries variables defined in the locale.
int    hls_setvbuf(FILE* stream, char* buf, int type, size_t size);                                         // Controls buffering and buffer size for stream.
void (*hls_signal(int sig, void (*func)(int)))(int);                                                        // Registers func as a signal handler for the signal sig.
double hls_sin(double x);                                                                                   // Calculates the sine of x.
double hls_sinh(double x);                                                                                  // Calculates the hyperbolic sine of x.
int    hls_snprintf(char* outbuf, size_t n, const char*, ...);                                              // Same as sprintf except that the function will stop after n characters have been written to outbuf.
int    hls_sprintf(char* buffer, const char* format, ...);                                                  // Formats and stores characters and values in buffer.
double hls_sqrt(double x);                                                                                  // Calculates the square root of x.
void   hls_srand(unsigned int seed);                                                                        // Sets the seed for the pseudo-random number generator.
int    hls_sscanf(const char* buffer, const char* format, ...);                                             // Reads data from buffer into the locations given by arg-list.
int    hls_srtcasecmp(const char* string1, const char* string2);                                            // Compares strings without case sensitivity.
char*  hls_strcat(char* string1, const char* string2);                                                      // Concatenates string2 to string1.
char*  hls_strchr(const char* string, int c);                                                               // Locates the first occurrence of c in string.
int    hls_strcmp(const char* string1, const char* string2);                                                // Compares the value of string1 to string2.
int    hls_strcoll(const char* string1, const char* string2);                                               // Compares two strings using the collating sequence in the current locale.
char*  hls_strcpy(char* string1, const char* string2);                                                      // Copies string2 into string1.
size_t hls_strcspn(const char* string1, const char* string2);                                               // Returns the length of the initial substring of string1 consisting of characters not contained in string2.
char*  hls_strerror(int errnum);                                                                            // Maps the error number in errnum to an error message string.
int    hls_strfmon(char* s, size_t maxsize, const char* format, ...);                                       // Converts monetary value to string.
size_t hls_strftime(char* dest, size_t maxsize, const char* format, const struct tm* timeptr);              // Stores characters in an array pointed to by dest, according to the string determined by format.
size_t hls_strlen(const char* string);                                                                      // Calculates the length of string.
int    hls_strncasecmp(const char* string1, const char* string2, size_t count);                             // Compares strings without case sensitivity.
char*  hls_strncat(char* string1, const char* string2, size_t count);                                       // Concatenates up to count characters of string2 to string1.
int    hls_strncmp(const char* string1, const char* string2, size_t count);                                 // Compares up to count characters of string1 and string2.
char*  hls_strncpy(char* string1, const char* string2, size_t count);                                       // Copies up to count characters of string2 to string1.
char*  hls_strpbrk(const char* string1, const char* string2);                                               // Locates the first occurrence in string1 of any character in string2.
char*  hls_strptime(const char* buf, const char* format, struct tm* tm);                                    // Date and time conversion
char*  hls_strrchr(const char* string, int c);                                                              // Locates the last occurrence of c in string.
size_t hls_strspn(const char* string1, const char* string2);                                                // Returns the length of the initial substring of string1 consisting of characters contained in string2.
char*  hls_strstr(const char* string1, const char* string2);                                                // Returns a pointer to the first occurrence of string2 in string1.
double hls_strtod(const char* nptr, char** endptr);                                                         // Converts nptr to a double precision value.
#ifdef __STDC_IEC_559__
_Decimal32 hls_strtod32(const char* nptr, char** endptr);   // Converts nptr to a single-precision decimal floating-point value.
_Decimal64 hls_strtod64(const char* nptr, char** endptr);   // Converts nptr to a double-precision decimal floating-point value.
_Decimal128 hls_strtod128(const char* nptr, char** endptr); // Converts nptr to a quad-precision decimal floating-point value.
#endif
float             hls_strtof(const char* nptr, char** endptr);                            // Converts nptr to a float value.
char*             hls_strtok(char* string1, const char* string2);                         // Locates the next token in string1 delimited by the next character in string2.
char*             hls_strtok_r(char* string, const char* seps, char** lasts);             // Locates the next token in string delimited by the next character in seps. (Restartable version of strtok.)
long int          hls_strtol(const char* nptr, char** endptr, int base);                  // Converts nptr to a signed long integer.
long double       hls_strtold(const char* nptr, char** endptr);                           // Converts nptr to a long double value.
unsigned long int hls_strtoul(const char* string1, char** string2, int base);             // Converts string1 to an unsigned long integer.
size_t            hls_strxfrm(char* string1, const char* string2, size_t count);          // Converts string2 and places the result in string1. The conversion is determined by the program's current locale.
int               hls_swprintf(wchar_t* wcsbuffer, size_t n, const wchar_t* format, ...); // Formats and stores a series of wide characters and values into the wide-character buffer wcsbuffer.
int               hls_swscanf(const wchar_t* buffer, const wchar_t* format, ...);         // Reads data from buffer into the locations given by arg-list.
int               hls_system(const char* string);                                         // Passes string to the system command analyzer.
double            hls_tan(double x);                                                      // Calculates the tangent of x.
double            hls_tanh(double x);                                                     // Calculates the hyperbolic tangent of x.
time_t            hls_time(time_t* timeptr);                                              // Returns the current calendar time.
time64_t          hls_time64(time64_t* timeptr);                                          // Returns the current calendar time.
FILE*             hls_tmpfile(void);                                                      // Creates a temporary binary file and opens it.
char*             hls_tmpnam(char* string);                                               // Generates a temporary file name.
int               hls_toascii(int c);                                                     // Converts c to a character in the 7-bit US-ASCII character set.
int               hls_tolower(int c);                                                     // Converts c to lowercase.
int               hls_toupper(int c);                                                     // Converts c to uppercase.
wint_t            hls_towctrans(wint_t wc, wctrans_t desc);                               // Translates the wide character wc based on the mapping described by desc.
wint_t            hls_towlower(wint_t wc);                                                // Converts uppercase letter to lowercase letter.
wint_t            hls_towupper(wint_t wc);                                                // Converts lowercase letter to uppercase letter.
int               hls_ungetc(int c, FILE* stream);                                        // Pushes c back onto the input stream.
wint_t            hls_ungetwc(wint_t wc, FILE* stream);                                   // Pushes the wide character wc back onto the input stream.
// type              hls_va_arg(va_list arg_ptr, type);                                                         // Returns the value of one argument and modifies arg_ptr to point to the next argument.
void             hls_va_copy(va_list dest, va_list src);                                                        // Initializes dest as a copy of src.
void             hls_va_end(va_list arg_ptr);                                                                   // Facilitates normal return from variable argument list processing.
void             hls_va_start(va_list arg_ptr, ...);                                                            // Initializes arg_ptr for subsequent use by va_arg and va_end.
int              hls_vfprintf(FILE* stream, const char* format, va_list arg_ptr);                               // Formats and prints characters to the output stream using a variable number of arguments.
int              hls_vfscanf(FILE* stream, const char* format, va_list arg_ptr);                                // Reads data from a specified stream into locations given by a variable number of arguments.
int              hls_vfwprintf(FILE* stream, const wchar_t* format, va_list arg);                               // Equivalent to fwprintf, except that the variable argument list is replaced by arg.
int              hls_vfwscanf(FILE* stream, const wchar_t* format, va_list arg_ptr);                            // Reads wide data from a specified stream into locations given by a variable number of arguments.
int              hls_vprintf(const char* format, va_list arg_ptr);                                              // Formats and prints characters to stdout using a variable number of arguments.
int              hls_vscanf(const char* format, va_list arg_ptr);                                               // Reads data from stdin into locations given by a variable number of arguments.
int              hls_vsprintf(char* target, const char* format, va_list arg_ptr);                               // Formats and stores characters in a buffer using a variable number of arguments.
int              hls_vsnprintf(char* outbuf, size_t n, const char*, va_list);                                   // Same as vsprintf except that the function will stop after n characters have been written to outbuf.
int              hls_vsscanf(const char* buffer, const char* format, va_list arg_ptr);                          // Reads data from a buffer into locations given by a variable number of arguments.
int              hls_vswprintf(wchar_t* wcsbuffer, size_t n, const wchar_t* format, va_list arg);               // Formats and stores a series of wide characters and values in the buffer wcsbuffer.
int              hls_vswscanf(const wchar_t* buffer, const wchar_t* format, va_list arg_ptr);                   // Reads wide data from a buffer into locations given by a variable number of arguments.
int              hls_vwprintf(const wchar_t* format, va_list arg);                                              // Equivalent to wprintf, except that the variable argument list is replaced by arg.
int              hls_vwscanf(const wchar_t* format, va_list arg_ptr);                                           // Reads wide data from stdin into locations given by a variable number of arguments.
int              hls_wcrtomb(char* s, wchar_t wchar, mbstate_t* pss);                                           // Converts a wide character to a multibyte character. (Restartable version of wctomb.)
wchar_t*         hls_wcscat(wchar_t* string1, const wchar_t* string2);                                          // Appends a copy of the string pointed to by string2 to the end of the string pointed to by string1.
wchar_t*         hls_wcschr(const wchar_t* string, wchar_t character);                                          // Searches the wide-character string pointed to by string for the occurrence of character.
int              hls_wcscmp(const wchar_t* string1, const wchar_t* string2);                                    // Compares two wide-character strings, *string1 and *string2.
int              hls_wcscoll(const wchar_t* wcs1, const wchar_t* wcs2);                                         // Compares two wide-character strings using the collating sequence in the current locale.
wchar_t*         hls_wcscpy(wchar_t* string1, const wchar_t* string2);                                          // Copies the contents of *string2 (including the ending wchar_t null character) into *string1.
size_t           hls_wcscspn(const wchar_t* string1, const wchar_t* string2);                                   // Determines the number of wchar_t characters in the initial segment of the string pointed to by *string1 that do not appear in the string pointed to by *string2.
size_t           hls_wcsftime(wchar_t* wdest, size_t maxsize, const wchar_t* format, const struct tm* timeptr); // Converts the time and date specification in the timeptr structure into a wide-character string.
size_t           hls_wcslen(const wchar_t* string);                                                             // Computes the number of wide-characters in the string pointed to by string.
struct wcslconv* hls_wcslocaleconv(void);                                                                       // Formats numeric quantities in struct wcslconv according to the current locale.
wchar_t*         hls_wcsncat(wchar_t* string1, const wchar_t* string2, size_t count);                           // Appends up to count wide characters from string2 to the end of string1, and appends a wchar_t null character to the result.
int              hls_wcsncmp(const wchar_t* string1, const wchar_t* string2, size_t count);                     // Compares up to count wide characters in string1 to string2.
wchar_t*         hls_wcsncpy(wchar_t* string1, const wchar_t* string2, size_t count);                           // Copies up to count wide characters from string2 to string1.
wchar_t*         hls_wcspbrk(const wchar_t* string1, const wchar_t* string2);                                   // Locates the first occurrence in the string pointed to by string1 of any wide characters from the string pointed to by string2.
wchar_t*         hls_wcsptime(const wchar_t* buf, const wchar_t* format, struct tm* tm);                        // Date and time conversion. Equivalent to strptime(), except that it uses wide characters.
wchar_t*         hls_wcsrchr(const wchar_t* string, wchar_t character);                                         // Locates the last occurrence of character in the string pointed to by string.
size_t           hls_wcsrtombs(char* dst, const wchar_t** src, size_t len, mbstate_t* ps);                      // Converts wide character string to multibyte string. (Restartable version of wcstombs.)
size_t           hls_wcsspn(const wchar_t* string1, const wchar_t* string2);                                    // Computes the number of wide characters in the initial segment of the string pointed to by string1, which consists entirely of wide characters from the string pointed to by string2.
wchar_t*         hls_wcsstr(const wchar_t* wcs1, const wchar_t* wcs2);                                          // Locates the first occurrence of wcs2 in wcs1.
double           hls_wcstod(const wchar_t* nptr, wchar_t** endptr);                                             // Converts the initial portion of the wide-character string pointed to by nptr to a double value.
#ifdef __STDC_IEC_559__
_Decimal32 hls_wcstod32(const wchar_t* nptr, wchar_t** endptr);   // Converts the initial portion of the wide-character string pointed to by nptr to a single-precision decimal floating-point value.
_Decimal64 hls_wcstod64(const wchar_t* nptr, wchar_t** endptr);   // Converts the initial portion of the wide-character string pointed to by nptr to a double-precision decimal floating-point value.
_Decimal128 hls_wcstod128(const wchar_t* nptr, wchar_t** endptr); // Converts the initial portion of the wide-character string pointed to by nptr to a quad-precision decimal floating-point value.
#endif
float             hls_wcstof(const wchar_t* nptr, wchar_t** endptr);             // Converts the initial portion of the wide-character string pointed to by nptr to a float value.
wchar_t*          hls_wcstok(wchar_t* wcs1, const wchar_t* wcs2, wchar_t** ptr); // Breaks wcs1 into a sequence of tokens, each of which is delimited by a wide character from the wide string pointed to by wcs2.
long int          hls_wcstol(const wchar_t* nptr, wchar_t** endptr, int base);   // Converts the initial portion of the wide-character string pointed to by nptr to a long integer value.
long double       hls_wcstold(const wchar_t* nptr, wchar_t** endptr);            // Converts the initial portion of the wide-character string pointed to by nptr to a long double value.
size_t            hls_wcstombs(char* dest, const wchar_t* string, size_t count); // Converts the wchar_t string into a multibyte string dest.
unsigned long int hls_wcstoul(const wchar_t* nptr, wchar_t** endptr, int base);  // Converts the initial portion of the wide-character string pointed to by nptr to an unsigned long integer value.
size_t            hls_wcsxfrm(wchar_t* wcs1, const wchar_t* wcs2, size_t n);     // Transforms a wide-character string to values which represent character collating weights and places the resulting wide-character string into an array.
int               hls_wctob(wint_t wc);                                          // Determines whether wc corresponds to a member of the extended character set whose multibyte character representation is a single byte when in the initial shift state.
                                                                                 //
int       hls_wctomb(char* string, wchar_t character);                           // Converts the wchar_t value of character into a multibyte string.
wctrans_t hls_wctrans(const char* property);                                     // Constructs a value with type wctrans_t that describes a mapping between wide characters identified by the string argument property.
wctype_t  hls_wctype(const char* property);                                      // Obtains handle for character property classification.
int       hls_wcswidth(const wchar_t* pwcs, size_t n);                           // Determine the display width of a wide character string.
wchar_t*  hls_wmemchr(const wchar_t* s, wchar_t c, size_t n);                    // Locates the first occurrence of c in the initial n wide characters of the object pointed to by s.
int       hls_wmemcmp(const wchar_t* s1, const wchar_t* s2, size_t n);           // Compares the first n wide characters of the object pointed to by s1 to the first n characters of the object pointed to by s2.
wchar_t*  hls_wmemcpy(wchar_t* s1, const wchar_t* s2, size_t n);                 // Copies n wide characters from the object pointed to by s2 to the object pointed to by s1.
wchar_t*  hls_wmemmove(wchar_t* s1, const wchar_t* s2, size_t n);                // Copies n wide characters from the object pointed to by s2 to the object pointed to by s1.
wchar_t*  hls_wmemset(wchar_t* s, wchar_t c, size_t n);                          // Copies the value of c into each of the first n wide characters of the object pointed to by s.
int       hls_wprintf(const wchar_t* format, ...);                               // Equivalent to fwprintf with the argument stdout interposed before the arguments to wprintf.
int       hls_wscanf(const wchar_t* format, ...);                                // Equivalent to fwscanf with the argument stdin interposed before the arguments of wscanf.
double    hls_y0(double x);                                                      // Calculates the Bessel function value of the second kind of order 0.
double    hls_y1(double x);                                                      // Calculates the Bessel function value of the second kind of order 1.
double    hls_yn(int n, double x);                                               // Calculates the Bessel function value of the second kind of order n.