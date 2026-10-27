#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

/*
 * Task 11: Recommend and Defend the Final Design
 * Final recommended design:
 *   - Meter reading: uint16_t (0..65535, exactly matching physical register)
 *   - Units consumed: uint32_t (handles rollover and up to 65535 units)
 *   - Money / Charges: int64_t paise (prevents all rounding and overflow at district scale)
 *   - Tariff constants: strongly typed integer constants
 */

#define METER_MAX          UINT16_MAX
#define FIXED_CHARGE_PAISE INT64_C(5000)
#define RATE1_PAISE        INT64_C(0)
#define RATE2_PAISE        INT64_C(225)
#define RATE3_PAISE        INT64_C(450)

static int64_t bill_for_units(uint32_t units) {
    int64_t p = FIXED_CHARGE_PAISE;
    if (units > 200U) {
        p += (int64_t)(units - 200U) * RATE3_PAISE;
        p += (int64_t)(100U) * RATE2_PAISE;
    } else if (units > 100U) {
        p += (int64_t)(units - 100U) * RATE2_PAISE;
    }
    return p;
}

int main(void) {
    printf("--- Task 11: Recommended Production Billing Architecture ---\n");

    uint32_t sample_units[] = {0, 100, 150, 200, 350};
    size_t count = sizeof sample_units / sizeof sample_units[0];

    for (size_t i = 0; i < count; ++i) {
        int64_t p = bill_for_units(sample_units[i]);
        printf("Units: %3u -> Bill: Rs %" PRId64 ".%02" PRId64 " (%" PRId64 " paise)\n",
               (unsigned)sample_units[i], p / 100, p % 100, p);
    }

    /* Demonstrate district scalability (800,000 households at average 350 units) */
    int64_t district_households = INT64_C(800000);
    int64_t bill_350 = bill_for_units(350);
    int64_t district_total_paise = district_households * bill_350;

    printf("\nDistrict Scale Simulation (800,000 households @ 350 units):\n");
    printf("  Single bill (350 units): Rs %" PRId64 ".%02" PRId64 "\n",
           bill_350 / 100, bill_350 % 100);
    printf("  District total:          Rs %" PRId64 ".%02" PRId64 " (%" PRId64 " paise)\n",
           district_total_paise / 100, district_total_paise % 100, district_total_paise);
    printf("  Data type: int64_t guarantees zero overflow (Capacity: ~9.22 x 10^18 paise)\n");
    return 0;
}
