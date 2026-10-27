#include "billing.h"
long compute_bill(int units) {
    if (units < 0) return -1L;
    long p = FIXED_CHARGE_PAISE;
    if (units > SLAB2_UNITS) p += (long)(units - SLAB2_UNITS) * RATE3_PAISE;
    if (units > SLAB1_UNITS) {
        int upper = units < SLAB2_UNITS ? units : SLAB2_UNITS;
        p += (long)(upper - SLAB1_UNITS) * RATE2_PAISE;
    }
    return p;
}
