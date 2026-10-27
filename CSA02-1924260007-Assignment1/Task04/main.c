#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>

/*
 * Task 04: Use Macros Safely
 * Demonstrates proper macro parenthesisation, side-effect pitfalls,
 * and static inline function equivalents.
 */

#define RUPEES_TO_PAISE(r) ((long)(r) * 100L)
#define SQUARE(x)          ((x) * (x))
#define BAD_SQUARE(x)      x * x
#define MAX(a, b)          ((a) > (b) ? (a) : (b))

static inline long square_long(long x) {
    return x * x;
}

static inline int max_int(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    printf("--- Task 04: Safe Macros vs Inline Functions ---\n");
    printf("RUPEES_TO_PAISE(12) = %ld paise\n", RUPEES_TO_PAISE(12));

    /* Parenthesisation demonstration with a + 1 */
    int a = 4, b = 7;
    printf("\nParenthesisation comparison for a = 4:\n");
    printf("  BAD_SQUARE(a + 1) = %d (wrong: 4 + 1 * 4 + 1 = 9)\n", BAD_SQUARE(a + 1));
    printf("  SQUARE(a + 1)     = %d (correct: (4 + 1) * (4 + 1) = 25)\n", SQUARE(a + 1));

    /* Double evaluation pitfall demonstration */
    int i1 = 5, j1 = 3;
    printf("\nSide-effect pitfall with MAX(i++, j) vs inline max_int(i++, j):\n");
    int m_macro = MAX(i1++, j1);
    printf("  MAX macro result = %d, i after macro = %d (evaluated twice!)\n", m_macro, i1);

    int i2 = 5, j2 = 3;
    int m_func = max_int(i2++, j2);
    printf("  Inline max result= %d, i after inline = %d (evaluated once)\n", m_func, i2);

    /* Regular inline calls */
    printf("\nStandard calls:\n");
    printf("  MAX(a, b)        = %d\n", MAX(a, b));
    printf("  inline square(5) = %ld\n", square_long(5));
    printf("  inline max(a, b) = %d\n", max_int(a, b));
    return 0;
}
