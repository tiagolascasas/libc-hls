#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include "synthcalls.h"

void init_interface(synthcall_interface *interface, size_t *buffer_sizes, unsigned int num_buffers)
{
    interface->buffer_count = num_buffers;
    interface->buffer_base_idx = (unsigned int *)malloc(sizeof(unsigned int) * num_buffers);
    interface->buffer_sizes = (size_t *)malloc(sizeof(size_t) * num_buffers);
    interface->front_idx = (unsigned int *)malloc(sizeof(unsigned int) * num_buffers);
    interface->back_idx = (unsigned int *)malloc(sizeof(unsigned int) * num_buffers);
    interface->is_closed = (bool *)malloc(sizeof(bool) * num_buffers);

    size_t totalSize = 0;
    for (int i = 0; i < num_buffers; i++)
    {
        interface->buffer_base_idx[i] = totalSize;
        interface->buffer_sizes[i] = buffer_sizes[i];
        interface->front_idx[i] = 0;
        interface->back_idx[i] = 0;
        interface->is_closed[i] = false;

        totalSize += buffer_sizes[i];
    }
    interface->unified_buffer = (char *)malloc(totalSize);
}

void async_call(synthcall_interface *interface, unsigned int callspot, char arg, bool isLast)
{
    char *buffer = interface->unified_buffer + interface->buffer_base_idx[callspot];
    unsigned int back_idx = interface->back_idx[callspot];

    buffer[back_idx] = arg;
    interface->back_idx[callspot] += 1;

    if (isLast)
    {
        close_callspot(interface, callspot);
    }
}

void close_callspot(synthcall_interface *interface, unsigned int callspot)
{
    interface->is_closed[callspot] = true;
}