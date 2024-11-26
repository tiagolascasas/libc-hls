#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <assert.h>
#include <stdint.h>
typedef struct
{
    size_t size;
    int32_t kernel_idx;
    int32_t host_idx;
    bool is_closed;
} async_info;

inline void close_async(async_info *info)
{
    info->is_closed = true;
}

void async_call(int8_t *buffer, async_info *info, bool isLast, const char *types, ...)
{
    if (info->kernel_idx == -1)
    {
        info->kernel_idx = 0;
    }

    va_list args;
    va_start(args, types);

    for (size_t i = 0; types[i] != '\0'; i++)
    {
        //int8_t *curr_ptr = buffer + info->kernel_idx;
        int8_t *curr_ptr = buffer;

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
            void *pointer = va_arg(args, void *);
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

void vadd(unsigned int *in1, unsigned int *in2, unsigned int *out, int size, int8_t *buf, async_info *info)
{
    for (int i = 0; i < size; ++i)
    {
        out[i] = in1[i] + in2[i];

        if (i == 6000)
        {
            async_call(buf, info, true, "c", 'a');
        }
    }
}