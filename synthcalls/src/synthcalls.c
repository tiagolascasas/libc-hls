#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include "synthcalls.h"

void init_interface(async_synthcalls_t *interface, size_t *buffer_sizes, unsigned int num_buffers)
{
    interface->buffer_count = num_buffers;
    interface->buffer_base_idx = (unsigned int *)malloc(sizeof(unsigned int) * num_buffers);
    interface->buffer_sizes = (size_t *)malloc(sizeof(size_t) * num_buffers);
    interface->buffer_idx = (unsigned int *)malloc(sizeof(unsigned int) * num_buffers);
    interface->is_closed = (bool *)malloc(sizeof(bool) * num_buffers);

    size_t totalSize = 0;
    for (int i = 0; i < num_buffers; i++)
    {
        interface->buffer_base_idx[i] = totalSize;
        interface->buffer_sizes[i] = buffer_sizes[i];
        interface->buffer_idx[i] = -1;
        interface->is_closed[i] = false;

        totalSize += buffer_sizes[i];
    }
    interface->unified_buffer = (char *)malloc(totalSize);
}

void async_call(async_synthcalls_t *interface, unsigned int callspot, bool isLast, const char *types, ...)
{
    char *buffer = interface->unified_buffer + interface->buffer_base_idx[callspot];
    unsigned int curr_idx = interface->buffer_idx[callspot];
    char *curr_ptr = buffer + curr_idx;

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
            *((int *)curr_ptr) = i;

            size_t size = sizeof(int);
            interface->buffer_idx[callspot] += size;
            break;
        }
        case 'u':
        { // unsigned int
            unsigned int u = va_arg(args, unsigned int);
            *((unsigned int *)curr_ptr) = u;

            size_t size = sizeof(unsigned int);
            interface->buffer_idx[callspot] += size;
            break;
        }
        case 'l':
        { // long
            long l = va_arg(args, long);
            *((long *)curr_ptr) = l;

            size_t size = sizeof(long);
            interface->buffer_idx[callspot] += size;
            break;
        }
        case 'U':
        { // unsigned long
            unsigned long ul = va_arg(args, unsigned long);
            *((unsigned long *)curr_ptr) = ul;

            size_t size = sizeof(unsigned long);
            interface->buffer_idx[callspot] += size;
            break;
        }
        case 'L':
        { // long long
            long long ll = va_arg(args, long long);
            *((long long *)curr_ptr) = ll;

            size_t size = sizeof(long long);
            interface->buffer_idx[callspot] += size;
            break;
        }
        case 'X':
        { // unsigned long long
            unsigned long long ull = va_arg(args, unsigned long long);
            *((unsigned long long *)curr_ptr) = ull;

            size_t size = sizeof(unsigned long long);
            interface->buffer_idx[callspot] += size;
            break;
        }
        case 'f':
        { // float
            float f = va_arg(args, float);
            *((float *)curr_ptr) = f;

            size_t size = sizeof(float);
            interface->buffer_idx[callspot] += size;
            break;
        }
        case 'd':
        { // double
            double d = va_arg(args, double);
            *((double *)curr_ptr) = d;

            size_t size = sizeof(double);
            interface->buffer_idx[callspot] += size;
            break;
        }
        case 'c':
        { // char
            char c = va_arg(args, char);
            *((char *)curr_ptr) = c;

            size_t size = sizeof(char);
            interface->buffer_idx[callspot] += size;
            break;
        }
        default:
            printf("Unknown type '%c'\n", *p);
        }
        p++;
    }

    va_end(args);

    if (isLast)
    {
        close_callspot(interface, callspot);
    }
}

void close_callspot(async_synthcalls_t *interface, unsigned int callspot)
{
    interface->is_closed[callspot] = true;
}