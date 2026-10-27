#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include "billing.h"

/*
 * Task 05: Organise the Program with Header Files and Conditional Compilation
 * Multi-file modular structure:
 *   - billing.h: Header with include guards and prototypes
 *   - tariff.c:  Business logic implementation
 *   - main.c:    Application driver and conditional DEBUG mode
 */

int main(void) {
    int test_units[] = {0, 100, 150, 200, 350};
    int n = (int)(sizeof test_units / sizeof test_units[0]);

    printf("--- Task 05: Multi-file Build & Conditional Debugging ---\n");
    for (int i = 0; i < n; ++i) {
        int units = test_units[i];
        long bill = compute_bill(units);
#ifdef DEBUG
        fprintf(stderr, "[DEBUG] units=%d -> bill_paise=%ld (Rs %ld.%02ld)\n",
                units, bill, bill / 100, bill % 100);
#endif
        printf("Bill for %3d units: Rs %ld.%02ld\n", units, bill / 100, bill % 100);
    }
    return 0;
}
