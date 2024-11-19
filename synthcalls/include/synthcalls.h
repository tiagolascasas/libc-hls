#pragma once
#include <stdarg.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C"
{
#endif
    typedef struct
    {
        char *unified_buffer;
        size_t unified_buffer_size;

        unsigned int *buffer_base_idx;
        size_t *buffer_sizes;
        unsigned int buffer_count;

        unsigned int *front_idx;
        int *back_idx;
    } synthcall_interface;

    void init_interface(synthcall_interface *interface, size_t *buffer_sizes, unsigned int num_buffers);

    void async_call(synthcall_interface *interface, unsigned int callspot, char arg, bool isLast);

    void close_callspot(synthcall_interface *interface, unsigned int callspot);
#ifdef __cplusplus
}
#endif
