#include "synthcalls.h"

void vadd(unsigned int *in1, unsigned int *in2, unsigned int *out, int size, int8_t *buf, async_info *info)
{
    for (int i = 0; i < size; ++i)
    {
        out[i] = in1[i] + in2[i];

        if (i == 50)
        {
            call_async_putchar(buf, info, true, 'X');
        }
    }
}