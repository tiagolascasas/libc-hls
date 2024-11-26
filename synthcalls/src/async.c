#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include "synthcalls.h"

static async_call_buf *create_async_buf(size_t buffer_size);

async_call_buf *create_async_buf_fixed(SyscallName fun, unsigned int n_calls) {
    size_t size = 0;
    switch (fun)
    {
    case ASSERT:
        size = sizeof(uint32_t);
        break;
    case PUTCHAR:
        size = sizeof(uint32_t);
        break;
    case PRINTF:    
        size = sizeof(uint32_t);
        break;
    default:
        break;
    }
    size_t buffer_size = size * n_calls;
    return create_async_buf(buffer_size)
}

async_call_buf *create_async_buf_variadic(const char* arg_types, unsigned int ncalls) {
    size_t size = 0;

    for (size_t i = 0; i < strlen(arg_types); i++)
    {
        const char type_indicator = arg_types[i];
        switch (type_indicator)
        {
        case 'i':
        case 'c':
        { // int
            size += sizeof(int32_t);
            break;
        }
        case 'u':
        { // unsigned int
            size += sizeof(uint32_t);
            break;
        }
        case 'l':
        { // long
            size += sizeof(int64_t);
            break;
        }
        case 'U':
        { // unsigned long
            size += sizeof(uint64_t);
            break;
        }
        case 'p':
        { // pointer
            size += sizeof(uint64_t);
            break;
        }
        case 'f':
        case 'd':
        { // float
            size += sizeof(double);
            break;
        }
        default:
        {
            break;
        }
        }
    }
    size_t buffer_size = size * ncalls;
    return create_async_buf(buffer_size);
}

static async_call_buf *create_async_buf(size_t buffer_size)
{
    int8_t *buffer = (int8_t *)calloc(1, buffer_size);

    async_info *info = (async_info *)calloc(1, sizeof(async_info));
    info->size = buffer_size;
    info->kernel_idx = -1;
    info->host_idx = -1;
    info->is_closed = false;

    async_call_buf *buf = (async_call_buf *)calloc(1, sizeof(async_call_buf));
    buf->info = info;
    buf->buffer = buffer;

    return buf;
}

void async_call(int8_t *buffer, async_info *info, bool isLast, const char *types, ...)
{
    if (info->kernel_idx == -1)
    {
        info->kernel_idx = 0;
    }

    va_list args;
    va_start(args, types);

    for (size_t i = 0; i < strlen(types); i++)
    {
        int8_t *curr_ptr = buffer + info->kernel_idx;

        const char type_indicator = types[i];
        switch (type_indicator)
        {
        case 'i':
        case 'c':
        { // int
            int32_t i = va_arg(args, int32_t);
            *((int *)curr_ptr) = i;
            info->kernel_idx += sizeof(int32_t);
            break;
        }
        case 'u':
        { // unsigned int
            uint32_t u = va_arg(args, uint32_t);
            *((uint32_t *)curr_ptr) = u;
            info->kernel_idx += sizeof(uint32_t);
            break;
        }
        case 'l':
        { // long
            int64_t l = va_arg(args, int64_t);
            *((int64_t *)curr_ptr) = l;
            info->kernel_idx += sizeof(int64_t);
            break;
        }
        case 'U':
        { // unsigned long
            uint64_t ul = va_arg(args, uint64_t);
            *((uint64_t *)curr_ptr) = ul;
            info->kernel_idx += sizeof(uint64_t);
            break;
        }
        case 'p':
        { // pointer
            void* pointer = va_arg(args, void *);
            uint64_t pointer_as_long = (uint64_t)pointer;
            *((uint64_t *)curr_ptr) = pointer_as_long;
            info->kernel_idx += sizeof(uint64_t);
            break;
        }
        case 'f':
        case 'd':
        { // float
            double f = va_arg(args, double);

            *((double *)curr_ptr) = f;
            info->kernel_idx += sizeof(double);
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
        close_async(info);
    }
}

bool listen_async_putchar(async_call_buf *buf)
{
    if (buf->info->host_idx == buf->info->kernel_idx)
    {
        return !buf->info->is_closed;
    }
    if (buf->info->host_idx == -1)
    {
        buf->info->host_idx = 0;
    }
    int8_t *curr_ptr = buf->buffer + buf->info->host_idx;

    uint32_t arg = *((uint32_t *)curr_ptr);
    putchar(arg);

    buf->info->host_idx += sizeof(uint32_t);
    return true;
}

bool listen_async_assert(async_call_buf *buf)
{
    if (buf->info->host_idx == buf->info->kernel_idx)
    {
        return !buf->info->is_closed;
    }
    if (buf->info->host_idx == -1)
    {
        buf->info->host_idx = 0;
    }
    int8_t *curr_ptr = buf->buffer + buf->info->host_idx;

    uint32_t arg = *((uint32_t *)curr_ptr);
    assert(arg);

    buf->info->host_idx += sizeof(uint32_t);
    return true;
}

bool listen_async_printf(async_call_buf *buf, const char *format)
{
    if (buf->info->host_idx == buf->info->kernel_idx)
    {
        return !buf->info->is_closed;
    }
    if (buf->info->host_idx == -1)
    {
        buf->info->host_idx = 0;
    }
    int8_t *curr_ptr = buf->buffer + buf->info->host_idx;
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
    buf->info->host_idx += host_ptr_increment;
    return true;
}

inline void close_async(async_info *info)
{
    info->is_closed = true;
}