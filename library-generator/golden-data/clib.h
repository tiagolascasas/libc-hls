#include <features-time64.h>
#include <nl_types.h>
#include <regex.h>
#include <setjmp.h>
#include <signal.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>
#include <wchar.h>
#include <wctype.h>

// This may be necessary to get this to compile, adapt as needed
#define time64_t time_t
#define __bool__ bool

void          abort(void);                                                                                                                     // Stops a program abnormally.
int           abs(int n);                                                                                                                      // Calculates the absolute value of an integer argument n.
double        acos(double x);                                                                                                                  // Calculates the arc cosine of x.
char*         asctime(const struct tm* time);                                                                                                  // Converts the time that is stored as a structure to a character string.
char*         asctime_r(const struct tm* tm, char* buf);                                                                                       // Converts tm that is stored as a structure to a character string. (Restartable version of asctime.)
double        asin(double x);                                                                                                                  // Calculates the arc sine of x.
void          assert(int expression);                                                                                                          // Prints a diagnostic message and ends the program if the expression is false.
double        atan(double x);                                                                                                                  // Calculates the arc tangent of x.
double        atan2(double y, double x);                                                                                                       // Calculates the arc tangent of y/x.
int           atexit(void (*func)(void));                                                                                                      // Registers a function to be called at normal termination.
double        atof(const char* string);                                                                                                        // Converts string to a double-precision floating-point value.
int           atoi(const char* string);                                                                                                        // Converts string to an integer.
long int      atol(const char* string);                                                                                                        // Converts string to a long integer.
void*         bsearch(const void* key, const void* base, size_t num, size_t size, int (*compare)(const void* element1, const void* element2)); // Performs a binary search on an array of num elements, each of size bytes. The array must be sorted in ascending order by the function pointed to by compare.
wint_t        btowc(int c);                                                                                                                    // Determines whether c constitues a valid multibyte character in the initial shift state.
void*         calloc(size_t num, size_t size);                                                                                                 // Reserves storage space for an array of num elements, each of size size, and initializes the values of all elements to 0.
int           catclose(nl_catd catd);                                                                                                          // Closes a previously opened message catalog.
char*         catgets(nl_catd catd, int set_id, int msg_id, const char* s);                                                                    // Retrieves a message from an open message catalog.
nl_catd       catopen(const char* name, int oflag);                                                                                            // Opens a message catalog, which must be done before a message can be retrieved.
double        ceil(double x);                                                                                                                  // Calculates the double value representing the smallest integer that is greater than or equal to x.
void          clearerr(FILE* stream);                                                                                                          // Resets the error indicators and the end-of-file indicator for stream.
clock_t       clock(void);                                                                                                                     // Returns the processor time that has elapsed since the job was started.
double        cos(double x);                                                                                                                   // Calculates the cosine of x.
double        cosh(double x);                                                                                                                  // Calculates the hyperbolic cosine of x.
char*         ctime(const time_t* time);                                                                                                       // Converts time to a character string.
char*         ctime64(const time64_t* time);                                                                                                   // Converts time to a character string.
char*         ctime_r(const time_t* time, char* buf);                                                                                          // Converts time to a character string. (Restartable version of ctime.)
char*         ctime64_r(const time64_t* time, char* buf);                                                                                      // Converts time to a character string. (Restartable version of ctime64.)
double        difftime(time_t time2, time_t time1);                                                                                            // Computes the difference between time2 and time1.
double        difftime64(time64_t time2, time64_t time1);                                                                                      // Computes the difference between time2 and time1.
div_t         div(int numerator, int denominator);                                                                                             // Calculates the quotient and remainder of the division of numerator by denominator.
double        erf(double x);                                                                                                                   // Calculates the error function of x.
double        erfc(double x);                                                                                                                  // Calculates the error function for large values of x.
void          exit(int status);                                                                                                                // Ends a program normally.
double        exp(double x);                                                                                                                   // Calculates the exponential function of a floating-point argument x.
double        fabs(double x);                                                                                                                  // Calculates the absolute value of a floating-point argument x.
int           fclose(FILE* stream);                                                                                                            // Closes the specified stream.
FILE*         fdopen(int handle, const char* type);                                                                                            // Associates an input or output stream with the file identified by handle.
int           feof(FILE* stream);                                                                                                              // Tests whether the end-of-file flag is set for a given stream.
int           ferror(FILE* stream);                                                                                                            // Tests for an error indicator in reading from or writing to stream.
int           fflush(FILE* stream);                                                                                                            // Writes the contents of the buffer associated with the output stream.
int           fgetc(FILE* stream);                                                                                                             // Reads a single unsigned character from the input stream.
int           fgetpos(FILE* stream, fpos_t* pos);                                                                                              // Stores the current position of the file pointer associated with stream into the object pointed to by pos.
char*         fgets(char* string, int n, FILE* stream);                                                                                        // Reads a string from the input stream.
wint_t        fgetwc(FILE* stream);                                                                                                            // Reads the next multibyte character from the input stream pointed to by stream.
wchar_t*      fgetws(wchar_t* wcs, int n, FILE* stream);                                                                                       // Reads wide characters from the stream into the array pointed to by wcs.
int           fileno(FILE* stream);                                                                                                            // Determines the file handle currently associated with stream.
double        floor(double x);                                                                                                                 // Calculates the floating-point value representing the largest integer less than or equal to x.
double        fmod(double x, double y);                                                                                                        // Calculates the floating-point remainder of x/y.
FILE*         fopen(const char* filename, const char* mode);                                                                                   // Opens the specified file.
int           fprintf(FILE* stream, const char* format, ...);                                                                                  // Formats and prints characters and values to the output stream.
int           fputc(int c, FILE* stream);                                                                                                      // Prints a character to the output stream.
int           fputs(const char* string, FILE* stream);                                                                                         // Copies a string to the output stream.
wint_t        fputwc(wchar_t wc, FILE* stream);                                                                                                // Converts the wide character wc to a multibyte character and writes it to the output stream pointed to by stream at the current position.
int           fputws(const wchar_t* wcs, FILE* stream);                                                                                        // Converts the wide-character string wcs to a multibyte-character string and writes it to stream as a multibyte character string.
size_t        fread(void* buffer, size_t size, size_t count, FILE* stream);                                                                    // Reads up to count items of size length from the input stream, and stores them in buffer.
void          free(void* ptr);                                                                                                                 // Frees a block of storage.
FILE*         freopen(const char* filename, const char* mode, FILE* stream);                                                                   // Closes stream, and reassigns it to the file specified.
double        frexp(double x, int* expptr);                                                                                                    // Separates a floating-point number into its mantissa and exponent.
int           fscanf(FILE* stream, const char* format, ...);                                                                                   // Reads data from stream into locations given by arg-list.
int           fseek(FILE* stream, long int offset, int origin);                                                                                // Changes the current file position associated with stream to a new location.
int           fsetpos(FILE* stream, const fpos_t* pos);                                                                                        // Moves the current file position to a new location determined by pos.
long int      ftell(FILE* stream);                                                                                                             // Gets the current position of the file pointer.
int           fwide(FILE* stream, int mode);                                                                                                   // Determines the orientation of the stream pointed to by stream.
int           fwprintf(FILE* stream, const wchar_t* format, ...);                                                                              // Writes output to the stream pointed to by stream.
size_t        fwrite(const void* buffer, size_t size, size_t count, FILE* stream);                                                             // Writes up to count items of size length from buffer to stream.
int           fwscanf(FILE* stream, const wchar_t* format, ...);                                                                               // Reads input from the stream pointed to by stream.
double        gamma(double x);                                                                                                                 // Computes the Gamma Function
int           getc(FILE* stream);                                                                                                              // Reads a single character from the input stream.
int           getchar(void);                                                                                                                   // Reads a single character from stdin.
char*         getenv(const char* varname);                                                                                                     // Searches environment variables for varname.
char*         gets(char* buffer);                                                                                                              // Reads a string from stdin, and stores it in buffer.
wint_t        getwc(FILE* stream);                                                                                                             // Reads the next multibyte character from stream, converts it to a wide character and advances the associated file position indicator for stream.
wint_t        getwchar(void);                                                                                                                  // Reads the next multibyte character from stdin, converts it to a wide character, and advances the associated file position indicator for stdin.
struct tm*    gmtime(const time_t* time);                                                                                                      // Converts a time value to a structure of type tm.
struct tm*    gmtime64(const time64_t* time);                                                                                                  // Converts a time value to a structure of type tm.
struct tm*    gmtime_r(const time_t* time, struct tm* result);                                                                                 // Converts a time value to a structure of type tm. (Restartable version of gmtime.)
struct tm*    gmtime64_r(const time64_t* time, struct tm* result);                                                                             // Converts a time value to a structure of type tm. (Restartable version of gmtime64.)
double        hypot(double side1, double side2);                                                                                               // Calculates the hypotenuse of a right-angled triangle with sides of length side1 and side2.
int           isalnum(int c);                                                                                                                  // Tests if c is alphanumeric.
int           isalpha(int c);                                                                                                                  // Tests if c is alphabetic.
int           isascii(int c);                                                                                                                  // Tests if c is within the 7-bit US-ASCII range.
int           isblank(int c);                                                                                                                  // Tests if c is a blank or tab character.
int           iscntrl(int c);                                                                                                                  // Tests if c is a control character.
int           isdigit(int c);                                                                                                                  // Tests if c is a decimal digit.
int           isgraph(int c);                                                                                                                  // Tests if c is a printable character excluding the space.
int           islower(int c);                                                                                                                  // Tests if c is a lowercase letter.
int           isprint(int c);                                                                                                                  // Tests if c is a printable character including the space.
int           ispunct(int c);                                                                                                                  // Tests if c is a punctuation character.
int           isspace(int c);                                                                                                                  // Tests if c is a whitespace character.
int           isupper(int c);                                                                                                                  // Tests if c is an uppercase letter.
int           iswalnum(wint_t wc);                                                                                                             // Checks for any alphanumeric wide character.
int           iswalpha(wint_t wc);                                                                                                             // Checks for any alphabetic wide character.
int           iswblank(wint_t wc);                                                                                                             // Checks for any blank or tab wide character.
int           iswcntrl(wint_t wc);                                                                                                             // Tests for any control wide character.
int           iswctype(wint_t wc, wctype_t wc_prop);                                                                                           // Determines whether or not the wide character wc has the property wc_prop.
int           iswdigit(wint_t wc);                                                                                                             // Checks for any decimal-digit wide character.
int           iswgraph(wint_t wc);                                                                                                             // Checks for any printing wide character except for the wide-character space.
int           iswlower(wint_t wc);                                                                                                             // Checks for any lowercase wide character.
int           iswprint(wint_t wc);                                                                                                             // Checks for any printing wide character.
int           iswpunct(wint_t wc);                                                                                                             // Test for a wide non-alphanumeric, non-space character.
int           iswspace(wint_t wc);                                                                                                             // Checks for any wide character that corresponds to an implementation-defined set of wide characters for which iswalnum is false.
int           iswupper(wint_t wc);                                                                                                             // Checks for any uppercase wide character.
int           iswxdigit(wint_t wc);                                                                                                            // Checks for any hexadecimal digit character.
int           isxdigit(int c);                                                                                                                 // Tests if c is a hexadecimal digit.
double        j0(double x);                                                                                                                    // Calculates the Bessel function value of the first kind of order 0.
double        j1(double x);                                                                                                                    // Calculates the Bessel function value of the first kind of order 1.
double        jn(int n, double x);                                                                                                             // Calculates the Bessel function value of the first kind of order n.
long int      labs(long int n);                                                                                                                // Calculates the absolute value of n.
double        ldexp(double x, int exp);                                                                                                        // Returns the value of x multiplied by (2 to the power of exp).
ldiv_t        ldiv(long int numerator, long int denominator);                                                                                  // Calculates the quotient and remainder of numerator/denominator.
struct lconv* localeconv(void);                                                                                                                // Formats numeric quantities in struct lconv according to the current locale.
struct tm*    localtime(const time_t* timeval);                                                                                                // Converts timeval to a structure of type tm.
struct tm*    localtime64(const time64_t* timeval);                                                                                            // Converts timeval to a structure of type tm.
struct tm*    localtime_r(const time_t* timeval, struct tm* result);                                                                           // Converts a time value to a structure of type tm. (Restartable version of localtime.)
struct tm*    localtime64_r(const time64_t* timeval, struct tm* result);                                                                       // Converts a time value to a structure of type tm. (Restartable version of localtime64.)
double        log(double x);                                                                                                                   // Calculates the natural logarithm of x.
double        log10(double x);                                                                                                                 // Calculates the base 10 logarithm of x.
void          longjmp(jmp_buf env, int value);                                                                                                 // Restores a stack environment previously set in env by the setjmp function.
void*         malloc(size_t size);                                                                                                             // Reserves a block of storage.
int           mblen(const char* string, size_t n);                                                                                             // Determines the length of a multibyte character string.
int           mbrlen(const char* s, size_t n, mbstate_t* ps);                                                                                  // Determines the length of a multibyte character. (Restartable version of mblen.)
int           mbrtowc(wchar_t* pwc, const char* s, size_t n, mbstate_t* ps);                                                                   // Convert a multibyte character to a wide character (Restartable version of mbtowc.)
int           mbsinit(const mbstate_t* ps);                                                                                                    // Test state object *ps for initial state.
size_t        mbsrtowc(wchar_t* dst, const char** src, size_t len, mbstate_t* ps);                                                             // Convert multibyte string to a wide character string. (Restartable version of mbstowcs.)
size_t        mbstowcs(wchar_t* pwc, const char* string, size_t n);                                                                            // Converts the multibyte characters in string to their corresponding wchar_t codes, and stores not more than n codes in pwc.
int           mbtowc(wchar_t* pwc, const char* string, size_t n);                                                                              // Stores the wchar_t code corresponding to the first n bytes of multibyte character string into the wchar_t character pwc.
void*         memchr(const void* buf, int c, size_t count);                                                                                    // Searches the first count bytes of buf for the first occurrence of c converted to an unsigned character.
int           memcmp(const void* buf1, const void* buf2, size_t count);                                                                        // Compares up to count bytes of buf1 and buf2.
void*         memcpy(void* dest, const void* src, size_t count);                                                                               // Copies count bytes of src to dest.
void*         memmove(void* dest, const void* src, size_t count);                                                                              // Copies count bytes of src to dest. Allows copying between objects that overlap.
void*         memset(void* dest, int c, size_t count);                                                                                         // Sets count bytes of dest to a value c.
time_t        mktime(struct tm* time);                                                                                                         // Converts local time into calendar time.
time64_t      mktime64(struct tm* time);                                                                                                       // Converts local time into calendar time.
double        modf(double x, double* intptr);                                                                                                  // Breaks down the floating-point value x into fractional and integral parts.
double        nextafter(double x, double y);                                                                                                   // Calculates the next representable value after x in the direction of y.
long double   nextafterl(long double x, long double y);                                                                                        // Calculates the next representable value after x in the direction of y.
double        nexttoward(double x, long double y);                                                                                             // Calculates the next representable value after x in the direction of y.
long double   nexttowardl(long double x, long double y);                                                                                       // Calculates the next representable value after x in the direction of y.
char*         nl_langinfo(nl_item item);                                                                                                       // Retrieve from the current locale the string that describes the requested information specified by item.
void          perror(const char* string);                                                                                                      // Prints an error message to stderr.
double        pow(double x, double y);                                                                                                         // Calculates the value x to the power y.
int           printf(const char* format, ...);                                                                                                 // Formats and prints characters and values to stdout.
int           putc(int c, FILE* stream);                                                                                                       // Prints c to the output stream.
int           putchar(int c);                                                                                                                  // Prints c to stdout.
int*          putenv(const char* varname);                                                                                                     // Sets the value of an environment variable by altering an existing variable or creating a new one.
int           puts(const char* string);                                                                                                        // Prints a string to stdout.
wint_t        putwchar(wchar_t wc);                                                                                                            // Converts the wide character wc to a multibyte character and writes it to stdout.
void          qsort(void* base, size_t num, size_t width, int (*compare)(const void* element1, const void* element2));                         // Performs a quick sort of an array of num elements, each of width bytes in size.
#ifdef __STDC_IEC_559__
_Decimal32 quantized32(_Decimal32 x, _Decimal32 y);     // Compute the quantum exponent of a single-precision decimal floating-point value.
_Decimal64 quantized64(_Decimal64 x, _Decimal64 y);     // Compute the quantum exponent of a double-precision decimal floating-point value.
_Decimal128 quantized128(_Decimal128 x, _Decimal128 y); // Compute the quantum exponent of a quad-precision decimal floating-point value.
int      quantexpd32(_Decimal32 x);                     // Set the quantum exponent of a single-precision decimal floating-point value to the quantum exponent of another single-precision decimal floating-point value.
int      quantexpd64(_Decimal64 x);                     // Set the quantum exponent of a double-precision decimal floating-point value to the quantum exponent of another double-precision decimal floating-point value.
int      quantexpd128(_Decimal128 x);                   // Set the quantum exponent of a quad-precision decimal floating-point value to the quantum exponent of another quad-precision decimal floating-point value.
__bool__ samequantumd32(_Decimal32 x, _Decimal32 y);    // Determine if the quantum exponents of two single-precision decimal floating-point values are the same.
__bool__ samequantumd64(_Decimal64 x, _Decimal64 y);    // Determine if the quantum exponents of two double-precision decimal floating-point values are the same.
__bool__ samequantumd128(_Decimal128 x, _Decimal128 y); // Determine if the quantum exponents of two quad-precision decimal floating-point values are the same.
#endif
int    raise(int sig);                                                                                  // Sends the signal sig to the running program.
int    rand(void);                                                                                      // Returns a pseudo-random integer.
int    rand_r(void);                                                                                    // Returns a pseudo-random integer. (Restartable version)
void*  realloc(void* ptr, size_t size);                                                                 // Changes the size of a previously reserved storage block.
int    regcomp(regex_t* preg, const char* pattern, int cflags);                                         // Compiles the source regular expression pointed to by pattern into an executable version and stores it in the location pointed to by preg.
size_t regerror(int errcode, const regex_t* preg, char* errbuf, size_t errbuf_size);                    // Finds the description for the error code errcode for the regular expression preg.
int    regexec(const regex_t* preg, const char* string, size_t nmatch, regmatch_t* pmatch, int eflags); // Compares the null-ended string string against the compiled regular expression preg to find a match between the two.
void   regfree(regex_t* preg);                                                                          // Frees any memory that was allocated by regcomp to implement the regular expression preg.
int    remove(const char* filename);                                                                    // Deletes the file specified by filename.
int    rename(const char* oldname, const char* newname);                                                // Renames the specified file.
void   rewind(FILE* stream);                                                                            // Repositions the file pointer associated with stream to the beginning of the file.
int    scanf(const char* format, ...);                                                                  // Reads data from stdin into locations given by arg-list.
void   setbuf(FILE* stream, char* buffer);                                                              // Controls buffering for stream.
int    setjmp(jmp_buf env);                                                                             // Saves a stack environment that can be subsequently restored by longjmp.
char*  setlocale(int category, const char* locale);                                                     // Changes or queries variables defined in the locale.
int    setvbuf(FILE* stream, char* buf, int type, size_t size);                                         // Controls buffering and buffer size for stream.
void (*signal(int sig, void (*func)(int)))(int);                                                        // Registers func as a signal handler for the signal sig.
double sin(double x);                                                                                   // Calculates the sine of x.
double sinh(double x);                                                                                  // Calculates the hyperbolic sine of x.
int    snprintf(char* outbuf, size_t n, const char*, ...);                                              // Same as sprintf except that the function will stop after n characters have been written to outbuf.
int    sprintf(char* buffer, const char* format, ...);                                                  // Formats and stores characters and values in buffer.
double sqrt(double x);                                                                                  // Calculates the square root of x.
void   srand(unsigned int seed);                                                                        // Sets the seed for the pseudo-random number generator.
int    sscanf(const char* buffer, const char* format, ...);                                             // Reads data from buffer into the locations given by arg-list.
int    srtcasecmp(const char* string1, const char* string2);                                            // Compares strings without case sensitivity.
char*  strcat(char* string1, const char* string2);                                                      // Concatenates string2 to string1.
char*  strchr(const char* string, int c);                                                               // Locates the first occurrence of c in string.
int    strcmp(const char* string1, const char* string2);                                                // Compares the value of string1 to string2.
int    strcoll(const char* string1, const char* string2);                                               // Compares two strings using the collating sequence in the current locale.
char*  strcpy(char* string1, const char* string2);                                                      // Copies string2 into string1.
size_t strcspn(const char* string1, const char* string2);                                               // Returns the length of the initial substring of string1 consisting of characters not contained in string2.
char*  strerror(int errnum);                                                                            // Maps the error number in errnum to an error message string.
int    strfmon(char* s, size_t maxsize, const char* format, ...);                                       // Converts monetary value to string.
size_t strftime(char* dest, size_t maxsize, const char* format, const struct tm* timeptr);              // Stores characters in an array pointed to by dest, according to the string determined by format.
size_t strlen(const char* string);                                                                      // Calculates the length of string.
int    strncasecmp(const char* string1, const char* string2, size_t count);                             // Compares strings without case sensitivity.
char*  strncat(char* string1, const char* string2, size_t count);                                       // Concatenates up to count characters of string2 to string1.
int    strncmp(const char* string1, const char* string2, size_t count);                                 // Compares up to count characters of string1 and string2.
char*  strncpy(char* string1, const char* string2, size_t count);                                       // Copies up to count characters of string2 to string1.
char*  strpbrk(const char* string1, const char* string2);                                               // Locates the first occurrence in string1 of any character in string2.
char*  strptime(const char* buf, const char* format, struct tm* tm);                                    // Date and time conversion
char*  strrchr(const char* string, int c);                                                              // Locates the last occurrence of c in string.
size_t strspn(const char* string1, const char* string2);                                                // Returns the length of the initial substring of string1 consisting of characters contained in string2.
char*  strstr(const char* string1, const char* string2);                                                // Returns a pointer to the first occurrence of string2 in string1.
double strtod(const char* nptr, char** endptr);                                                         // Converts nptr to a double precision value.
#ifdef __STDC_IEC_559__
_Decimal32 strtod32(const char* nptr, char** endptr);   // Converts nptr to a single-precision decimal floating-point value.
_Decimal64 strtod64(const char* nptr, char** endptr);   // Converts nptr to a double-precision decimal floating-point value.
_Decimal128 strtod128(const char* nptr, char** endptr); // Converts nptr to a quad-precision decimal floating-point value.
#endif
float             strtof(const char* nptr, char** endptr);                                                   // Converts nptr to a float value.
char*             strtok(char* string1, const char* string2);                                                // Locates the next token in string1 delimited by the next character in string2.
char*             strtok_r(char* string, const char* seps, char** lasts);                                    // Locates the next token in string delimited by the next character in seps. (Restartable version of strtok.)
long int          strtol(const char* nptr, char** endptr, int base);                                         // Converts nptr to a signed long integer.
long double       strtold(const char* nptr, char** endptr);                                                  // Converts nptr to a long double value.
unsigned long int strtoul(const char* string1, char** string2, int base);                                    // Converts string1 to an unsigned long integer.
size_t            strxfrm(char* string1, const char* string2, size_t count);                                 // Converts string2 and places the result in string1. The conversion is determined by the program's current locale.
int               swprintf(wchar_t* wcsbuffer, size_t n, const wchar_t* format, ...);                        // Formats and stores a series of wide characters and values into the wide-character buffer wcsbuffer.
int               swscanf(const wchar_t* buffer, const wchar_t* format, ...);                                // Reads data from buffer into the locations given by arg-list.
int               system(const char* string);                                                                // Passes string to the system command analyzer.
double            tan(double x);                                                                             // Calculates the tangent of x.
double            tanh(double x);                                                                            // Calculates the hyperbolic tangent of x.
time_t            time(time_t* timeptr);                                                                     // Returns the current calendar time.
time64_t          time64(time64_t* timeptr);                                                                 // Returns the current calendar time.
FILE*             tmpfile(void);                                                                             // Creates a temporary binary file and opens it.
char*             tmpnam(char* string);                                                                      // Generates a temporary file name.
int               toascii(int c);                                                                            // Converts c to a character in the 7-bit US-ASCII character set.
int               tolower(int c);                                                                            // Converts c to lowercase.
int               toupper(int c);                                                                            // Converts c to uppercase.
wint_t            towctrans(wint_t wc, wctrans_t desc);                                                      // Translates the wide character wc based on the mapping described by desc.
wint_t            towlower(wint_t wc);                                                                       // Converts uppercase letter to lowercase letter.
wint_t            towupper(wint_t wc);                                                                       // Converts lowercase letter to uppercase letter.
int               ungetc(int c, FILE* stream);                                                               // Pushes c back onto the input stream.
wint_t            ungetwc(wint_t wc, FILE* stream);                                                          // Pushes the wide character wc back onto the input stream.
var_type          va_arg(va_list arg_ptr, var_type);                                                         // Returns the value of one argument and modifies arg_ptr to point to the next argument.
void              va_copy(va_list dest, va_list src);                                                        // Initializes dest as a copy of src.
void              va_end(va_list arg_ptr);                                                                   // Facilitates normal return from variable argument list processing.
void              va_start(va_list arg_ptr, ...);                                                            // Initializes arg_ptr for subsequent use by va_arg and va_end.
int               vfprintf(FILE* stream, const char* format, va_list arg_ptr);                               // Formats and prints characters to the output stream using a variable number of arguments.
int               vfscanf(FILE* stream, const char* format, va_list arg_ptr);                                // Reads data from a specified stream into locations given by a variable number of arguments.
int               vfwprintf(FILE* stream, const wchar_t* format, va_list arg);                               // Equivalent to fwprintf, except that the variable argument list is replaced by arg.
int               vfwscanf(FILE* stream, const wchar_t* format, va_list arg_ptr);                            // Reads wide data from a specified stream into locations given by a variable number of arguments.
int               vprintf(const char* format, va_list arg_ptr);                                              // Formats and prints characters to stdout using a variable number of arguments.
int               vscanf(const char* format, va_list arg_ptr);                                               // Reads data from stdin into locations given by a variable number of arguments.
int               vsprintf(char* target - string, const char* format, va_list arg_ptr);                      // Formats and stores characters in a buffer using a variable number of arguments.
int               vsnprintf(char* outbuf, size_t n, const char*, va_list);                                   // Same as vsprintf except that the function will stop after n characters have been written to outbuf.
int               vsscanf(const char* buffer, const char* format, va_list arg_ptr);                          // Reads data from a buffer into locations given by a variable number of arguments.
int               vswprintf(wchar_t* wcsbuffer, size_t n, const wchar_t* format, va_list arg);               // Formats and stores a series of wide characters and values in the buffer wcsbuffer.
int               vswscanf(const wchar_t* buffer, const wchar_t* format, va_list arg_ptr);                   // Reads wide data from a buffer into locations given by a variable number of arguments.
int               vwprintf(const wchar_t* format, va_list arg);                                              // Equivalent to wprintf, except that the variable argument list is replaced by arg.
int               vwscanf(const wchar_t* format, va_list arg_ptr);                                           // Reads wide data from stdin into locations given by a variable number of arguments.
int               wcrtomb(char* s, wchar_t wchar, mbstate_t* pss);                                           // Converts a wide character to a multibyte character. (Restartable version of wctomb.)
wchar_t*          wcscat(wchar_t* string1, const wchar_t* string2);                                          // Appends a copy of the string pointed to by string2 to the end of the string pointed to by string1.
wchar_t*          wcschr(const wchar_t* string, wchar_t character);                                          // Searches the wide-character string pointed to by string for the occurrence of character.
int               wcscmp(const wchar_t* string1, const wchar_t* string2);                                    // Compares two wide-character strings, *string1 and *string2.
int               wcscoll(const wchar_t* wcs1, const wchar_t* wcs2);                                         // Compares two wide-character strings using the collating sequence in the current locale.
wchar_t*          wcscpy(wchar_t* string1, const wchar_t* string2);                                          // Copies the contents of *string2 (including the ending wchar_t null character) into *string1.
size_t            wcscspn(const wchar_t* string1, const wchar_t* string2);                                   // Determines the number of wchar_t characters in the initial segment of the string pointed to by *string1 that do not appear in the string pointed to by *string2.
size_t            wcsftime(wchar_t* wdest, size_t maxsize, const wchar_t* format, const struct tm* timeptr); // Converts the time and date specification in the timeptr structure into a wide-character string.
size_t            wcslen(const wchar_t* string);                                                             // Computes the number of wide-characters in the string pointed to by string.
struct wcslconv*  wcslocaleconv(void);                                                                       // Formats numeric quantities in struct wcslconv according to the current locale.
wchar_t*          wcsncat(wchar_t* string1, const wchar_t* string2, size_t count);                           // Appends up to count wide characters from string2 to the end of string1, and appends a wchar_t null character to the result.
int               wcsncmp(const wchar_t* string1, const wchar_t* string2, size_t count);                     // Compares up to count wide characters in string1 to string2.
wchar_t*          wcsncpy(wchar_t* string1, const wchar_t* string2, size_t count);                           // Copies up to count wide characters from string2 to string1.
wchar_t*          wcspbrk(const wchar_t* string1, const wchar_t* string2);                                   // Locates the first occurrence in the string pointed to by string1 of any wide characters from the string pointed to by string2.
wchar_t*          wcsptime(const wchar_t* buf, const wchar_t* format, struct tm* tm);                        // Date and time conversion. Equivalent to strptime(), except that it uses wide characters.
wchar_t*          wcsrchr(const wchar_t* string, wchar_t character);                                         // Locates the last occurrence of character in the string pointed to by string.
size_t            wcsrtombs(char* dst, const wchar_t** src, size_t len, mbstate_t* ps);                      // Converts wide character string to multibyte string. (Restartable version of wcstombs.)
size_t            wcsspn(const wchar_t* string1, const wchar_t* string2);                                    // Computes the number of wide characters in the initial segment of the string pointed to by string1, which consists entirely of wide characters from the string pointed to by string2.
wchar_t*          wcsstr(const wchar_t* wcs1, const wchar_t* wcs2);                                          // Locates the first occurrence of wcs2 in wcs1.
double            wcstod(const wchar_t* nptr, wchar_t** endptr);                                             // Converts the initial portion of the wide-character string pointed to by nptr to a double value.
#ifdef __STDC_IEC_559__
_Decimal32 wcstod32(const wchar_t* nptr, wchar_t** endptr);   // Converts the initial portion of the wide-character string pointed to by nptr to a single-precision decimal floating-point value.
_Decimal64 wcstod64(const wchar_t* nptr, wchar_t** endptr);   // Converts the initial portion of the wide-character string pointed to by nptr to a double-precision decimal floating-point value.
_Decimal128 wcstod128(const wchar_t* nptr, wchar_t** endptr); // Converts the initial portion of the wide-character string pointed to by nptr to a quad-precision decimal floating-point value.
#endif
float             wcstof(const wchar_t* nptr, wchar_t** endptr);             // Converts the initial portion of the wide-character string pointed to by nptr to a float value.
wchar_t*          wcstok(wchar_t* wcs1, const wchar_t* wcs2, wchar_t** ptr); // Breaks wcs1 into a sequence of tokens, each of which is delimited by a wide character from the wide string pointed to by wcs2.
long int          wcstol(const wchar_t* nptr, wchar_t** endptr, int base);   // Converts the initial portion of the wide-character string pointed to by nptr to a long integer value.
long double       wcstold(const wchar_t* nptr, wchar_t** endptr);            // Converts the initial portion of the wide-character string pointed to by nptr to a long double value.
size_t            wcstombs(char* dest, const wchar_t* string, size_t count); // Converts the wchar_t string into a multibyte string dest.
unsigned long int wcstoul(const wchar_t* nptr, wchar_t** endptr, int base);  // Converts the initial portion of the wide-character string pointed to by nptr to an unsigned long integer value.
size_t            wcsxfrm(wchar_t* wcs1, const wchar_t* wcs2, size_t n);     // Transforms a wide-character string to values which represent character collating weights and places the resulting wide-character string into an array.
int               wctob(wint_t wc);                                          // Determines whether wc corresponds to a member of the extended character set whose multibyte character representation is a single byte when in the initial shift state.
                                                                             //
int       wctomb(char* string, wchar_t character);                           // Converts the wchar_t value of character into a multibyte string.
wctrans_t wctrans(const char* property);                                     // Constructs a value with type wctrans_t that describes a mapping between wide characters identified by the string argument property.
wctype_t  wctype(const char* property);                                      // Obtains handle for character property classification.
int       wcswidth(const wchar_t* pwcs, size_t n);                           // Determine the display width of a wide character string.
wchar_t*  wmemchr(const wchar_t* s, wchar_t c, size_t n);                    // Locates the first occurrence of c in the initial n wide characters of the object pointed to by s.
int       wmemcmp(const wchar_t* s1, const wchar_t* s2, size_t n);           // Compares the first n wide characters of the object pointed to by s1 to the first n characters of the object pointed to by s2.
wchar_t*  wmemcpy(wchar_t* s1, const wchar_t* s2, size_t n);                 // Copies n wide characters from the object pointed to by s2 to the object pointed to by s1.
wchar_t*  wmemmove(wchar_t* s1, const wchar_t* s2, size_t n);                // Copies n wide characters from the object pointed to by s2 to the object pointed to by s1.
wchar_t*  wmemset(wchar_t* s, wchar_t c, size_t n);                          // Copies the value of c into each of the first n wide characters of the object pointed to by s.
int       wprintf(const wchar_t* format, ...);                               // Equivalent to fwprintf with the argument stdout interposed before the arguments to wprintf.
int       wscanf(const wchar_t* format, ...);                                // Equivalent to fwscanf with the argument stdin interposed before the arguments of wscanf.
double    y0(double x);                                                      // Calculates the Bessel function value of the second kind of order 0.
double    y1(double x);                                                      // Calculates the Bessel function value of the second kind of order 1.
double    yn(int n, double x);                                               // Calculates the Bessel function value of the second kind of order n.