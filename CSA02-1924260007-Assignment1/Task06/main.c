#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <limits.h>

/*
 * Task 06: Read and Print Data Correctly
 * Demonstrates:
 *   - Formatted input using scanf with format specifiers
 *   - Input validation checking the return value of scanf
 *   - Range validation on household ID (positive) and meter readings (0..65535)
 *   - Handling of rollover and printing exact rupee/paise amounts
 */

int main(void) {
    int household = 0;
    int previous = 0;
    int current = 0;
    char category[32];

    printf("Enter household number, category, previous reading, current reading: ");
    if (scanf("%d %31s %d %d", &household, category, &previous, &current) != 4) {
        fprintf(stderr, "Invalid input. Expected: <int:household> <string:category> <int:prev> <int:curr>\n");
        return 1;
    }

    if (household <= 0 || previous < 0 || previous > 65535 ||
        current < 0 || current > 65535) {
        fprintf(stderr, "Input out of allowed range (household > 0, readings in 0..65535).\n");
        return 1;
    }

    /* Rollover calculation for 16-bit counter */
    unsigned int units = (current >= previous)
                         ? (unsigned int)(current - previous)
                         : (unsigned int)(65536 - previous + current);

    /* Tariff calculation in paise */
    long bill_paise = 5000L; /* Rs 50 fixed charge */
    if (units > 200U) {
        bill_paise += (long)(units - 200U) * 450L + 100L * 225L;
    } else if (units > 100U) {
        bill_paise += (long)(units - 100U) * 225L;
    }

    printf("Household: %d | Category: %s | Units: %u | Bill: Rs %ld.%02ld\n",
           household, category, units, bill_paise / 100L, bill_paise % 100L);
    return 0;
}
