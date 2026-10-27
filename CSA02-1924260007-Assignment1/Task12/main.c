#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>

/*
 * Task 12: Day-4 Design Challenge (Smart Meter Time-of-Day Billing)
 * Changed Requirements:
 *   1. Readings received every 15 minutes in Watt-hours (35,040 readings/year/household).
 *   2. Time-of-Day (ToD) tariff: Peak hours between 18:00 (6 PM) and 22:00 (10 PM) cost 20% extra.
 *   3. Runtime-configurable tariff parameters via 'tariff.cfg' (no code recompilation needed).
 *   4. Wide 64-bit integer arithmetic with micro-paise accumulator to avoid precision loss.
 */

#define CONFIG_FILE "tariff.cfg"
#define INTERVALS_PER_YEAR 35040U
#define PEAK_START_MINUTE (18 * 60) /* 18:00 = 1080 min */
#define PEAK_END_MINUTE   (22 * 60) /* 22:00 = 1320 min */

typedef struct {
    int64_t fixed_charge_paise;
    int64_t normal_rate_paise_per_kwh;
    int peak_percent;
} Tariff;

/* Reads runtime configuration file (format: fixed_paise normal_rate_paise_per_kwh peak_percent) */
static int load_tariff(Tariff *t) {
    FILE *f = fopen(CONFIG_FILE, "r");
    if (!f) return 0;

    int ok = fscanf(f, "%" SCNd64 " %" SCNd64 " %d",
                    &t->fixed_charge_paise,
                    &t->normal_rate_paise_per_kwh,
                    &t->peak_percent) == 3;
    fclose(f);

    return ok && t->fixed_charge_paise >= 0 &&
           t->normal_rate_paise_per_kwh >= 0 &&
           t->peak_percent >= 0 && t->peak_percent <= 1000;
}

/*
 * Computes interval charge in micro-paise (1 paise = 1,000,000 micro-paise).
 * High-precision fixed-point avoids floating-point inaccuracies when aggregating 35,040 intervals.
 */
static int64_t interval_charge_micro_paise(uint64_t watt_hours,
                                           int minute, const Tariff *t) {
    int64_t rate_micro = t->normal_rate_paise_per_kwh * INT64_C(1000000);
    if (minute >= PEAK_START_MINUTE && minute < PEAK_END_MINUTE) {
        rate_micro += rate_micro * (int64_t)t->peak_percent / 100LL;
    }
    /* 1 kWh = 1000 Wh */
    return (int64_t)watt_hours * rate_micro / 1000LL;
}

int main(void) {
    printf("--- Task 12: Day-4 Design Challenge (Smart Meter TOD Billing) ---\n");

    Tariff tariff;
    if (!load_tariff(&tariff)) {
        fprintf(stderr, "Error: Cannot read valid %s (format: fixed_paise rate_paise_per_kwh peak_percent).\n",
                CONFIG_FILE);
        return 1;
    }

    printf("Tariff Loaded from %s:\n", CONFIG_FILE);
    printf("  Fixed Charge:      Rs %" PRId64 ".%02" PRId64 " (%" PRId64 " paise)\n",
           tariff.fixed_charge_paise / 100, tariff.fixed_charge_paise % 100, tariff.fixed_charge_paise);
    printf("  Normal Rate:       Rs %" PRId64 ".%02" PRId64 "/kWh (%" PRId64 " paise/kWh)\n",
           tariff.normal_rate_paise_per_kwh / 100, tariff.normal_rate_paise_per_kwh % 100, tariff.normal_rate_paise_per_kwh);
    printf("  Peak Surcharge:    %d%% (Active 18:00 to 22:00)\n\n", tariff.peak_percent);

    /* Demonstration readings spanning off-peak and peak intervals */
    const uint64_t watt_hours[] = {500, 750, 1000, 250};
    const int minutes[] = {10 * 60, 19 * 60, 21 * 60, 23 * 60};
    const char *times[] = {"10:00 (Off-Peak)", "19:00 (Peak +20%)", "21:00 (Peak +20%)", "23:00 (Off-Peak)"};

    size_t num_intervals = sizeof watt_hours / sizeof watt_hours[0];
    int64_t energy_micro_paise = 0;

    printf("Processing demonstration intervals:\n");
    for (size_t i = 0; i < num_intervals; ++i) {
        int64_t chg_micro = interval_charge_micro_paise(watt_hours[i], minutes[i], &tariff);
        energy_micro_paise += chg_micro;
        printf("  Interval %lu: %s | %" PRIu64 " Wh -> %" PRId64 " micro-paise (%.4f paise)\n",
               (unsigned long)(i + 1), times[i], watt_hours[i], chg_micro, (double)chg_micro / 1000000.0);
    }

    /* Round half-up to nearest paise */
    int64_t energy_paise = (energy_micro_paise + 500000LL) / 1000000LL;
    int64_t total_paise = tariff.fixed_charge_paise + energy_paise;

    printf("\nBilling Summary:\n");
    printf("  Intervals processed:         %lu\n", (unsigned long)num_intervals);
    printf("  Annual intervals per meter:  %u\n", INTERVALS_PER_YEAR);
    printf("  Accumulated Energy Charge:   Rs %" PRId64 ".%02" PRId64 " (%" PRId64 " paise)\n",
           energy_paise / 100, energy_paise % 100, energy_paise);
    printf("  Fixed Monthly Charge:        Rs %" PRId64 ".%02" PRId64 " (%" PRId64 " paise)\n",
           tariff.fixed_charge_paise / 100, tariff.fixed_charge_paise % 100, tariff.fixed_charge_paise);
    printf("  Total Customer Bill:         Rs %" PRId64 ".%02" PRId64 "\n",
           total_paise / 100, total_paise % 100);
    return 0;
}
