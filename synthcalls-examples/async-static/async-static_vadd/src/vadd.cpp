#include "synthcalls.h"

void vadd(unsigned int* in1, unsigned int* in2, unsigned int* out, int size, async_call_buf* buf) {
    for (int i = 0; i < size; ++i) {
        out[i] = in1[i] + in2[i];

        if (i == 6000) {
            async_call(buf, true, "c", 'a');
        }
    }
}