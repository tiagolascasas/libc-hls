#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include "synthcalls.h"

async_call_buf *create_async_buf(const char *arg_types, unsigned int n_calls)
{
    size_t size = 0;
    for (size_t i = 0; i < strlen(arg_types); i++)
    {
        switch (arg_types[i])
        {
        case 'i':
        case 'c':
            size += sizeof(int32_t);
            break;
        case 'u':
            size += sizeof(uint32_t);
            break;
        case 'l':
            size += sizeof(int64_t);
            break;
        case 'U':
            size += sizeof(uint64_t);
            break;
        case 'f':
        case 'd':
            size += sizeof(double);
            break;
        case 'p':
            size += sizeof(uint64_t);
            break;
        default:
            break;
        }
    }
    size_t buffer_size = size * n_calls;
    size_t total_size = sizeof(async_call_buf) + buffer_size;

    async_call_buf *buf = (async_call_buf *)calloc(total_size, sizeof(uint8_t));

    buf->size = total_size;
    buf->kernel_idx = -1;
    buf->host_idx = -1;
    buf->is_closed = false;
    buf->buffer = (int8_t *)(buf + 1);
    return buf;
}

void async_call(async_call_buf *buf, bool isLast, const char *types, ...)
{
    if (buf->kernel_idx == -1)
    {
        buf->kernel_idx = 0;
    }

    va_list args;
    va_start(args, types);

    for (size_t i = 0; i < strlen(types); i++)
    {
        int8_t *curr_ptr = buf->buffer + buf->kernel_idx;

        const char type_indicator = types[i];
        switch (type_indicator)
        {
        case 'i':
        case 'c':
        { // int
            int32_t i = va_arg(args, int32_t);
            *((int *)curr_ptr) = i;
            buf->kernel_idx += sizeof(int32_t);
            break;
        }
        case 'u':
        { // unsigned int
            uint32_t u = va_arg(args, uint32_t);
            *((uint32_t *)curr_ptr) = u;
            buf->kernel_idx += sizeof(uint32_t);
            break;
        }
        case 'l':
        { // long
            int64_t l = va_arg(args, int64_t);
            *((int64_t *)curr_ptr) = l;
            buf->kernel_idx += sizeof(int64_t);
            break;
        }
        case 'U':
        { // unsigned long
            uint64_t ul = va_arg(args, uint64_t);
            *((uint64_t *)curr_ptr) = ul;
            buf->kernel_idx += sizeof(uint64_t);
            break;
        }
        case 'p':
        { // pointer
            void* pointer = va_arg(args, void *);
            uint64_t pointer_as_long = (uint64_t)pointer;
            *((uint64_t *)curr_ptr) = pointer_as_long;
            buf->kernel_idx += sizeof(uint64_t);
            break;
        }
        case 'f':
        case 'd':
        { // float
            double f = va_arg(args, double);

            *((double *)curr_ptr) = f;
            buf->kernel_idx += sizeof(double);
            break;
        }
        default:
        {
            break;
        }
        }
    }
    va_end(args);

    if (isLast)
    {
        close_async_buf(buf);
    }
}

bool listen_async_putchar(async_call_buf *buf)
{
    if (buf->host_idx == buf->kernel_idx)
    {
        return !buf->is_closed;
    }
    if (buf->host_idx == -1)
    {
        buf->host_idx = 0;
    }
    int8_t *curr_ptr = buf->buffer + buf->host_idx;

    uint32_t arg = *((uint32_t *)curr_ptr);
    putchar(arg);

    buf->host_idx += sizeof(uint32_t);
    return true;
}

bool listen_async_assert(async_call_buf *buf)
{
    if (buf->host_idx == buf->kernel_idx)
    {
        return !buf->is_closed;
    }
    if (buf->host_idx == -1)
    {
        buf->host_idx = 0;
    }
    int8_t *curr_ptr = buf->buffer + buf->host_idx;

    uint32_t arg = *((uint32_t *)curr_ptr);
    assert(arg);

    buf->host_idx += sizeof(uint32_t);
    return true;
}

bool listen_async_printf(async_call_buf *buf, const char *format)
{
    if (buf->host_idx == buf->kernel_idx)
    {
        return !buf->is_closed;
    }
    if (buf->host_idx == -1)
    {
        buf->host_idx = 0;
    }
    int8_t *curr_ptr = buf->buffer + buf->host_idx;
    size_t host_ptr_increment = 0;

    for (size_t i = 0; i < strlen(format); i++)
    {
        char curr_char = format[i];
        if (curr_char != '%')
        {
            putchar(curr_char);
        }
        else if (curr_char == '%' && format[i + 1] == '\0')
        {
            putchar(curr_char);
        }
        else
        {
            char next_char = format[i + 1];
            switch (next_char)
            {
            case 'd':
            case 'i':
            {
                int32_t arg = *((int32_t *)(curr_ptr + host_ptr_increment));
                printf("%d", arg);
                host_ptr_increment += sizeof(int32_t);
                break;
            }
            case 'c':
            {
                uint32_t arg = *((uint32_t *)(curr_ptr + host_ptr_increment));
                printf("%c", (uint8_t)arg);
                host_ptr_increment += sizeof(uint32_t);
                break;
            }
            case 'u':
            {
                uint32_t arg = *((uint32_t *)(curr_ptr + host_ptr_increment));
                printf("%u", arg);
                host_ptr_increment += sizeof(unsigned int);
                break;
            }
            case 'l':
            {
                int64_t arg = *((int64_t *)(curr_ptr + host_ptr_increment));
                printf("%ld", arg);
                host_ptr_increment += sizeof(int64_t);
                break;
            }
            case 'U':
            {
                uint64_t arg = *((uint64_t *)(curr_ptr + host_ptr_increment));
                printf("%lu", arg);
                host_ptr_increment += sizeof(uint64_t);
                break;
            }
            case 'f':
            {
                double arg = *((double *)(curr_ptr + host_ptr_increment));
                printf("%f", arg);
                host_ptr_increment += sizeof(double);
                break;
            }
            case 'p':
            {
                uint64_t arg = *((uint64_t *)(curr_ptr + host_ptr_increment));
                printf("%p", (void *)arg);
                host_ptr_increment += sizeof(uint64_t);
                break;
            }
            default:
            {
                putchar(curr_char);
                break;
            }
            }
            i++;
        }
    }
    buf->host_idx += host_ptr_increment;
    return true;
}

inline void close_async_buf(async_call_buf *buf)
{
    buf->is_closed = true;
}