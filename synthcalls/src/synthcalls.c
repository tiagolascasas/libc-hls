#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include "synthcalls.h"

void synthcalls_init_interface(async_interface_t *interface, size_t *buffer_sizes, unsigned int num_buffers)
{
    interface->buffer_count = num_buffers;
    interface->buffer_base_idx = (unsigned int *)malloc(sizeof(unsigned int) * num_buffers);
    interface->buffer_sizes = (size_t *)malloc(sizeof(size_t) * num_buffers);
    interface->buffer_idx = (int *)malloc(sizeof(int) * num_buffers);
    interface->is_closed = (bool *)malloc(sizeof(bool) * num_buffers);

    size_t totalSize = 0;
    for (unsigned int i = 0; i < num_buffers; i++)
    {
        interface->buffer_base_idx[i] = totalSize;
        interface->buffer_sizes[i] = buffer_sizes[i];
        interface->buffer_idx[i] = -1;
        interface->is_closed[i] = false;

        totalSize += buffer_sizes[i];
    }
    interface->unified_buffer = (char *)malloc(totalSize);
}

void synthcalls_async_call(async_interface_t *interface, unsigned int callspot, bool isLast, const char *types, ...)
{
    if (interface->buffer_idx[callspot] == -1)
    {
        interface->buffer_idx[callspot] = 0;
    }

    char *buffer = interface->unified_buffer + interface->buffer_base_idx[callspot];
    int curr_idx = interface->buffer_idx[callspot];
    char *curr_ptr = buffer + curr_idx;
    size_t size = 0;

    va_list args;
    va_start(args, types);

    const char *p = types;
    while (*p)
    {
        switch (*p)
        {
        case 'i':
        case 'c':
        { // int
            int i = va_arg(args, int);
            *((int *)curr_ptr) = i;
            size = sizeof(int);
            break;
        }
        case 'u':
        { // unsigned int
            unsigned int u = va_arg(args, unsigned int);
            *((unsigned int *)curr_ptr) = u;
            size = sizeof(unsigned int);
            break;
        }
        case 'l':
        { // long
            long l = va_arg(args, long);
            *((long *)curr_ptr) = l;
            size = sizeof(long);
            break;
        }
        case 'U':
        { // unsigned long
            unsigned long ul = va_arg(args, unsigned long);
            *((unsigned long *)curr_ptr) = ul;
            size = sizeof(unsigned long);
            break;
        }
        case 'L':
        { // long long
            long long ll = va_arg(args, long long);
            *((long long *)curr_ptr) = ll;
            size = sizeof(long long);
            break;
        }
        case 'X':
        { // unsigned long long
            unsigned long long ull = va_arg(args, unsigned long long);
            *((unsigned long long *)curr_ptr) = ull;
            size = sizeof(unsigned long long);
            break;
        }
        case 'f':
        case 'd':
        { // float
            double f = va_arg(args, double);
            *((double *)curr_ptr) = f;
            size = sizeof(double);
            break;
        }
        default:
            break;
        }
        p++;
    }
    va_end(args);

    interface->buffer_idx[callspot] += size;

    if (isLast)
    {
        synthcalls_close_callspot(interface, callspot);
    }
}

void synthcalls_close_callspot(async_interface_t *interface, unsigned int callspot)
{
    interface->is_closed[callspot] = true;
}