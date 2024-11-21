#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <pthread.h>
#include "synthcalls.h"

#define BIG_N 1000000000

void *kernel_A(async_call_buf *putchar_0, async_call_buf *putchar_1, async_call_buf *putchar_2, async_call_buf *assert_0)
{
    async_call(putchar_0, true, "c", 'H');
    unsigned long long *sum = (unsigned long long *)malloc(sizeof(unsigned long long));
    *sum = 0;

    async_call(assert_0, true, "i", *sum == 0);
    for (int i = 0; i < BIG_N; i++)
    {
        *sum += i;
    }
    async_call(putchar_1, true, "c", 'i');
    for (int i = 0; i < BIG_N; i++)
    {
        *sum *= i;
    }
    async_call(putchar_2, true, "c", '!');
    return (void *)(sum);
}

void wrapped_kernel_A()
{
    async_call_buf *putchar_0 = create_async_buf("c", 1);
    async_call_buf *putchar_1 = create_async_buf("c", 1);
    async_call_buf *putchar_2 = create_async_buf("c", 1);
    async_call_buf *assert_0 = create_async_buf("i", 1);

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
        async_call(printf_0, false, "i", i);

        for (int i = 0; i < BIG_N / 100; i++)
        {
            *sum += i;
        }
    }
    close_async_buf((async_call_buf *)printf_0);
    return (void *)sum;
}

void wrapped_kernel_B()
{
    async_call_buf *printf_0 = create_async_buf("i", 10);

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
        async_call(printf_0, false, "il", i, *sum);

        for (int i = 0; i < BIG_N / 100; i++)
        {
            *sum += i;
        }
    }
    close_async_buf(printf_0);
    async_call(printf_1, true, "fffc", 123.456, -999.555, 1615.55, 2);
    return (void *)sum;
}

void wrapped_kernel_C()
{
    async_call_buf *printf_0 = create_async_buf("il", 10);
    async_call_buf *printf_1 = create_async_buf("fffc", 1);

    kernel_C(printf_0, printf_1);

    printf("%d\n", printf_0->size);
    for (int i = 0; i < printf_0->size; i++)
    {
        printf("printf_0 %d\n", printf_0->buffer[i]);
    }

    bool active = true;
    while (active)
    {
        active = false;
        active = active || listen_async_printf(printf_0, "index = %d, sum = %lu\n");
        active = active || listen_async_printf(printf_1, "floats: %f, %f, %f, int: %d\n");
    }
}

int main()
{
    printf("--------------------------------------------------\n");
    printf("Test: three static putchar() callspots\n");
    // wrapped_kernel_A();

    printf("\n--------------------------------------------------\n");
    printf("Test: one printf() callspot, called 10 times (static number of repetitions)\n");
    // wrapped_kernel_B();

    printf("--------------------------------------------------\n");
    printf("Test: variadic printf()\n");
    wrapped_kernel_C();

    return 0;
}