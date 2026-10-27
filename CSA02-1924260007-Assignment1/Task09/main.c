#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

/*
 * Task 09: Implement and Test the Billing Program
 * Full billing program with rigorous input validation and tariff computation.
 *
 * Tariff structure (Assignment 1 Specification):
 *   - Fixed charge: Rs 50.00 (5000 paise)
 *   - First 100 units (0 to 100): Free (0 paise/unit)
 *   - Next 100 units (101 to 200): Rs 2.25/unit (225 paise/unit)
 *   - Units above 200: Rs 4.50/unit (450 paise/unit)
 *
 * Meter register: 16-bit counter (0 to 65535, rollover to 0).
 */

#define MAX_READING 65535U
#define SLAB1 100U
#define SLAB2 200U
#define RATE1 0LL
#define RATE2 225LL
#define RATE3 450LL
#define FIXED 5000LL

/*
 * Parses a string into an unsigned integer meter reading (0..65535).
 * Validates:
 *   - Empty input or whitespace-only input (rejected)
 *   - Non-numeric input (rejected)
 *   - Negative numbers (rejected)
 *   - Out-of-range values > 65535 (rejected)
 *   - Trailing non-whitespace characters (e.g. "1000abc") (rejected)
 * Accepts valid inputs such as "1000\n", "  1150 \r\n", "0", "65535".
 */
static int parse_reading(const char *s, unsigned *out) {
    if (!s) return 0;

    /* Skip leading whitespace */
    while (*s == ' ' || *s == '\t' || *s == '\r' || *s == '\n') {
        s++;
    }
    if (*s == '\0' || *s == '-') {
        return 0;
    }

    char *end = NULL;
    errno = 0;
    long v = strtol(s, &end, 10);

    /* Verify conversion occurred and value is within valid 16-bit register limits */
    if (errno != 0 || end == s || v < 0 || v > (long)MAX_READING) {
        return 0;
    }

    /* Skip trailing whitespace characters (including newline from fgets) */
    while (*end == ' ' || *end == '\t' || *end == '\r' || *end == '\n') {
        end++;
    }

    /* If trailing non-whitespace characters exist, reject */
    if (*end != '\0') {
        return 0;
    }

    *out = (unsigned)v;
    return 1;
}

/*
 * Computes units consumed between previous and current meter readings.
 * Accounts for 16-bit register rollover (e.g. 65535 to 0 = 1 unit).
 */
static unsigned units_used(unsigned prev, unsigned cur) {
    if (cur >= prev) {
        return cur - prev;
    } else {
        /* Single rollover modulo 65536 */
        return (MAX_READING + 1U - prev + cur);
    }
}

/*
 * Computes total bill in integer paise.
 * Fixed charge = Rs 50.00 (5000 paise).
 * Energy charge computed slab-by-slab.
 */
static long long bill_paise(unsigned units) {
    long long p = FIXED;
    if (units > SLAB2) {
        p += (long long)(units - SLAB2) * RATE3;
    }
    if (units > SLAB1) {
        unsigned upto = (units < SLAB2) ? units : SLAB2;
        p += (long long)(upto - SLAB1) * RATE2;
    }
    /* Slab 1 (0..100) is free (RATE1 = 0) */
    return p;
}

int main(void) {
    char prev_text[64];
    char cur_text[64];
    unsigned prev = 0;
    unsigned cur = 0;

    printf("Previous meter reading (0-65535): ");
    if (!fgets(prev_text, sizeof prev_text, stdin) ||
        !parse_reading(prev_text, &prev)) {
        fprintf(stderr, "Invalid previous reading.\n");
        return 1;
    }

    printf("Current meter reading (0-65535): ");
    if (!fgets(cur_text, sizeof cur_text, stdin) ||
        !parse_reading(cur_text, &cur)) {
        fprintf(stderr, "Invalid current reading.\n");
        return 1;
    }

    unsigned units = units_used(prev, cur);
    long long p = bill_paise(units);

    printf("Units consumed: %u\n", units);
    printf("Bill: Rs %lld.%02lld\n", p / 100LL, p % 100LL);
    return 0;
}
