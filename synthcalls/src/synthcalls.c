#include <stdlib.h>
#include <stddef.h>
#include "synthcalls.h"

void initInterface(SynthCallInterface *interface, size_t *buffer_sizes, int num_buffers)
{

    interface->buffer_count = num_buffers;
    interface->buffer_sizes = (size_t *)malloc(sizeof(size_t) * num_buffers);

    size_t totalSize = 0;
    for (int i = 0; i < num_buffers; i++)
    {
        totalSize += buffer_sizes[i];
    }
    interface->buffers = (char *)malloc(totalSize);
}

void async_call(SynthCallInterface *interface, SynthCallID id, unsigned int callspot, ...);