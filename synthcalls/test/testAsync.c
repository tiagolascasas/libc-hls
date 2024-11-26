#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <pthread.h>
#include "synthcalls.h"

#define BIG_N 1000000000

void *kernel_A(async_call_buf *putchar_0, async_call_buf *putchar_1, async_call_buf *putchar_2, async_call_buf *assert_0)
{
    call_async_putchar(putchar_0->buffer, putchar_0->info, true, 'H');
    unsigned long long *sum = (unsigned long long *)malloc(sizeof(unsigned long long));
    *sum = 0;

    call_async_assert(assert_0->buffer, assert_0->info, true, 1 == 1);
    for (int i = 0; i < BIG_N; i++)
    {
        *sum += i;
    }
    call_async_putchar(putchar_1->buffer, putchar_1->info, true, 'i');
    for (int i = 0; i < BIG_N; i++)
    {
        *sum *= i;
    }
    call_async_putchar(putchar_2->buffer, putchar_2->info, true, '!');
    return (void *)(sum);
}

void wrapped_kernel_A()
{
    async_call_buf *putchar_0 = create_async_buf_fixed(PUTCHAR, 1);
    async_call_buf *putchar_1 = create_async_buf_fixed(PUTCHAR, 1);
    async_call_buf *putchar_2 = create_async_buf_fixed(PUTCHAR, 1);
    async_call_buf *assert_0 = create_async_buf_fixed(ASSERT, 1);

    kernel_A(putchar_0, putchar_1, putchar_2, assert_0);

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

void *kernel_B(async_call_buf *printf_0)
{
    unsigned long long *sum = (unsigned long long *)malloc(sizeof(unsigned long long));
    *sum = 0;

    for (int i = 0; i < 10; i++)
    {
        uint64_t args[1] = {i};
        call_async_printf(printf_0->buffer, printf_0->info, false, args, 1);

        for (int i = 0; i < BIG_N / 100; i++)
        {
            *sum += i;
        }
    }
    close_async(printf_0->info);
    return (void *)sum;
}

void wrapped_kernel_B()
{
    async_call_buf *printf_0 = create_async_buf_variadic(1, 10);

    kernel_B(printf_0);

    bool active = true;
    while (active)
    {
        active = false;
        active = active || listen_async_printf(printf_0, "index = %d\n");
    }
}

void *kernel_C(async_call_buf *printf_0, async_call_buf *printf_1)
{
    unsigned long long *sum = (unsigned long long *)malloc(sizeof(unsigned long long));
    *sum = 0;

    for (int i = 0; i < 10; i++)
    {
        uint64_t printf_0_args[2] = {i, *sum};
        call_async_printf(printf_0->buffer, printf_0->info, false, printf_0_args, 2);

        for (int i = 0; i < BIG_N / 100; i++)
        {
            *sum += i;
        }
    }
    close_async(printf_0->info);

    int64_t printf_1_args[4] = {10, 20, 30, 40};
    call_async_printf(printf_1->buffer, printf_1->info, true, printf_1_args, 4);
    return (void *)sum;
}

void wrapped_kernel_C()
{
    async_call_buf *printf_0 = create_async_buf_variadic(2, 10);
    async_call_buf *printf_1 = create_async_buf_variadic(2, 1);

    kernel_C(printf_0, printf_1);

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