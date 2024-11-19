#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <pthread.h>
#include "synthcalls.h"

#define BIG_N 100000000

int simple_putchar(void *interface)
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

void wrapped_simple_putchar()
{
    // create interface
    size_t buffer_sizes[4] = {1, 1, 1};
    synthcall_interface interface;
    init_interface(&interface, buffer_sizes, sizeof(buffer_sizes) / sizeof(size_t));

    // simulate kernel execution using a thread
    pthread_t thread;
    pthread_create(&thread, NULL, simple_putchar, (void *)&interface);

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
            char *buffer_0_addr = interface.unified_buffer + interface.buffer_base_idx[0] + interface.back_idx[0];
            putchar(*buffer_0_addr);
            buffer_0_front_idx++;
        }
        bool is_closed_0 = interface.is_closed[0] && buffer_0_front_idx == interface.back_idx[0];
        active = active || !is_closed_0;

        if (buffer_1_front_idx < interface.back_idx[1])
        {
            char *buffer_1_addr = interface.unified_buffer + interface.buffer_base_idx[1] + interface.back_idx[1];
            putchar(*buffer_1_addr);
            buffer_1_front_idx++;
        }
        bool is_closed_1 = interface.is_closed[1] && buffer_1_front_idx == interface.back_idx[1];
        active = active || !is_closed_1;

        if (buffer_2_front_idx < interface.back_idx[2])
        {
            char *buffer_2_addr = interface.unified_buffer + interface.buffer_base_idx[2] + interface.back_idx[2];
            putchar(*buffer_2_addr);
            buffer_2_front_idx++;
        }
        bool is_closed_2 = interface.is_closed[2] && buffer_2_front_idx == interface.back_idx[2];
        active = active || !is_closed_2;
    } while (active);

    pthread_join(thread, NULL);
}

int loop_printf(void *interface)
{
    unsigned long long sum = 0;
    for (int i = 0; i < 10; i++)
    {
        async_call((synthcall_interface *)interface, 0, i, false);

        for (int i = 0; i < BIG_N; i++)
        {
            sum += i;
        }
    }
    close_callspot((synthcall_interface *)interface, 0);
    return sum;
}

void wrapped_loop_printf()
{
    size_t buffer_sizes[1] = {11};
    synthcall_interface interface;
    init_interface(&interface, buffer_sizes, sizeof(buffer_sizes) / sizeof(size_t));

    loop_printf(&interface);

    bool active;
    int buffer_0_front_idx = -1;
    do
    {
        active = false;

        if (buffer_0_front_idx < interface.back_idx[0])
        {
            char *buffer_0_addr = interface.unified_buffer + interface.buffer_base_idx[0] + interface.back_idx[0];
            printf("%d, ", *buffer_0_addr);
            buffer_0_front_idx++;
        }
        bool is_closed_0 = interface.is_closed[0] && buffer_0_front_idx == interface.back_idx[0];
        active = active || !is_closed_0;

    } while (active);
}

int main()
{
    printf("Test: simple putchar\n");
    wrapped_simple_putchar();

    printf("\nTest: loop printf\n");
    wrapped_loop_printf();

    return 0;
}