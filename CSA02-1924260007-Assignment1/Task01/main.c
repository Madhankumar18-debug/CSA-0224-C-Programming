#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <stdint.h>

/*
 * Task 01: Understand the Problem and Identify the Data
 * Demonstrates the 16-bit meter register rollover arithmetic.
 * A 16-bit unsigned counter rolls over from 65535 to 0.
 * Modular unsigned 16-bit subtraction calculates the true units consumed
 * without requiring conditional branching.
 */

typedef uint16_t meter_t;

uint32_t consumption(meter_t previous, meter_t current) {
    return (uint32_t)(uint16_t)(current - previous);
}

int main(void) {
    printf("--- Task 01: Problem Understanding & 16-bit Rollover Demo ---\n");
    printf("Normal reading: 1200 to 1530 -> %u units\n",
           (unsigned)consumption(1200, 1530));
    printf("Rollover reading: 65400 to 120 -> %u units\n",
           (unsigned)consumption(65400, 120));
    printf("Boundary reading: 65535 to 0 -> %u units\n",
           (unsigned)consumption(65535, 0));
    return 0;
}
