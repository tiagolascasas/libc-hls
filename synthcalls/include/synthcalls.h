#pragma once
#include <stdarg.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C"
{
#endif
    typedef enum
    {
        PRINTF,
        PUTCHAR
    } AsyncCall;

    typedef struct
    {
        unsigned int callspot;
        char *buffer;
        size_t size;
        int kernel_idx;
        int host_idx;
        bool is_closed;
    } async_call_buf;

    async_call_buf *create_async_buf(unsigned int callspot, const char *arg_types, unsigned int n_calls);

    void init_async_buf(async_call_buf *buf, unsigned int callspot, const char *arg_types, unsigned int n_calls);

    void async_call(async_call_buf *buf, bool isLast, const char *types, ...);

    bool listen_async_nonblock(async_call_buf *buf, AsyncCall fun, const char *arg_types);

    void close_async_buf(async_call_buf *buf);
#ifdef __cplusplus
}
#endif
