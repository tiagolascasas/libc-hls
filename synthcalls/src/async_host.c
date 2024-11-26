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

async_call_buf *create_async_buf_fixed(SyscallName fun, unsigned int n_calls)
{
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
    return create_async_buf(buffer_size);
}

async_call_buf *create_async_buf_variadic(unsigned int n_args, unsigned int ncalls)
{
    size_t size = n_args * sizeof(int64_t);
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

bool listen_async_assert(int8_t *buffer, async_info *info)
{
    if (info->host_idx == info->kernel_idx)
    {
        return !info->is_closed;
    }
    if (info->host_idx == -1)
    {
        info->host_idx = 0;
    }
    int8_t *curr_ptr = buffer + info->host_idx;

    int32_t arg = *((int32_t *)curr_ptr);
    assert(arg);
    printf("Assertion passed\n");

    info->host_idx += sizeof(int32_t);
    return true;
}

bool listen_async_putchar(int8_t *buffer, async_info *info)
{
    if (info->host_idx == info->kernel_idx)
    {
        return !info->is_closed;
    }
    if (info->host_idx == -1)
    {
        info->host_idx = 0;
    }
    int8_t *curr_ptr = buffer + info->host_idx;

    uint32_t arg = *((uint32_t *)curr_ptr);
    putchar(arg);

    info->host_idx += sizeof(uint32_t);
    return true;
}

bool listen_async_printf(int8_t *buffer, async_info *info, const char *format)
{
    if (info->host_idx == info->kernel_idx)
    {
        return !info->is_closed;
    }
    if (info->host_idx == -1)
    {
        info->host_idx = 0;
    }
    int8_t *curr_ptr = buffer + info->host_idx;
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
            int64_t arg = *((int64_t *)(curr_ptr + host_ptr_increment));

            char next_char = format[i + 1];
            switch (next_char)
            {
            case 'd':
            case 'i':
            {
                printf("%d", arg);
                break;
            }
            case 'c':
            {
                printf("%c", (uint8_t)arg);
                break;
            }
            case 'u':
            {
                printf("%u", arg);
                break;
            }
            case 'l':
            {
                printf("%ld", arg);
                break;
            }
            case 'U':
            {
                printf("%lu", arg);
                break;
            }
            case 'f':
            {
                printf("%f", arg);
                break;
            }
            case 'p':
            {
                printf("%p", (void *)arg);
                break;
            }
            default:
            {
                printf("%d", arg);
                break;
            }
            }
            host_ptr_increment += sizeof(int64_t);
            i++;
        }
    }
    info->host_idx += host_ptr_increment;
    return true;
}