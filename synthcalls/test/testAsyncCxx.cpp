#include <iostream>
#include <thread>
#include <cstddef>
#include "synthcalls.h"

#define BIG_N 100000000

int loop_cout(async_interface_t *interface)
{
    unsigned long long sum = 0;
    for (int i = 0; i < 10; i++)
    {
        synthcalls_async_call(interface, 0, false, "i", i);

        for (int i = 0; i < BIG_N; i++)
        {
            sum += i;
        }
    }
    synthcalls_close_callspot(interface, 0);
    return sum;
}

void wrapped_loop_cout()
{
    size_t buffer_sizes[1] = {11};
    async_interface_t interface;
    synthcalls_init_interface(&interface, buffer_sizes, sizeof(buffer_sizes) / sizeof(size_t));

    std::thread thread(loop_cout, &interface);

    bool active;
    int buffer_0_front_idx = -1;
    do
    {
        active = false;

        if (buffer_0_front_idx < interface.buffer_idx[0])
        {
            buffer_0_front_idx++;
            char *buffer_0 = interface.unified_buffer + interface.buffer_base_idx[0];
            char data = buffer_0[buffer_0_front_idx];
            std::cout << static_cast<unsigned int>(data) << std::endl;
        }
        bool is_closed_0 = interface.is_closed[0] && buffer_0_front_idx == interface.buffer_idx[0];
        active = active || !is_closed_0;

    } while (active);

    thread.join();
}

int main()
{
    printf("\nTest: loop std::cout\n");
    wrapped_loop_cout();

    return 0;
}