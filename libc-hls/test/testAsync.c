#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <pthread.h>
#include "synthcalls.h"

#define BIG_N 1000000000

void *kernel_A(int8_t *putchar_0_buf, async_kernel_info *putchar_0_info,
               int8_t *putchar_1_buf, async_kernel_info *putchar_1_info,
               int8_t *putchar_2_buf, async_kernel_info *putchar_2_info,
               int8_t *assert_0_buf, async_kernel_info *assert_0_info)
{
    call_async_putchar(putchar_0_buf, putchar_0_info, true, 'H');
    unsigned long long *sum = (unsigned long long *)malloc(sizeof(unsigned long long));
    *sum = 0;

    call_async_assert(assert_0_buf, assert_0_info, true, 1 == 1);
    for (int i = 0; i < BIG_N; i++)
    {
        *sum += i;
    }
    call_async_putchar(putchar_1_buf, putchar_1_info, true, 'i');
    for (int i = 0; i < BIG_N; i++)
    {
        *sum *= i;
    }
    call_async_putchar(putchar_2_buf, putchar_2_info, true, '!');
    return (void *)(sum);
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

void *kernel_B(int8_t *printf_0_buffer, async_kernel_info *printf_0_info)
{
    unsigned long long *sum = (unsigned long long *)malloc(sizeof(unsigned long long));
    *sum = 0;

    for (int i = 0; i < 10; i++)
    {
        int64_t args[1] = {i};
        call_async_printf(printf_0_buffer, printf_0_info, false, args, 1);

        for (int i = 0; i < BIG_N / 100; i++)
        {
            *sum += i;
        }
    }
    close_async(printf_0_info);
    return (void *)sum;
}

void wrapped_kernel_B()
{
    async_call *printf_0 = create_async_call_variadic(PRINTF, 1, 10);

    kernel_B(printf_0->buffer, printf_0->kernel_info);

    bool active = true;
    while (active)
    {
        active = false;
        active = active || listen_async_printf(printf_0, "index = %d\n");
    }
}

void *kernel_C(int8_t *printf_0_buffer, async_kernel_info *printf_0_info,
                int8_t *printf_1_buffer, async_kernel_info *printf_1_info)
{
    unsigned long long *sum = (unsigned long long *)malloc(sizeof(unsigned long long));
    *sum = 0;

    for (int i = 0; i < 10; i++)
    {
        int64_t printf_0_args[2] = {i, *sum};
        call_async_printf(printf_0_buffer, printf_0_info, false, printf_0_args, 2);

        for (int i = 0; i < BIG_N / 100; i++)
        {
            *sum += i;
        }
    }
    close_async(printf_0_info);

    int64_t printf_1_args[4] = {10, 20, 30, 40};
    call_async_printf(printf_1_buffer, printf_1_info, true, printf_1_args, 4);
    return (void *)sum;
}

void wrapped_kernel_C()
{
    async_call *printf_0 = create_async_call_variadic(PRINTF, 2, 10);
    async_call *printf_1 = create_async_call_variadic(PRINTF, 2, 1);

    kernel_C(printf_0->buffer, printf_0->kernel_info, printf_1->buffer, printf_1->kernel_info);

    bool active = true;
    while (active)
    {
        active = false;
        active = active || listen_async_printf(printf_0, "index = %d, sum = %lu\n");
        active = active || listen_async_printf(printf_1, "numbers: %d, %d, %d, %d\n");
    }
}

int main()
{
    printf("--------------------------------------------------\n");
    printf("Test: three static putchar() callspots\n");
    wrapped_kernel_A();

    printf("\n--------------------------------------------------\n");
    printf("Test: one printf() callspot, called 10 times (static number of repetitions)\n");
    wrapped_kernel_B();

    printf("--------------------------------------------------\n");
    printf("Test: variadic printf()\n");
    wrapped_kernel_C();

    return 0;
}