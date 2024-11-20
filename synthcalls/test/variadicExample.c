#include <stdio.h>
#include <stdarg.h>

void print_args(const char *types, ...)
{
    va_list args;
    va_start(args, types);

    const char *p = types;
    while (*p)
    {
        switch (*p)
        {
        case 'i':
        { // int
            int i = va_arg(args, int);
            printf("int: %d, size: %zu\n", i, sizeof(i));
            break;
        }
        case 'u':
        { // unsigned int
            unsigned int u = va_arg(args, unsigned int);
            printf("unsigned int: %u, size: %zu\n", u, sizeof(u));
            break;
        }
        case 'l':
        { // long
            long l = va_arg(args, long);
            printf("long: %ld, size: %zu\n", l, sizeof(l));
            break;
        }
        case 'U':
        { // unsigned long
            unsigned long ul = va_arg(args, unsigned long);
            printf("unsigned long: %lu, size: %zu\n", ul, sizeof(ul));
            break;
        }
        case 'L':
        { // long long
            long long ll = va_arg(args, long long);
            printf("long long: %lld, size: %zu\n", ll, sizeof(ll));
            break;
        }
        case 'X':
        { // unsigned long long
            unsigned long long ull = va_arg(args, unsigned long long);
            printf("unsigned long long: %llu, size: %zu\n", ull, sizeof(ull));
            break;
        }
        case 'f':
        { // float (promoted to double)
            double f = va_arg(args, double);
            printf("float/double: %f, size: %zu\n", f, sizeof(double));
            break;
        }
        case 'd':
        { // double
            double d = va_arg(args, double);
            printf("double: %f, size: %zu\n", d, sizeof(d));
            break;
        }
        case 'c':
        {                              // char
            int c = va_arg(args, int); // char is promoted to int
            printf("char: %c, size: %zu\n", c, sizeof(char));
            break;
        }
        default:
            printf("Unknown type '%c'\n", *p);
        }
        p++;
    }

    va_end(args);
}

int main()
{
    print_args("iulULXfdc", 42, 420u, 420L, 420UL, 420LL, 420ULL, 3.14f, 2.718, 'A');
    return 0;
}
