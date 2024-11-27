#include "synthcalls.h"

void vadd(unsigned int *in1, unsigned int *in2, unsigned int *out, int size,
          int8_t *buf_putchar, async_kernel_info *info_putchar,
          int8_t *buf_assert, async_kernel_info *info_assert,
          int8_t *buf_printf, async_kernel_info *info_printf)
{
    for (int i = 0; i < size; ++i)
    {
        out[i] = in1[i] + in2[i];

        if (i == 50)
        {
            call_async_putchar(buf_putchar, info_putchar, true, 'X');
        }

        if (i == 100)
        {
            call_async_assert(buf_assert, info_assert, true, i == 100);
        }
        if (i == 150)
        {
            int64_t args[1] = {i};
            call_async_printf(buf_printf, info_printf, true, args, 1);
        }
    }
}