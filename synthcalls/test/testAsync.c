#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <pthread.h>
#include "synthcalls.h"

#define BIG_N 1000000000

void *simple_putchar(void *interface)
{
    synthcalls_async_call((async_interface_t *)interface, 0, true, "i", 'H');
    unsigned long long *sum = (unsigned long long *)malloc(sizeof(unsigned long long));
    *sum = 0;

    for (int i = 0; i < BIG_N; i++)
    {
        *sum += i;
    }
    synthcalls_async_call((async_interface_t *)interface, 1, true, "i", 'i');
    for (int i = 0; i < BIG_N; i++)
    {
        *sum *= i;
    }
    synthcalls_async_call((async_interface_t *)interface, 2, true, "i", '!');
    return (void *)(sum);
}

void wrapped_simple_putchar()
{
    // create interface
    size_t buffer_sizes[3] = {sizeof(int), sizeof(int), sizeof(int)};
    async_interface_t interface;
    synthcalls_init_interface(&interface, buffer_sizes, 3);

    // simulate kernel execution using a thread
    pthread_t thread;
    pthread_create(&thread, NULL, simple_putchar, (void *)&interface);

    pthread_join(thread, NULL);

    // apply all the synthcalls
    bool active;
    int buffer_0_host_idx = -1;
    int buffer_1_host_idx = -1;
    int buffer_2_host_idx = -1;
    do
    {
        active = false;

        if (buffer_0_host_idx < interface.buffer_idx[0])
        {
            buffer_0_host_idx = (buffer_0_host_idx == -1) ? 0 : buffer_0_host_idx;

            char *buffer_0_base_addr = interface.unified_buffer + interface.buffer_base_idx[0];
            char *buffer_0_ptr = buffer_0_base_addr + buffer_0_host_idx;

            int arg0 = *((int *)buffer_0_ptr);
            putchar(arg0);

            buffer_0_host_idx += sizeof(int);
        }
        bool is_closed_0 = interface.is_closed[0] && buffer_0_host_idx == interface.buffer_idx[0];
        active = active || !is_closed_0;

        if (buffer_1_host_idx < interface.buffer_idx[1])
        {
            buffer_1_host_idx = (buffer_1_host_idx == -1) ? 0 : buffer_1_host_idx;

            char *buffer_1_base_addr = interface.unified_buffer + interface.buffer_base_idx[1];
            char *buffer_1_ptr = buffer_1_base_addr + buffer_1_host_idx;

            int arg0 = *((int *)buffer_1_ptr);
            putchar(arg0);

            buffer_1_host_idx += sizeof(int);
        }
        bool is_closed_1 = interface.is_closed[1] && buffer_1_host_idx == interface.buffer_idx[1];
        active = active || !is_closed_1;

        if (buffer_2_host_idx < interface.buffer_idx[2])
        {
            buffer_2_host_idx = (buffer_2_host_idx == -1) ? 0 : buffer_2_host_idx;

            char *buffer_2_base_addr = interface.unified_buffer + interface.buffer_base_idx[2];
            char *buffer_2_ptr = buffer_2_base_addr + buffer_2_host_idx;

            int arg0 = *((int *)buffer_2_ptr);
            putchar(arg0);

            buffer_2_host_idx += sizeof(int);
        }
        bool is_closed_2 = interface.is_closed[2] && buffer_2_host_idx == interface.buffer_idx[2];
        active = active || !is_closed_2;
    } while (active);

    printf("\n");
    for (int i = 0; i < sizeof(int) * 3; i++)
    {
        printf("%p %d\n", interface.unified_buffer + i, interface.unified_buffer[i]);
    }
}

// void *loop_printf(void *interface)
// {
//     unsigned long long *sum = (unsigned long long *)malloc(sizeof(unsigned long long));
//     *sum = 0;

//     for (int i = 0; i < 10; i++)
//     {
//         synthcalls_async_call((async_interface_t *)interface, 0, i, false);

//         for (int i = 0; i < BIG_N; i++)
//         {
//             *sum += i;
//         }
//     }
//     synthcalls_close_callspot((async_interface_t *)interface, 0);
//     return (void *)sum;
// }

// void wrapped_loop_printf()
// {
//     size_t buffer_sizes[1] = {11};
//     async_interface_t interface;
//     init_interface(&interface, buffer_sizes, sizeof(buffer_sizes) / sizeof(size_t));

//     pthread_t thread;
//     pthread_create(&thread, NULL, loop_printf, (void *)&interface);

//     bool active;
//     int buffer_0_front_idx = -1;
//     do
//     {
//         active = false;

//         if (buffer_0_front_idx < interface.buffer_idx[0])
//         {
//             buffer_0_front_idx++;
//             char *buffer_0_addr = interface.unified_buffer + interface.buffer_base_idx[0] + buffer_0_front_idx;
//             printf("%d, ", *buffer_0_addr);
//         }
//         bool is_closed_0 = interface.is_closed[0] && buffer_0_front_idx == interface.buffer_idx[0];
//         active = active || !is_closed_0;

//     } while (active);

//     pthread_join(thread, NULL);
// }

int main()
{
    printf("Test: simple putchar\n");
    wrapped_simple_putchar();

    // printf("\nTest: loop printf\n");
    // wrapped_loop_printf();

    return 0;
}