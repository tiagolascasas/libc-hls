#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include "synthcalls.h"

static sync_call *create_sync_call(SyncCall fun, size_t buffer_size, bool args_are_float, bool ret_is_float);

sync_call *create_sync_call_fixed(SyncCall fun)
{
    size_t size = 0;
    bool args_are_float = false;
    bool ret_is_float = false; 
    switch (fun)
    {
    case SQRT:
        size = sizeof(double);
        args_are_float = true;
        ret_is_float = true;
        break;
    case POW:
        size = sizeof(double) * 2;
        args_are_float = true;
        ret_is_float = true;
        break;
    default:
        break;
    }
    return create_sync_call(fun, size, args_are_float, ret_is_float);
}

sync_call *create_sync_call_variadic(SyncCall fun, unsigned int n_args)
{
    printf("create_sync_call_variadic not yet implemented\n");
}

static sync_call *create_sync_call(SyncCall fun, size_t buffer_size, bool args_are_float, bool ret_is_float)  {
    sync_call *call = (sync_call *)calloc(1, sizeof(sync_call));
    call->args_are_float = args_are_float;
    call->ret_is_float = ret_is_float;
    call->fun = fun;

    if (args_are_float) {
        call->args.float_arg_buf = (double *)calloc(1, buffer_size);
    } else {
        call->args.int_arg_buf = (int64_t *)calloc(1, buffer_size);
    }

    if (ret_is_float) {
        call->ret.float_ret = 0.0f;
    } else {
        call->ret.int_ret = 0;
    }

    sync_info* info = (sync_info *)calloc(1, sizeof(sync_info));
    info->kernel_has_data = false;
    info->host_has_data = false;
    info->is_closed = false;
    call->info = info;
}

bool listen_sync_sqrt(sync_call *call)
{
    if (!call->info->kernel_has_data)
    {
        return !call->info->is_closed;
    }
    double x = call->args.float_arg_buf[0];
    double res = sqrt(x);

    call->ret.float_ret = res;
    call->info->host_has_data = true;
    call->info->kernel_has_data = false;
    return true;
}

bool listen_sync_pow(sync_call *call)
{
    if (!call->info->kernel_has_data)
    {
        return !call->info->is_closed;
    }
    double base = call->args.float_arg_buf[0];
    double exp = call->args.float_arg_buf[1];
    double res = pow(base, exp);

    call->ret.float_ret = res;
    call->info->host_has_data = true;
    call->info->kernel_has_data = false;
    return true;
}
