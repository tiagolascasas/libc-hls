#pragma once
#include <stdarg.h>

typedef enum
{
    PRINTF,
    PUTCHAR
} synthcall_id;

typedef struct
{
    char *buffers;
    size_t buffer_count;
    size_t *buffer_sizes;
} synthcall_interface;

#ifdef __cplusplus
extern "C"
{
#endif
    void init_interface(synthcall_interface *interface, size_t *buffer_sizes, int num_buffers);

    void async_call(synthcall_interface *interface, synthcall_id id, unsigned int callspot, ...);

#ifdef __cplusplus
}
#endif
