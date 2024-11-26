#include "synthcalls.h"

void call_async_assert(int8_t *buf, async_info *info, bool isLast, bool condition)
{
    if (info->kernel_idx == -1)
    {
        info->kernel_idx = 0;
    }

    *((int32_t *)(buf + info->kernel_idx)) = (int32_t)condition;
    info->kernel_idx += sizeof(int32_t);

    if (isLast)
    {
        close_async(info);
    }
}

void call_async_putchar(int8_t *buf, async_info *info, bool isLast, char c)
{
    if (info->kernel_idx == -1)
    {
        info->kernel_idx = 0;
    }

    *((uint32_t *)(buf + info->kernel_idx)) = (uint32_t)c;
    info->kernel_idx += sizeof(uint32_t);

    if (isLast)
    {
        close_async(info);
    }
}

void call_async_printf(int8_t *buf, async_info *info, bool isLast, int64_t *args, size_t n_args)
{
    if (info->kernel_idx == -1)
    {
        info->kernel_idx = 0;
    }

    for (size_t i = 0; i < n_args; i++)
    {
        int64_t arg = args[i];
        *((int64_t *)(buf + info->kernel_idx)) = arg;
        info->kernel_idx += sizeof(int64_t);
    }

    if (isLast)
    {
        close_async(info);
    }
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

inline void close_async(async_info *info)
{
    info->is_closed = true;
}