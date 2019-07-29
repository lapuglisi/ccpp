#include <stdio.h>

#include "mempool.h"

int main(int argc, char** argv)
{
    for (int i = 0; i < argc; i++)
    {
        printf("argv[%d] = %s\n", i, argv[i]);
    }

    lap::memory::memory_pool<char> mp;

    mp.create(20 * 1024 * 1024); // 20MB

    size_t left = 0L;
    char *buffer = mp.allocate(512 * 1024, &left);
    printf("initial buffer of 512K = %p; usable memory (before allocation): %lu\n", buffer, left);
    printf("available memory now: %lu\n", mp.get_available_memory());

    buffer = mp.allocate(250 * 1024, &left);
    printf("additional buffer of 250K = %p; usable memory (before allocation): %lu\n", buffer, left);
    printf("available memory now: %lu\n", mp.get_available_memory());
    
    buffer = mp.allocate(10 * 1024 * 1024, &left);
    printf("additional buffer of 10MB = %p; usable memory (before allocation): %lu\n", buffer, left);
    printf("available memory now: %lu\n", mp.get_available_memory());

    buffer = mp.allocate(9 * 1024 * 1024, &left);
    printf("additional buffer of 9MB = %p; usable memory (before allocation): %lu\n", buffer, left);
    printf("available memory now: %lu\n", mp.get_available_memory());

    buffer = mp.allocate(1 * 1024 * 1024, &left);
    printf("additional buffer of 1MB = %p; usable memory (before allocation): %lu\n", buffer, left);
    printf("available memory now: %lu\n", mp.get_available_memory());

    return 0;
}