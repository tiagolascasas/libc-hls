#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include "synthcalls.h"

async_call_buf *create_async_buf(unsigned int callspot, const char *arg_types, unsigned int n_calls)
{
    async_call_buf *buf = (async_call_buf *)malloc(sizeof(async_call_buf));
    init_async_buf(buf, callspot, arg_types, n_calls);
    return buf;
}

void init_async_buf(async_call_buf *buf, unsigned int callspot, const char *arg_types, unsigned int n_calls)
{
    buf->callspot = callspot;
    buf->kernel_idx = -1;
    buf->host_idx = -1;
    buf->is_closed = false;

    size_t size = 0;
    for (size_t i = 0; i < strlen(arg_types); i++)
    {
        switch (arg_types[i])
        {
        case 'i':
        case 'c':
            size += sizeof(int);
            break;
        case 'u':
            size += sizeof(unsigned int);
            break;
        case 'l':
            size += sizeof(long);
            break;
        case 'U':
            size += sizeof(unsigned long);
            break;
        case 'L':
            size += sizeof(long long);
            break;
        case 'X':
            size += sizeof(unsigned long long);
            break;
        case 'f':
        case 'd':
            size += sizeof(double);
            break;
        default:
            break;
        }
    }
    buf->size = size;
    buf->buffer = (char *)malloc(size * n_calls);
}

void async_call(async_call_buf *buf, bool isLast, const char *types, ...)
{
    if (buf->kernel_idx == -1)
    {
        buf->kernel_idx = 0;
    }
    char *curr_ptr = buf->buffer + buf->kernel_idx;
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

    buf->kernel_idx += size;

    if (isLast)
    {
        close_async_buf(buf);
    }
}

bool listen_async_nonblock(async_call_buf *buf, AsyncCall fun)
{
    if (fun != PRINTF)
    {
        return listen_async_nonblock_variadic(buf, fun, "");
    }
    else
    {
        printf("printf() needs to be explicitly called with listen_async_nonblock_variadic, even if it has no arguments");
        return false;
    }
}

bool listen_async_nonblock_variadic(async_call_buf *buf, AsyncCall fun, const char *arg_types)
{
    if (buf->host_idx == buf->kernel_idx)
    {
        return !buf->is_closed;
    }
    if (buf->host_idx == -1)
    {
        buf->host_idx = 0;
    }

    char *curr_ptr = buf->buffer + buf->host_idx;
    size_t size = 0;

    switch (fun)
    {
    case PRINTF:

        break;
    case PUTCHAR:
        int arg = *((int *)curr_ptr);
        putchar((char)arg);

        buf->host_idx += sizeof(int);
        break;
    default:
        printf("Syscall %d not implemented", fun);
    }
    buf->host_idx += size;
}

inline void close_async_buf(async_call_buf *buf)
{
    buf->is_closed = true;
}