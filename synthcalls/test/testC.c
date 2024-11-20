#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <pthread.h>
#include "synthcalls.h"

#define BIG_N 100000000

int variadic_printf(void *interface)
{
    async_call((synthcall_interface *)interface, 0, 'H', true);
    unsigned long long sum = 0;
    for (int i = 0; i < BIG_N; i++)
    {
        sum += i;
    }
    async_call((synthcall_interface *)interface, 1, 'W', true);
    for (int i = 0; i < BIG_N; i++)
    {
        sum *= i;
    }
    async_call((synthcall_interface *)interface, 2, '\n', true);
    return sum;
}

void wrapped_variadic_printf()
{
    // create interface
    size_t buffer_sizes[4] = {1, 1, 1};
    synthcall_interface interface;
    init_interface(&interface, buffer_sizes, sizeof(buffer_sizes) / sizeof(size_t));

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

        if (buffer_0_front_idx < interface.back_idx[0])
        {
            buffer_0_front_idx++;
            char *buffer_0_addr = interface.unified_buffer + interface.buffer_base_idx[0] + buffer_0_front_idx;
            putchar(*buffer_0_addr);
        }
        bool is_closed_0 = interface.is_closed[0] && buffer_0_front_idx == interface.back_idx[0];
        active = active || !is_closed_0;

        if (buffer_1_front_idx < interface.back_idx[1])
        {
            buffer_1_front_idx++;
            char *buffer_1_addr = interface.unified_buffer + interface.buffer_base_idx[1] + buffer_0_front_idx;
            putchar(*buffer_1_addr);
        }
        bool is_closed_1 = interface.is_closed[1] && buffer_1_front_idx == interface.back_idx[1];
        active = active || !is_closed_1;

        if (buffer_2_front_idx < interface.back_idx[2])
        {
            buffer_2_front_idx++;
            char *buffer_2_addr = interface.unified_buffer + interface.buffer_base_idx[2] + buffer_0_front_idx;
            putchar(*buffer_2_addr);
        }
        bool is_closed_2 = interface.is_closed[2] && buffer_2_front_idx == interface.back_idx[2];
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