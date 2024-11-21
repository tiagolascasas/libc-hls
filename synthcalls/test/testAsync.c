#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <pthread.h>
#include "synthcalls.h"

#define BIG_N 1000000000

void *kernel_A(async_call_buf *putchar_0, async_call_buf *putchar_1, async_call_buf *putchar_2)
{
    async_call(putchar_0, true, "c", 'H');
    unsigned long long *sum = (unsigned long long *)malloc(sizeof(unsigned long long));
    *sum = 0;

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

void wrapped_simple_putchar()
{
    async_call_buf *putchar_0 = create_async_buf(0, "c", 1);
    async_call_buf *putchar_1 = create_async_buf(1, "c", 1);
    async_call_buf *putchar_2 = create_async_buf(2, "c", 1);

    kernel_A(&putchar_0, &putchar_1, &putchar_2);

    bool active = true;
    while (active)
    {
        active = false;
        active = active || listen_async_nonblock(&putchar_0, PUTCHAR, "c");
        active = active || listen_async_nonblock(&putchar_1, PUTCHAR, "c");
        active = active || listen_async_nonblock(&putchar_2, PUTCHAR, "c");
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
//     size_t buffer_sizes[1] = {11 * sizeof(int)};
//     async_interface_t interface;
//     synthcalls_init_interface(&interface, buffer_sizes, 1);

//     pthread_t thread;
//     pthread_create(&thread, NULL, loop_printf, (void *)&interface);

//     pthread_join(thread, NULL);

//     printf("\n");
//     for (int i = 0; i < sizeof(int) * 11; i++)
//     {
//         printf("%p %d\n", interface.unified_buffer + i, interface.unified_buffer[i]);
//     }

//     bool active;
//     int buffer_0_host_idx = -1;

//     do
//     {
//         active = false;

//         if (buffer_0_host_idx < interface.buffer_idx[0])
//         {
//             buffer_0_host_idx = (buffer_0_host_idx == -1) ? 0 : buffer_0_host_idx;

//             char *buffer_0_base_addr = interface.unified_buffer + interface.buffer_base_idx[0];
//             char *buffer_0_ptr = buffer_0_base_addr + buffer_0_host_idx;

//             int arg0 = *((int *)buffer_0_ptr);
//             printf("Loop index: %d\n", arg0);

//             buffer_0_host_idx += sizeof(int);
//         }
//         bool is_closed_0 = interface.is_closed[0] && buffer_0_host_idx == interface.buffer_idx[0];
//         active = active || !is_closed_0;
//     } while (active);
// }

int main()
{
    printf("Test: simple putchar\n");
    wrapped_simple_putchar();

    // printf("\nTest: loop printf\n");
    // wrapped_loop_printf();

    return 0;
}