#pragma once
#include <stdarg.h>

typedef enum
{
    PRINTF,
    PUTC
} SynthCallID;

typedef struct
{
    char *buffers;
    size_t buffer_count;
    size_t *buffer_sizes;
} SynthCallInterface;

#ifdef __cplusplus
extern "C"
{
#endif
    void initInterface(SynthCallInterface *interface, size_t *buffer_sizes, int num_buffers);

    void async_call(SynthCallInterface *interface, SynthCallID id, unsigned int callspot, ...);

#ifdef __cplusplus
}
#endif
