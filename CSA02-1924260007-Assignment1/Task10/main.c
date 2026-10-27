#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <stdint.h>
#include <limits.h>

/*
 * Task 10: Compare Expectations with Execution
 * Compares:
 *   - Integer-paise exact accounting vs float rupees accumulation
 *   - Scalability across Village (4,000), Taluk (60,000), and District (800,000) scales
 *   - Overflow analysis for int (32-bit), long (32-bit), and long long (64-bit)
 *   - System sizes vs C standard minimums
 */

int main(void) {
    const long long bill_paise = 16250LL; /* Rs 162.50 in paise */
    const float bill_float = 162.50f;     /* Rs 162.50 in float rupees */
    const unsigned counts[] = {4000U, 60000U, 800000U};
    const char *scale_names[] = {"Village (4,000)", "Taluk (60,000)", "District (800,000)"};
    size_t num_scales = sizeof counts / sizeof counts[0];

    printf("--- Task 10: Billing Scale Comparison (Paise vs Float) ---\n");
    for (size_t i = 0; i < num_scales; ++i) {
        unsigned n = counts[i];

        /* Exact integer paise calculation */
        long long total_paise = bill_paise * (long long)n;
        double rupees_from_paise = (double)total_paise / 100.0;

        /* Float accumulation */
        float float_sum = 0.0f;
        for (unsigned k = 0; k < n; ++k) {
            float_sum += bill_float;
        }

        double diff = (double)float_sum - rupees_from_paise;

        printf("\nScale: %s\n", scale_names[i]);
        printf("  Integer Paise Total: %lld paise -> Rs %lld.%02lld\n",
               total_paise, total_paise / 100LL, total_paise % 100LL);
        printf("  Float Accumulated:   Rs %.4f\n", float_sum);
        printf("  Difference:          Rs %.4f\n", diff);
        printf("  32-bit int overflow: %s (Total paise %lld %s INT_MAX %ld)\n",
               (total_paise > INT_MAX) ? "YES (OVERFLOWS!)" : "NO",
               total_paise,
               (total_paise > INT_MAX) ? ">" : "<=",
               LONG_MAX);
    }

    printf("\n--- System Data Type Sizes (Platform vs Minimum C Standard) ---\n");
    printf("sizeof(int)       = %lu bytes (C standard minimum: 2 bytes)\n", (unsigned long)sizeof(int));
    printf("sizeof(long)      = %lu bytes (C standard minimum: 4 bytes)\n", (unsigned long)sizeof(long));
    printf("sizeof(long long) = %lu bytes (C standard minimum: 8 bytes)\n", (unsigned long)sizeof(long long));
    return 0;
}
