#pragma once
#include <stdarg.h>

typedef enum
{
    PRINTF,
    PUTC
} SynthCallID;

#ifdef __cplusplus
extern "C"
{
#endif

    void async_call(SynthCallID id, unsigned int callspot, ...);

#ifdef __cplusplus
}
#endif
