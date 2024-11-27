#include "synthcalls.h"

void call_async_assert(int8_t *buf, async_kernel_info *info, bool isLast, bool condition)
{
    if (info->idx == -1)
    {
        info->idx = 0;
    }

    *((int32_t *)(buf + info->idx)) = (int32_t)condition;
    info->idx += sizeof(int32_t);

    if (isLast)
    {
        close_async(info);
    }
}

void call_async_putchar(int8_t *buf, async_kernel_info *info, bool isLast, char c)
{
    if (info->idx == -1)
    {
        info->idx = 0;
    }

    *((uint32_t *)(buf + info->idx)) = (uint32_t)c;
    info->idx += sizeof(uint32_t);

    if (isLast)
    {
        close_async(info);
    }
}

void call_async_printf(int8_t *buf, async_kernel_info *info, bool isLast, int64_t *args, size_t n_args)
{
    if (info->idx == -1)
    {
        info->idx = 0;
    }

    for (size_t i = 0; i < n_args; i++)
    {
        int64_t arg = args[i];
        *((int64_t *)(buf + info->idx)) = arg;
        info->idx += sizeof(int64_t);
    }

    if (isLast)
    {
        close_async(info);
    }
}

inline void close_async(async_kernel_info *info)
{
    info->is_closed = true;
}