#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "synthcalls.h"

void simple_putchar(synthcall_interface *interface)
{
    async_call(interface, 0, 'H', true);
    async_call(interface, 1, 'W', true);
    async_call(interface, 2, '\n', true);
}

void wrapped_simple_putchar()
{
    // create interface
    size_t buffer_sizes[4] = {1, 1, 1};
    synthcall_interface interface;
    init_interface(&interface, buffer_sizes, sizeof(buffer_sizes) / sizeof(size_t));

    // call the function using the interface
    simple_putchar(&interface);

    // apply all the synthcalls
    bool active;
    do
    {
        active = false;

        char *buffer_0_addr = interface.unified_buffer + interface.buffer_base_idx[0] + interface.front_idx[0];
        putchar(*buffer_0_addr);
        interface.front_idx[0]++;
        bool is_closed_0 = interface.is_closed[0] && interface.front_idx[0] == interface.back_idx[0];
        active = active || !is_closed_0;

        char *buffer_1_addr = interface.unified_buffer + interface.buffer_base_idx[1] + interface.front_idx[1];
        putchar(*buffer_1_addr);
        interface.front_idx[1]++;
        bool is_closed_1 = interface.is_closed[1] && interface.front_idx[1] == interface.back_idx[1];
        active = active || !is_closed_1;

        char *buffer_2_addr = interface.unified_buffer + interface.buffer_base_idx[2] + interface.front_idx[2];
        putchar(*buffer_2_addr);
        interface.front_idx[2]++;
        bool is_closed_2 = interface.is_closed[2] && interface.front_idx[2] == interface.back_idx[2];
        active = active || !is_closed_2;

    } while (active);
}

void loop_printf(synthcall_interface *interface)
{
    for (int i = 0; i < 10; i++)
    {
        async_call(interface, 0, i, false);
    }
    close_callspot(interface, 0);
}

void wrapped_loop_printf()
{
    size_t buffer_sizes[1] = {11};
    synthcall_interface interface;
    init_interface(&interface, buffer_sizes, sizeof(buffer_sizes) / sizeof(size_t));

    loop_printf(&interface);

    int active;
    do
    {
        active = 0;

        char *buffer_0_addr = interface.unified_buffer + interface.buffer_base_idx[0] + interface.front_idx[0];
        printf("%d\n", *buffer_0_addr);
        interface.front_idx[0]++;
        bool is_closed_0 = interface.is_closed[0] && interface.front_idx[0] == interface.back_idx[0];
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