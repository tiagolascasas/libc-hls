#include "synthcalls.h"

void vadd(unsigned int *in1, unsigned int *in2, unsigned int *out, int size, int8_t *buf_putchar, async_info *info_putchar, int8_t *buf_assert, async_info *info_assert)
{
    for (int i = 0; i < size; ++i)
    {
        out[i] = in1[i] + in2[i];

        if (i == 50)
        {
            call_async_putchar(buf_putchar, info_putchar, true, 'X');
        }

        if (i == 100) {
            call_async_assert(buf_assert, info_assert, true, i == 100);
        }
    }
}