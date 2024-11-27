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
        int32_t idx;
        bool is_closed;
    } async_kernel_info;

    typedef struct
    {
        int32_t idx;
        SyscallName fun;
    } async_host_info;

    typedef struct
    {
        async_kernel_info *kernel_info;
        async_host_info *host_info;
        int8_t* buffer;
    } async_call;

    // Host async functions
    async_call *create_async_call_fixed(SyscallName fun, unsigned int n_calls);
    async_call *create_async_call_variadic(SyscallName fun, unsigned int ncalls, unsigned int n_args);
    void replace_async_buf(async_call *call, int8_t *buf, async_kernel_info *info);
    bool listen_async_assert(async_call *call);
    bool listen_async_putchar(async_call *call);
    bool listen_async_printf(async_call *call, const char *format);

    // Kernel async functions
    void call_async_assert(int8_t *buf, async_kernel_info *info, bool isLast, bool condition);
    void call_async_putchar(int8_t *buf, async_kernel_info *info, bool isLast, char c);
    void call_async_printf(int8_t *buf, async_kernel_info *info, bool isLast, int64_t *args, size_t n_args);
    void close_async(async_kernel_info *info);

    // TODO: implement sync_call
#ifdef __cplusplus
}
#endif
