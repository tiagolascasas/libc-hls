#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include "synthcalls.h"

sync_call_buf *create_sync_buf(const char *arg_types)
{
    sync_call_buf *buf = (sync_call_buf *)calloc(1, sizeof(sync_call_buf));
    init_sync_buf(buf, arg_types);
    return buf;
}

void init_sync_buf(sync_call_buf *buf, const char *arg_types)
{
    buf->kernel_idx = -1;
    buf->host_idx = -1;
    buf->is_closed = false;

    size_t size = 0;
    for (size_t i = 0; i < strlen(arg_types); i++)
    {
        switch (arg_types[i])
        {
        case 'i':
        case 'c':
            size += sizeof(int32_t);
            break;
        case 'u':
            size += sizeof(uint32_t);
            break;
        case 'l':
            size += sizeof(int64_t);
            break;
        case 'U':
            size += sizeof(uint64_t);
            break;
        case 'f':
        case 'd':
            size += sizeof(double);
            break;
        case 'p':
            size += sizeof(uint64_t);
            break;
        default:
            break;
        }
    }
    buf->size = size;
    buf->buffer = (char *)calloc(size, sizeof(uint8_t));

    buf->res_buffer = 0;
    buf->has_result = false;
}