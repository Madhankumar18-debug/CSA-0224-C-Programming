#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <stdint.h>
#include <limits.h>

/*
 * Task 07: Control Type Conversion and Precision
 * Demonstrates:
 *   1. Integer division truncation (e.g. 5 / 2 = 2, discarding 0.5)
 *   2. Binary floating-point representation artifact (0.1 + 0.2 != 0.3)
 *   3. Truncation toward zero on double-to-int cast ((int)3.99 = 3)
 *   4. Narrowing cast overflow / wraparound from 64-bit to 32-bit int
 *   5. Correct integer-paise accumulation preventing fractional loss
 */

int main(void) {
    printf("--- Task 07: Type Conversion, Division & Precision Demonstrations ---\n");

    /* Surprise 1: Integer division discards fractional remainder */
    printf("\n[Surprise 1: Integer Division]\n");
    printf("  Expression: 5 / 2 = %d (expected 2.5, fraction discarded!)\n", 5 / 2);
    printf("  Fixed with cast: (double)5 / 2 = %.2f\n", (double)5 / 2);

    /* Surprise 2: Binary floating-point representation inexactness */
    printf("\n[Surprise 2: Binary Floating-Point Inexactness]\n");
    printf("  Expression: 0.1 + 0.2 = %.17f\n", 0.1 + 0.2);
    printf("  Comparison (0.1 + 0.2 == 0.3): %s\n",
           (0.1 + 0.2 == 0.3) ? "TRUE" : "FALSE (differs at 17th decimal place!)");

    /* Surprise 3: Truncation towards zero in explicit cast */
    printf("\n[Surprise 3: Double to Int Truncation]\n");
    printf("  Expression: (int)3.99 = %d (truncates towards zero, not rounded to 4!)\n", (int)3.99);
    printf("  Proper rounding: (int)(3.99 + 0.5) = %d\n", (int)(3.99 + 0.5));

    /* Surprise 4: Narrowing cast overflow */
    printf("\n[Surprise 4: Narrowing Cast Overflow]\n");
    long long large_val = 3000000000LL; /* Exceeds 32-bit signed INT_MAX (2,147,483,647) */
    int truncated_val = (int)large_val;
    printf("  Original int64 value: %lld\n", large_val);
    printf("  Casting to 32-bit int: %d (overflow / sign change!)\n", truncated_val);

    /* Resolution: Exact integer-paise arithmetic */
    printf("\n[Resolution: Integer Paise Accounting]\n");
    long long paise_per_bill = 225LL;
    long long bills_count = 4000LL;
    long long total_paise = paise_per_bill * bills_count;
    printf("  4,000 bills at 225 paise = %lld paise (Rs %lld.%02lld exactly)\n",
           total_paise, total_paise / 100LL, total_paise % 100LL);

    return 0;
}
