#pragma once
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif
    typedef struct
    {
        char *buffer;
        size_t size;
        int kernel_idx;
        int host_idx;
        bool is_closed;
    } async_call_buf;

    async_call_buf *create_async_buf(const char *arg_types, unsigned int n_calls);

    void init_async_buf(async_call_buf *buf, const char *arg_types, unsigned int n_calls);

    void async_call(async_call_buf *buf, bool isLast, const char *types, ...);

    bool listen_async_assert(async_call_buf *buf);

    bool listen_async_putchar(async_call_buf *buf);

    bool listen_async_printf(async_call_buf *buf, const char *format);

    void close_async_buf(async_call_buf *buf);

    typedef struct
    {
        // call buffer is similar to the async buffer
        char *buffer;
        size_t size;
        int kernel_idx;
        int host_idx;
        bool is_closed;

        // result buffer has only 64-bit, as that fits the result of most STDLIB functions
        uint64_t res_buffer;
        bool has_result;
    } sync_call_buf;

    sync_call_buf *create_sync_buf(const char *arg_types);

    void init_sync_buf(sync_call_buf *buf, const char *arg_types);

    // TODO: implement sync_call
#ifdef __cplusplus
}
#endif
