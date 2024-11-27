#include "synthcalls.h"

double call_sync_sqrt(double *arg_buf, sync_info *info, bool is_last, double x)
{
    arg_buf[0] = x;
    info->kernel_has_data = true;
    if (is_last)
    {
        close_sync(info);
    }
}

double call_sync_pow(double *arg_buf, sync_info *info, bool is_last, double base, double exponent)
{
    arg_buf[0] = base;
    arg_buf[1] = exponent;
    info->kernel_has_data = true;
    if (is_last)
    {
        close_sync(info);
    }
}

inline void close_sync(sync_info *info)
{
    info->is_closed = true;
}