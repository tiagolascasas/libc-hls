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
        size_t size;
        int32_t kernel_idx;
        int32_t host_idx;
        bool is_closed;
        int8_t *buffer;
    } async_call_buf;

    async_call_buf *create_async_buf(const char *arg_types, unsigned int n_calls);

    void async_call(async_call_buf *buf, bool isLast, const char *types, ...);

    bool listen_async_assert(async_call_buf *buf);

    bool listen_async_putchar(async_call_buf *buf);

    bool listen_async_printf(async_call_buf *buf, const char *format);

    void close_async_buf(async_call_buf *buf);

    typedef struct
    {
        
        size_t size;
        int32_t kernel_idx;
        int32_t host_idx;
        bool is_closed;
        int64_t res_buffer;
        bool has_result;

        int8_t *buffer;

    } sync_call_buf;

    sync_call_buf *create_sync_buf(const char *arg_types);

    void init_sync_buf(sync_call_buf *buf, const char *arg_types);

    // TODO: implement sync_call
#ifdef __cplusplus
}
#endif
