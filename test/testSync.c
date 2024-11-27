#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <pthread.h>
#include "synthcalls.h"

#define N 128

double *v1_x;
double *v1_y;
double *v2_x;
double *v2_y;
double *distances;
double *reference;
sync_call *sqrt_call;
sync_call *pow_call;

void *euclidean_distance()
{
    for (size_t i = 0; i < N; i++)
    {
        double dx = v1_x[i] - v2_x[i];
        double dy = v1_y[i] - v2_y[i];

        dx = pow(dx, 2);
        if (i % 20)
        {
            dx = call_sync_pow(pow_call->args.float_arg_buf,
                               &pow_call->ret.float_ret,
                               pow_call->info,
                               false,
                               dx,
                               2);
        }
        else
        {
            dx = pow(dx, 2);
        }
        dy = pow(dy, 2);
        close_sync(pow_call->info);

        double d = dx + dy;
        if (i % 32 == 0)
        {
            d = call_sync_sqrt(sqrt_call->args.float_arg_buf,
                               &sqrt_call->ret.float_ret,
                               sqrt_call->info,
                               false,
                               d);
        }
        else
        {
            d = sqrt(d);
        }
        close_sync(sqrt_call->info);
        distances[i] = d;
    }
    return NULL;
}

void wrapped_euclidean_distance()
{
    v1_x = (double *)malloc(N * sizeof(double));
    v1_y = (double *)malloc(N * sizeof(double));
    v2_x = (double *)malloc(N * sizeof(double));
    v2_y = (double *)malloc(N * sizeof(double));
    distances = (double *)malloc(N * sizeof(double));
    reference = (double *)malloc(N * sizeof(double));

    for (size_t i = 0; i < N; i++)
    {
        v1_x[i] = (double)i;
        v1_y[i] = (double)i * 2;
        v2_x[i] = (double)i + 42;
        v2_y[i] = (double)i + (i % 2 == 0 ? -50 : 100);
        distances[i] = 0.0;
        reference[i] = sqrt(pow(v1_x[i] - v2_x[i], 2) + pow(v1_y[i] - v2_y[i], 2));
    }
    sqrt_call = create_sync_call_fixed(SQRT);
    pow_call = create_sync_call_fixed(POW);

    pthread_t thread;
    pthread_create(&thread, NULL, euclidean_distance, NULL);

    bool valid;
    do {
        valid = false;
        valid = valid || listen_sync_sqrt(sqrt_call);
        valid = valid || listen_sync_pow(pow_call);
    }
    while (valid);

    pthread_join(thread, NULL);

    bool same = memcmp(distances, reference, N * sizeof(double)) == 0;
    printf("Test %s\n", same ? "PASSED" : "FAILED");
}

int main()
{
    printf("--------------------------------------------------\n");
    printf("Test: sqrt() and pow() call spots, repeated\n");
    wrapped_euclidean_distance();

    return 0;
}