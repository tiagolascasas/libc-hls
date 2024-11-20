#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <pthread.h>
#include "synthcalls.h"

#define BIG_N 100000000

void *original_variadic_printf()
{
    unsigned long long *sum = (unsigned long long *)malloc(sizeof(unsigned long long));
    *sum = 0;

    printf("Message with one arg: %d\n", 42);
    for (int i = 0; i < BIG_N; i++)
    {
        *sum += i;
    }
    printf("Message with three args: %d, %d, %d\n", 10, 20, 30);
    for (int i = 0; i < BIG_N; i++)
    {
        *sum *= i;
    }
    printf("Here is a really long number: %llu\n", ULLONG_MAX);
    printf("Here is a float: %f\n", 3.14);
    return (void *)sum;
}

void *variadic_printf(void *interface)
{
    synthcalls_async_call((async_interface_t *)interface, 0, 42, true);
    unsigned long long *sum = (unsigned long long *)malloc(sizeof(unsigned long long));
    *sum = 0;

    for (int i = 0; i < BIG_N; i++)
    {
        *sum += i;
    }
    synthcalls_async_call((async_interface_t *)interface, 1, 10, true);
    for (int i = 0; i < BIG_N; i++)
    {
        *sum *= i;
    }
    synthcalls_async_call((async_interface_t *)interface, 2, '\n', true);
    synthcalls_async_call((async_interface_t *)interface, 3, 20, false);
    return (void *)sum;
}

void wrapped_variadic_printf()
{
    // create interface
    size_t buffer_sizes[] = {
        sizeof(int),
        sizeof(int) * 3,
        sizeof(unsigned long long)};
    async_interface_t interface;
    synthcalls_init_interface(&interface, buffer_sizes, sizeof(buffer_sizes) / sizeof(size_t));

    // simulate kernel execution using a thread
    pthread_t thread;
    pthread_create(&thread, NULL, variadic_printf, (void *)&interface);

    // apply all the synthcalls
    bool active;
    int buffer_0_front_idx = -1;
    int buffer_1_front_idx = -1;
    int buffer_2_front_idx = -1;
    do
    {
        active = false;

        if (buffer_0_front_idx < interface.buffer_idx[0])
        {
            buffer_0_front_idx++;
            char *buffer_0_addr = interface.unified_buffer + interface.buffer_base_idx[0] + buffer_0_front_idx;
            putchar(*buffer_0_addr);
        }
        bool is_closed_0 = interface.is_closed[0] && buffer_0_front_idx == interface.buffer_idx[0];
        active = active || !is_closed_0;

        if (buffer_1_front_idx < interface.buffer_idx[1])
        {
            buffer_1_front_idx++;
            char *buffer_1_addr = interface.unified_buffer + interface.buffer_base_idx[1] + buffer_0_front_idx;
            putchar(*buffer_1_addr);
        }
        bool is_closed_1 = interface.is_closed[1] && buffer_1_front_idx == interface.buffer_idx[1];
        active = active || !is_closed_1;

        if (buffer_2_front_idx < interface.buffer_idx[2])
        {
            buffer_2_front_idx++;
            char *buffer_2_addr = interface.unified_buffer + interface.buffer_base_idx[2] + buffer_0_front_idx;
            putchar(*buffer_2_addr);
        }
        bool is_closed_2 = interface.is_closed[2] && buffer_2_front_idx == interface.buffer_idx[2];
        active = active || !is_closed_2;
    } while (active);

    pthread_join(thread, NULL);
}

int main()
{
    printf("Test: variadic_printf\n");
    wrapped_variadic_printf();

    return 0;
}