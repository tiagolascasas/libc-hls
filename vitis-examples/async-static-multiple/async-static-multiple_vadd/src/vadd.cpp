#include "synthcalls.h"

void vadd(unsigned int* in1, unsigned int* in2, unsigned int* out, int size, int8_t* buf_printf, async_kernel_info* info_printf)
{
    for (int i = 0; i < size; ++i)
    {
        out[i] = in1[i] + in2[i];

        if (i % 50 == 0)
        {
            int64_t arg[1] = {i};
            call_async_printf(buf_printf, info_printf, false, arg, 1);
        }
    }
    close_async(info_printf);
}