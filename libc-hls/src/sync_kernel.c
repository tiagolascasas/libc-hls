#include "synthcalls.h"

inline static double get_float_result(double *ret_val, sync_info *info, bool is_last)
{
    info->kernel_has_data = true;
    while (!info->host_has_data)
    {
    }
    info->host_has_data = false;
    double res = *ret_val;
    if (is_last)
    {
        close_sync(info);
    }
    return res;
}

double call_sync_sqrt(double *arg_buf, double *ret_val, sync_info *info, bool is_last, double x)
{
    arg_buf[0] = x;
    return get_float_result(ret_val, info, is_last);
}

double call_sync_pow(double *arg_buf, double *ret_val, sync_info *info, bool is_last, double base, double exponent)
{
    arg_buf[0] = base;
    arg_buf[1] = exponent;
    return get_float_result(ret_val, info, is_last);
}

inline void close_sync(sync_info *info)
{
    info->is_closed = true;
}