#include "libc_hls_async_host_listener.h"
bool hls_abort_listen(hls_async_call* call)
{
    if (call->host_idx >= call->kernel_info->idx)
    {
        return !call->kernel_info->is_closed;
    }
    if (call->host_idx == -1)
    {
        call->host_idx = 0;
    }
    int8_t* curr_ptr;
    abort();
    return true;
}

bool hls_assert_listen(hls_async_call* call)
{
    if (call->host_idx >= call->kernel_info->idx)
    {
        return !call->kernel_info->is_closed;
    }
    if (call->host_idx == -1)
    {
        call->host_idx = 0;
    }
    int8_t* curr_ptr;
    int8_t* curr_ptr   = call->buffer + sizeof(int);
    int     expression = *((int*)curr_ptr);
    call->host_idx += sizeof(int);
    assert(expression);
    return true;
}

bool hls_exit_listen(hls_async_call* call)
{
    if (call->host_idx >= call->kernel_info->idx)
    {
        return !call->kernel_info->is_closed;
    }
    if (call->host_idx == -1)
    {
        call->host_idx = 0;
    }
    int8_t* curr_ptr;
    int8_t* curr_ptr = call->buffer + sizeof(int);
    int     status   = *((int*)curr_ptr);
    call->host_idx += sizeof(int);
    exit(status);
    return true;
}

bool hls_fclose_listen(hls_async_call* call, FILE* stream)
{
    if (call->host_idx >= call->kernel_info->idx)
    {
        return !call->kernel_info->is_closed;
    }
    if (call->host_idx == -1)
    {
        call->host_idx = 0;
    }
    int8_t* curr_ptr;
    fclose(stream);
    return true;
}

bool hls_fflush_listen(hls_async_call* call, FILE* stream)
{
    if (call->host_idx >= call->kernel_info->idx)
    {
        return !call->kernel_info->is_closed;
    }
    if (call->host_idx == -1)
    {
        call->host_idx = 0;
    }
    int8_t* curr_ptr;
    fflush(stream);
    return true;
}

bool hls_fprintf_int_listen(hls_async_call* call, FILE* stream)
{
    if (call->host_idx >= call->kernel_info->idx)
    {
        return !call->kernel_info->is_closed;
    }
    if (call->host_idx == -1)
    {
        call->host_idx = 0;
    }
    int8_t* curr_ptr;
    int8_t* curr_ptr = call->buffer + sizeof(int);
    int     num      = *((int*)curr_ptr);
    call->host_idx += sizeof(int);
    fprintf(stream, num);
    return true;
}

bool hls_fprintf_str_listen(hls_async_call* call, FILE* stream)
{
    if (call->host_idx >= call->kernel_info->idx)
    {
        return !call->kernel_info->is_closed;
    }
    if (call->host_idx == -1)
    {
        call->host_idx = 0;
    }
    int8_t* curr_ptr;
    int8_t* curr_ptr = call->buffer + sizeof(char[N]);
    char[N] str      = *((char[N]*)curr_ptr);
    call->host_idx += sizeof(char[N]);
    fprintf(stream, str);
    return true;
}

bool hls_fputc_listen(hls_async_call* call, int c)
{
    if (call->host_idx >= call->kernel_info->idx)
    {
        return !call->kernel_info->is_closed;
    }
    if (call->host_idx == -1)
    {
        call->host_idx = 0;
    }
    int8_t* curr_ptr;
    int8_t* curr_ptr = call->buffer + sizeof(int);
    int     c        = *((int*)curr_ptr);
    call->host_idx += sizeof(int);
    fputc(c, c);
    return true;
}

bool hls_fputs_listen(hls_async_call* call, char const* string)
{
    if (call->host_idx >= call->kernel_info->idx)
    {
        return !call->kernel_info->is_closed;
    }
    if (call->host_idx == -1)
    {
        call->host_idx = 0;
    }
    int8_t*     curr_ptr;
    int8_t*     curr_ptr = call->buffer + sizeof(char const*);
    char const* string   = *((char const**)curr_ptr);
    call->host_idx += sizeof(char const*);
    fputs(string, string);
    return true;
}

bool fputwc_listen(hls_async_call* call, wchar_t wc)
{
    if (call->host_idx >= call->kernel_info->idx)
    {
        return !call->kernel_info->is_closed;
    }
    if (call->host_idx == -1)
    {
        call->host_idx = 0;
    }
    int8_t* curr_ptr;
    int8_t* curr_ptr = call->buffer + sizeof(wchar_t);
    wchar_t wc       = *((wchar_t*)curr_ptr);
    call->host_idx += sizeof(wchar_t);
    fputwc(wc, wc);
    return true;
}
