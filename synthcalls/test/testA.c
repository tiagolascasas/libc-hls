#include <stdio.h>
#include "synthcalls.h"

int main()
{
    size_t buffer_sizes[3] = {1024, 512, 256};
    SynthCallInterface interface;
    initInterface(&interface, buffer_sizes, 3);

    printf("Hello, World!\n");
    return 0;
}