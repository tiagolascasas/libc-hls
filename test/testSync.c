#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <pthread.h>
#include "synthcalls.h"

#define N 128

void distance(double *v1_x, double *v1_y, double *v2_x, double *v2_y, double *distances, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        double dx = v1_x[i] - v2_x[i];
        double dy = v1_y[i] - v2_y[i];
        double d = dx * dx + dy * dy;
        if (i % 32 == 0) {
            // d = sync_sqrt()
        }
        else {
            d = sqrt(d);
        }
        distances[i] = d;
    }

}

void wrapped_kernel_A()
{
    async_call *putchar_0 = create_async_call_fixed(PUTCHAR, 1);
    async_call *putchar_1 = create_async_call_fixed(PUTCHAR, 1);
    async_call *putchar_2 = create_async_call_fixed(PUTCHAR, 1);
    async_call *assert_0 = create_async_call_fixed(ASSERT, 1);

    kernel_A(putchar_0->buffer, putchar_0->kernel_info,
             putchar_1->buffer, putchar_1->kernel_info,
             putchar_2->buffer, putchar_2->kernel_info,
             assert_0->buffer, assert_0->kernel_info);

    bool active = true;
    while (active)
    {
        active = false;
        active = active || listen_async_putchar(putchar_0);
        active = active || listen_async_putchar(putchar_1);
        active = active || listen_async_putchar(putchar_2);
        active = active || listen_async_assert(assert_0);
    }
}

int main()
{
    printf("--------------------------------------------------\n");
    printf("Test: a single sqrt() callspot\n");
    wrapped_kernel_A();

    return 0;
}