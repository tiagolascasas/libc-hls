#include "synthcalls.h"

void vadd(unsigned int* in1, unsigned int* in2, unsigned int* out, int size, int8_t* buf_putchar, async_kernel_info* info_putchar, int8_t* buf_assert, async_kernel_info* info_assert, int8_t* buf_printf, async_kernel_info* info_printf, int c1, int c2, int c3)
{
    for (int i = 0; i < size; i++)
    {
        out[i] = in1[i] + in2[i];

        if (i == c1)
        {
            call_async_putchar(buf_putchar, info_putchar, true, 'X');
        }

        if (i == c2)
        {
            call_async_assert(buf_assert, info_assert, true, i == c2);
        }
        if (i == c3)
        {
            int64_t args[1] = {i};
            call_async_printf(buf_printf, info_printf, true, args, 1);
        }
    }
}