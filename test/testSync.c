#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <pthread.h>
#include "synthcalls.h"

#define N 128

void euclidean_distance(double *v1_x, double *v1_y, double *v2_x, double *v2_y, double *distances, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        double dx = v1_x[i] - v2_x[i];
        double dy = v1_y[i] - v2_y[i];

        dx = pow(dx, 2);
        if (i % 20) {
            // dx = sync_sqrt()
        }
        else {
            dx = pow(dx, 2);
        }
        dy= pow(dy, 2);

        double d = dx + dy;
        if (i % 32 == 0) {
            // d = sync_sqrt()
        }
        else {
            d = sqrt(d);
        }
        distances[i] = d;
    }
}

void wrapped_euclidean_distance()
{

}

int main()
{
    printf("--------------------------------------------------\n");
    printf("Test: sqrt() and pow() call spots, repeated\n");
    wrapped_kernel_A();

    return 0;
}