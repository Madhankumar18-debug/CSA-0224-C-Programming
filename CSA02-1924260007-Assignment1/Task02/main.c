#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <stdint.h>

/*
 * Task 02: Choose the Data Types
 * Complete the Code exercise from Assignment 1 Specification (Page 3)
 */

/* The meter register is a 16-bit counter: after 65535 it rolls over to 0. */
typedef unsigned short meter_t;

unsigned int consumption(meter_t previous, meter_t current) {
    /*
     * TODO 1: Return the units consumed, correct even when the register has rolled over
     * (current < previous); use unsigned 16-bit arithmetic instead of an if-else.
     * In C unsigned arithmetic, (current - previous) modulo 65536 is guaranteed by standard.
     */
    return (meter_t)(current - previous);
}

int main(void) {
    /* Part 1: Required Starter Code Verification (Assignment Page 3) */
    printf("--- Part 1: Starter Code Rollover Demonstration ---\n");
    printf("sizeof(meter_t) = %zu bytes, maximum reading = %u\n", sizeof(meter_t), (unsigned)USHRT_MAX);
    printf("Consumption: %u units\n", consumption(1200, 1530));
    printf("Consumption: %u units\n", consumption(65400, 120)); /* rolled over */

    /* Part 2: Data Types Sizes and Ranges on this System */
    printf("\n--- Part 2: System Data Type Sizes and Ranges ---\n");
    printf("sizeof(char)      = %zu byte,  range = %d to %d\n", sizeof(char), CHAR_MIN, CHAR_MAX);
    printf("sizeof(short)     = %zu bytes, range = %d to %d\n", sizeof(short), SHRT_MIN, SHRT_MAX);
    printf("sizeof(int)       = %zu bytes, range = %d to %d\n", sizeof(int), INT_MIN, INT_MAX);
    printf("sizeof(long)      = %zu bytes, range = %ld to %ld\n", sizeof(long), LONG_MIN, LONG_MAX);
    printf("sizeof(long long) = %zu bytes, range = %lld to %lld\n", sizeof(long long), LLONG_MIN, LLONG_MAX);
    printf("sizeof(float)     = %zu bytes, precision digits = %d\n", sizeof(float), FLT_DIG);
    printf("sizeof(double)    = %zu bytes, precision digits = %d\n", sizeof(double), DBL_DIG);

    /* Part 3: Floating-point precision error demonstration (4,000 bills) */
    printf("\n--- Part 3: Float vs Integer-Paise Precision Test (4,000 bills) ---\n");
    float bill_float = 162.50f;
    float sum_float = 0.0f;
    for (int i = 0; i < 4000; ++i) {
        sum_float += bill_float;
    }
    long long bill_paise = 16250LL;
    long long sum_paise = 0LL;
    for (int i = 0; i < 4000; ++i) {
        sum_paise += bill_paise;
    }

    printf("Float accumulation total:   Rs %.4f\n", sum_float);
    printf("Integer paise exact total:  Rs %lld.%02lld (paise: %lld)\n",
           sum_paise / 100, sum_paise % 100, sum_paise);
    return 0;
}
