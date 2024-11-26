#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include "synthcalls.h"

sync_call_buf *create_sync_buf(const char *arg_types) {
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
    size_t total_size = sizeof(sync_call_buf) + size;

    sync_call_buf *buf = (sync_call_buf *)calloc(total_size, sizeof(uint8_t));

    buf->size = size;
    buf->kernel_idx = -1;
    buf->host_idx = -1;
    buf->is_closed = false;
    buf->res_buffer = 0;
    buf->has_result = false;
    buf->buffer = (int8_t *)(buf + 1);
    return buf;
}