#pragma once
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif
    typedef enum
    {
        ASSERT,
        PUTCHAR,
        PRINTF
    } SyscallName;

    // Async data structures
    typedef struct
    {
        size_t size;
        int32_t kernel_idx;
        int32_t host_idx;
        bool is_closed;
    } async_info;

    typedef struct
    {
        async_info *info;
        int8_t *buffer;
    } async_call_buf;

    // Host async functions
    async_call_buf *create_async_buf_fixed(SyscallName fun, unsigned int n_calls);
    async_call_buf *create_async_buf_variadic(unsigned int n_args, unsigned int ncalls);
    bool listen_async_assert(async_call_buf *buf);
    bool listen_async_putchar(async_call_buf *buf);
    bool listen_async_printf(async_call_buf *buf, const char *format);

    // Kernel async functions
    void call_async_assert(int8_t *buf, async_info *info, bool isLast, bool condition);
    void call_async_putchar(int8_t *buf, async_info *info, bool isLast, char c);
    void call_async_printf(int8_t *buf, async_info *info, bool isLast, int64_t *args, size_t n_args);
    void close_async(async_info *info);

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
