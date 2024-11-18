#include <stdio.h>
#include "synthcalls.h"

void original_foo()
{
    printf("Hello, World!\n");
    printf("Hello, World, again\n");
    putchar('H');
}

void synthcalls_foo(synthcall_interface *interface)
{
    async_call(interface, PRINTF, 0, "Hello, World!\n");
    async_call(interface, PRINTF, 1, "Hello, World, again\n");
    async_call(interface, PUTCHAR, 2, 'H');
}

void foo(synthcall_interface *interface)
{
    async_call(interface, PRINTF, 0, "Hello, World!\n");
}

int main()
{
    original_foo();

    size_t buffer_sizes[3] = {1024, 512, 256};
    synthcall_interface interface;
    init_interface(&interface, buffer_sizes, 3);

    synthcalls_foo(&interface);

    printf("Hello, World!\n");
    return 0;
}