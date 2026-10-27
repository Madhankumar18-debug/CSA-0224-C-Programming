# Complete Test Execution Records: CSA02 Assignment 1
**Student:** Madhankumar M (1924260007)  
**Compiler:** gcc.exe (tdm64-1) 4.9.2  
**Standard & Flags:** -std=c11 -Wall -Wextra -Wpedantic  
| Test ID | Test Scenario | Executable | Input Provided | Expected Exit | Actual Exit | Result |
|---|---|---|---|---|---|---|
| TC01 | Task 01 - Problem Understanding | Task01/main.exe | None | 0 | 0 | **PASS** |
| TC02 | Task 02 - Types & Precision | Task02/main.exe | None | 0 | 0 | **PASS** |
| TC03 | Task 03 - Constants & Slabs | Task03/main.exe | None | 0 | 0 | **PASS** |
| TC04 | Task 04 - Macros & Inlines | Task04/main.exe | None | 0 | 0 | **PASS** |
| TC05 | Task 05 - Release Build | Task05/main.exe | None | 0 | 0 | **PASS** |
| TC06 | Task 05 - Debug Build | Task05/main_debug.exe | None | 0 | 0 | **PASS** |
| TC07 | Task 06 - Valid Input | Task06/main.exe | '101 Domestic 1000 1150\n' | 0 | 0 | **PASS** |
| TC08 | Task 06 - Invalid Letters | Task06/main.exe | '101 Domestic abc 1150\n' | 1 | 1 | **PASS** |
| TC09 | Task 06 - Out of Range | Task06/main.exe | '101 Domestic 1000 70000\n' | 1 | 1 | **PASS** |
| TC10 | Task 07 - Precision Surprises | Task07/main.exe | None | 0 | 0 | **PASS** |
| TC11 | Task 08 - Pipeline Trace | Task08/billing.exe | None | 0 | 0 | **PASS** |
| TC12 | Task 09 - Valid 1000 & 1150 | Task09/main.exe | '1000\n1150\n' | 0 | 0 | **PASS** |
| TC13 | Task 09 - Boundary 0 Units | Task09/main.exe | '1000\n1000\n' | 0 | 0 | **PASS** |
| TC14 | Task 09 - Boundary 100 Units | Task09/main.exe | '1000\n1100\n' | 0 | 0 | **PASS** |
| TC15 | Task 09 - Boundary 200 Units | Task09/main.exe | '1000\n1200\n' | 0 | 0 | **PASS** |
| TC16 | Task 09 - Slab 3 350 Units | Task09/main.exe | '1000\n1350\n' | 0 | 0 | **PASS** |
| TC17 | Task 09 - Rollover 65535 to 0 | Task09/main.exe | '65535\n0\n' | 0 | 0 | **PASS** |
| TC18 | Task 09 - Rollover 65400 to 120 | Task09/main.exe | '65400\n120\n' | 0 | 0 | **PASS** |
| TC19 | Task 09 - Invalid Empty | Task09/main.exe | '\n' | 1 | 1 | **PASS** |
| TC20 | Task 09 - Invalid Letters | Task09/main.exe | 'abc\n' | 1 | 1 | **PASS** |
| TC21 | Task 09 - Invalid Negative | Task09/main.exe | '-5\n' | 1 | 1 | **PASS** |
| TC22 | Task 09 - Invalid >65535 | Task09/main.exe | '70000\n' | 1 | 1 | **PASS** |
| TC23 | Task 09 - Invalid Trailing | Task09/main.exe | '1000abc\n' | 1 | 1 | **PASS** |
| TC24 | Task 10 - Multi-Scale Aggregation | Task10/main.exe | None | 0 | 0 | **PASS** |
| TC25 | Task 11 - Production Architecture | Task11/main.exe | None | 0 | 0 | **PASS** |
| TC26 | Task 12 - Smart Meter TOD Challenge | Task12/main.exe | None | 0 | 0 | **PASS** |
---
## Detailed Terminal Execution Evidence
### TC01: Task 01 - Problem Understanding
- **Description:** Normal & rollover modulo-65536 arithmetic
- **Executable Path:** Task01/main.exe
- **Input Supplied:** None
- **Expected Exit Code:** 0 | **Observed Exit Code:** 0
- **Status:** **PASS**
```text
--- Task 01: Problem Understanding & 16-bit Rollover Demo ---
Normal reading: 1200 to 1530 -> 330 units
Rollover reading: 65400 to 120 -> 256 units
Boundary reading: 65535 to 0 -> 1 units
```
### TC02: Task 02 - Types & Precision
- **Description:** Completed starter code, type ranges, float error
- **Executable Path:** Task02/main.exe
- **Input Supplied:** None
- **Expected Exit Code:** 0 | **Observed Exit Code:** 0
- **Status:** **PASS**
```text
--- Part 1: Starter Code Rollover Demonstration ---
sizeof(meter_t) = 2 bytes, maximum reading = 65535
Consumption: 330 units
Consumption: 256 units
--- Part 2: System Data Type Sizes and Ranges ---
sizeof(char)      = 1 byte,  range = -128 to 127
sizeof(short)     = 2 bytes, range = -32768 to 32767
sizeof(int)       = 4 bytes, range = -2147483648 to 2147483647
sizeof(long)      = 4 bytes, range = -2147483648 to 2147483647
sizeof(long long) = 8 bytes, range = -9223372036854775808 to 9223372036854775807
sizeof(float)     = 4 bytes, precision digits = 6
sizeof(double)    = 8 bytes, precision digits = 15
--- Part 3: Float vs Integer-Paise Precision Test (4,000 bills) ---
Float accumulation total:   Rs 650000.0000
Integer paise exact total:  Rs 650000.00 (paise: 65000000)
```
### TC03: Task 03 - Constants & Slabs
- **Description:** Slab pricing verification (0, 100, 150, 200, 350)
- **Executable Path:** Task03/main.exe
- **Input Supplied:** None
- **Expected Exit Code:** 0 | **Observed Exit Code:** 0
- **Status:** **PASS**
```text
0 units -> Rs 50.00
100 units -> Rs 50.00
150 units -> Rs 162.50
200 units -> Rs 275.00
350 units -> Rs 950.00
```
### TC04: Task 04 - Macros & Inlines
- **Description:** Safe macros, SQUARE(a+1), MAX(i++, j) side-effects
- **Executable Path:** Task04/main.exe
- **Input Supplied:** None
- **Expected Exit Code:** 0 | **Observed Exit Code:** 0
- **Status:** **PASS**
```text
--- Task 04: Safe Macros vs Inline Functions ---
RUPEES_TO_PAISE(12) = 1200 paise
Parenthesisation comparison for a = 4:
  BAD_SQUARE(a + 1) = 9 (wrong: 4 + 1 * 4 + 1 = 9)
  SQUARE(a + 1)     = 25 (correct: (4 + 1) * (4 + 1) = 25)
Side-effect pitfall with MAX(i++, j) vs inline max_int(i++, j):
  MAX macro result = 6, i after macro = 7 (evaluated twice!)
  Inline max result= 5, i after inline = 6 (evaluated once)
Standard calls:
  MAX(a, b)        = 7
  inline square(5) = 25
  inline max(a, b) = 7
```
### TC05: Task 05 - Release Build
- **Description:** Modular release build without debug instrumentation
- **Executable Path:** Task05/main.exe
- **Input Supplied:** None
- **Expected Exit Code:** 0 | **Observed Exit Code:** 0
- **Status:** **PASS**
```text
--- Task 05: Multi-file Build & Conditional Debugging ---
Bill for   0 units: Rs 50.00
Bill for 100 units: Rs 50.00
Bill for 150 units: Rs 162.50
Bill for 200 units: Rs 275.00
Bill for 350 units: Rs 950.00
```
### TC06: Task 05 - Debug Build
- **Description:** Modular debug build with -DDEBUG stderr traces
- **Executable Path:** Task05/main_debug.exe
- **Input Supplied:** None
- **Expected Exit Code:** 0 | **Observed Exit Code:** 0
- **Status:** **PASS**
```text
--- Task 05: Multi-file Build & Conditional Debugging ---
Bill for   0 units: Rs 50.00
Bill for 100 units: Rs 50.00
Bill for 150 units: Rs 162.50
Bill for 200 units: Rs 275.00
Bill for 350 units: Rs 950.00
[STDERR]
[DEBUG] units=0 -> bill_paise=5000 (Rs 50.00)
[DEBUG] units=100 -> bill_paise=5000 (Rs 50.00)
[DEBUG] units=150 -> bill_paise=16250 (Rs 162.50)
[DEBUG] units=200 -> bill_paise=27500 (Rs 275.00)
[DEBUG] units=350 -> bill_paise=95000 (Rs 950.00)
```
### TC07: Task 06 - Valid Input
- **Description:** Valid input reading (150 units -> Rs 162.50)
- **Executable Path:** Task06/main.exe
- **Input Supplied:** '101 Domestic 1000 1150\n'
- **Expected Exit Code:** 0 | **Observed Exit Code:** 0
- **Status:** **PASS**
```text
Enter household number, category, previous reading, current reading: Household: 101 | Category: Domestic | Units: 150 | Bill: Rs 162.50
```
### TC08: Task 06 - Invalid Letters
- **Description:** Reject non-numeric characters
- **Executable Path:** Task06/main.exe
- **Input Supplied:** '101 Domestic abc 1150\n'
- **Expected Exit Code:** 1 | **Observed Exit Code:** 1
- **Status:** **PASS**
```text
Enter household number, category, previous reading, current reading:
[STDERR]
Invalid input. Expected: <int:household> <string:category> <int:prev> <int:curr>
```
### TC09: Task 06 - Out of Range
- **Description:** Reject reading > 65535
- **Executable Path:** Task06/main.exe
- **Input Supplied:** '101 Domestic 1000 70000\n'
- **Expected Exit Code:** 1 | **Observed Exit Code:** 1
- **Status:** **PASS**
```text
Enter household number, category, previous reading, current reading:
[STDERR]
Input out of allowed range (household > 0, readings in 0..65535).
```
### TC10: Task 07 - Precision Surprises
- **Description:** Integer division, float inexactness, cast truncation
- **Executable Path:** Task07/main.exe
- **Input Supplied:** None
- **Expected Exit Code:** 0 | **Observed Exit Code:** 0
- **Status:** **PASS**
```text
--- Task 07: Type Conversion, Division & Precision Demonstrations ---
[Surprise 1: Integer Division]
  Expression: 5 / 2 = 2 (expected 2.5, fraction discarded!)
  Fixed with cast: (double)5 / 2 = 2.50
[Surprise 2: Binary Floating-Point Inexactness]
  Expression: 0.1 + 0.2 = 0.30000000000000004
  Comparison (0.1 + 0.2 == 0.3): FALSE (differs at 17th decimal place!)
[Surprise 3: Double to Int Truncation]
  Expression: (int)3.99 = 3 (truncates towards zero, not rounded to 4!)
  Proper rounding: (int)(3.99 + 0.5) = 4
[Surprise 4: Narrowing Cast Overflow]
  Original int64 value: 3000000000
  Casting to 32-bit int: -1294967296 (overflow / sign change!)
[Resolution: Integer Paise Accounting]
  4,000 bills at 225 paise = 900000 paise (Rs 9000.00 exactly)
```
### TC11: Task 08 - Pipeline Trace
- **Description:** Trace compilation stages and error types
- **Executable Path:** Task08/billing.exe
- **Input Supplied:** None
- **Expected Exit Code:** 0 | **Observed Exit Code:** 0
- **Status:** **PASS**
```text
=== Grama Jyothi Electricity Billing System ===
Release: Version 1.0 (C11 Strict)
Compilation stages demonstrated:
  Stage 1 (Preprocessing): gcc -E main.c -o main.i
  Stage 2 (Compilation):   gcc -S main.c -o main.s
  Stage 3 (Assembly):      gcc -c main.c -o main.o
  Stage 4 (Linking):       gcc main.o -o billing.exe
```
### TC12: Task 09 - Valid 1000 & 1150
- **Description:** Accept 1000 and 1150 -> 150 units, Rs 162.50
- **Executable Path:** Task09/main.exe
- **Input Supplied:** '1000\n1150\n'
- **Expected Exit Code:** 0 | **Observed Exit Code:** 0
- **Status:** **PASS**
```text
Previous meter reading (0-65535): Current meter reading (0-65535): Units consumed: 150
Bill: Rs 162.50
```
### TC13: Task 09 - Boundary 0 Units
- **Description:** Zero consumption boundary -> Rs 50.00
- **Executable Path:** Task09/main.exe
- **Input Supplied:** '1000\n1000\n'
- **Expected Exit Code:** 0 | **Observed Exit Code:** 0
- **Status:** **PASS**
```text
Previous meter reading (0-65535): Current meter reading (0-65535): Units consumed: 0
Bill: Rs 50.00
```
### TC14: Task 09 - Boundary 100 Units
- **Description:** Slab 1 upper limit -> Rs 50.00
- **Executable Path:** Task09/main.exe
- **Input Supplied:** '1000\n1100\n'
- **Expected Exit Code:** 0 | **Observed Exit Code:** 0
- **Status:** **PASS**
```text
Previous meter reading (0-65535): Current meter reading (0-65535): Units consumed: 100
Bill: Rs 50.00
```
### TC15: Task 09 - Boundary 200 Units
- **Description:** Slab 2 upper limit -> Rs 275.00
- **Executable Path:** Task09/main.exe
- **Input Supplied:** '1000\n1200\n'
- **Expected Exit Code:** 0 | **Observed Exit Code:** 0
- **Status:** **PASS**
```text
Previous meter reading (0-65535): Current meter reading (0-65535): Units consumed: 200
Bill: Rs 275.00
```
### TC16: Task 09 - Slab 3 350 Units
- **Description:** Slab 3 rate test -> Rs 950.00
- **Executable Path:** Task09/main.exe
- **Input Supplied:** '1000\n1350\n'
- **Expected Exit Code:** 0 | **Observed Exit Code:** 0
- **Status:** **PASS**
```text
Previous meter reading (0-65535): Current meter reading (0-65535): Units consumed: 350
Bill: Rs 950.00
```
### TC17: Task 09 - Rollover 65535 to 0
- **Description:** Register boundary rollover -> 1 unit, Rs 50.00
- **Executable Path:** Task09/main.exe
- **Input Supplied:** '65535\n0\n'
- **Expected Exit Code:** 0 | **Observed Exit Code:** 0
- **Status:** **PASS**
```text
Previous meter reading (0-65535): Current meter reading (0-65535): Units consumed: 1
Bill: Rs 50.00
```
### TC18: Task 09 - Rollover 65400 to 120
- **Description:** Multi-unit rollover -> 256 units, Rs 527.00
- **Executable Path:** Task09/main.exe
- **Input Supplied:** '65400\n120\n'
- **Expected Exit Code:** 0 | **Observed Exit Code:** 0
- **Status:** **PASS**
```text
Previous meter reading (0-65535): Current meter reading (0-65535): Units consumed: 256
Bill: Rs 527.00
```
### TC19: Task 09 - Invalid Empty
- **Description:** Empty line rejection
- **Executable Path:** Task09/main.exe
- **Input Supplied:** '\n'
- **Expected Exit Code:** 1 | **Observed Exit Code:** 1
- **Status:** **PASS**
```text
Previous meter reading (0-65535):
[STDERR]
Invalid previous reading.
```
### TC20: Task 09 - Invalid Letters
- **Description:** Non-numeric input rejection
- **Executable Path:** Task09/main.exe
- **Input Supplied:** 'abc\n'
- **Expected Exit Code:** 1 | **Observed Exit Code:** 1
- **Status:** **PASS**
```text
Previous meter reading (0-65535):
[STDERR]
Invalid previous reading.
```
### TC21: Task 09 - Invalid Negative
- **Description:** Negative reading rejection
- **Executable Path:** Task09/main.exe
- **Input Supplied:** '-5\n'
- **Expected Exit Code:** 1 | **Observed Exit Code:** 1
- **Status:** **PASS**
```text
Previous meter reading (0-65535):
[STDERR]
Invalid previous reading.
```
### TC22: Task 09 - Invalid >65535
- **Description:** Reading above register limit rejection
- **Executable Path:** Task09/main.exe
- **Input Supplied:** '70000\n'
- **Expected Exit Code:** 1 | **Observed Exit Code:** 1
- **Status:** **PASS**
```text
Previous meter reading (0-65535):
[STDERR]
Invalid previous reading.
```
### TC23: Task 09 - Invalid Trailing
- **Description:** Trailing non-whitespace rejection
- **Executable Path:** Task09/main.exe
- **Input Supplied:** '1000abc\n'
- **Expected Exit Code:** 1 | **Observed Exit Code:** 1
- **Status:** **PASS**
```text
Previous meter reading (0-65535):
[STDERR]
Invalid previous reading.
```
### TC24: Task 10 - Multi-Scale Aggregation
- **Description:** 4,000 / 60,000 / 800,000 bills & 32-bit overflow
- **Executable Path:** Task10/main.exe
- **Input Supplied:** None
- **Expected Exit Code:** 0 | **Observed Exit Code:** 0
- **Status:** **PASS**
```text
--- Task 10: Billing Scale Comparison (Paise vs Float) ---
Scale: Village (4,000)
  Integer Paise Total: 65000000 paise -> Rs 650000.00
  Float Accumulated:   Rs 650000.0000
  Difference:          Rs 0.0000
  32-bit int overflow: NO (Total paise 65000000 <= INT_MAX 2147483647)
Scale: Taluk (60,000)
  Integer Paise Total: 975000000 paise -> Rs 9750000.00
  Float Accumulated:   Rs 9745812.0000
  Difference:          Rs -4188.0000
  32-bit int overflow: NO (Total paise 975000000 <= INT_MAX 2147483647)
Scale: District (800,000)
  Integer Paise Total: 13000000000 paise -> Rs 130000000.00
  Float Accumulated:   Rs 129258144.0000
  Difference:          Rs -741856.0000
  32-bit int overflow: YES (OVERFLOWS!) (Total paise 13000000000 > INT_MAX 2147483647)
--- System Data Type Sizes (Platform vs Minimum C Standard) ---
sizeof(int)       = 4 bytes (C standard minimum: 2 bytes)
sizeof(long)      = 4 bytes (C standard minimum: 4 bytes)
sizeof(long long) = 8 bytes (C standard minimum: 8 bytes)
```
### TC25: Task 11 - Production Architecture
- **Description:** 64-bit integer paise architecture & district revenue
- **Executable Path:** Task11/main.exe
- **Input Supplied:** None
- **Expected Exit Code:** 0 | **Observed Exit Code:** 0
- **Status:** **PASS**
```text
--- Task 11: Recommended Production Billing Architecture ---
Units:   0 -> Bill: Rs 50.00 (5000 paise)
Units: 100 -> Bill: Rs 50.00 (5000 paise)
Units: 150 -> Bill: Rs 162.50 (16250 paise)
Units: 200 -> Bill: Rs 275.00 (27500 paise)
Units: 350 -> Bill: Rs 950.00 (95000 paise)
District Scale Simulation (800,000 households @ 350 units):
  Single bill (350 units): Rs 950.00
  District total:          Rs 760000000.00 (76000000000 paise)
  Data type: int64_t guarantees zero overflow (Capacity: ~9.22 x 10^18 paise)
```
### TC26: Task 12 - Smart Meter TOD Challenge
- **Description:** 15-min Wh intervals, 20% peak rate, tariff.cfg
- **Executable Path:** Task12/main.exe
- **Input Supplied:** None
- **Expected Exit Code:** 0 | **Observed Exit Code:** 0
- **Status:** **PASS**
```text
--- Task 12: Day-4 Design Challenge (Smart Meter TOD Billing) ---
Tariff Loaded from tariff.cfg:
  Fixed Charge:      Rs 50.00 (5000 paise)
  Normal Rate:       Rs 2.25/kWh (225 paise/kWh)
  Peak Surcharge:    20% (Active 18:00 to 22:00)
Processing demonstration intervals:
  Interval 1: 10:00 (Off-Peak) | 500 Wh -> 112500000 micro-paise (112.5000 paise)
  Interval 2: 19:00 (Peak +20%) | 750 Wh -> 202500000 micro-paise (202.5000 paise)
  Interval 3: 21:00 (Peak +20%) | 1000 Wh -> 270000000 micro-paise (270.0000 paise)
  Interval 4: 23:00 (Off-Peak) | 250 Wh -> 56250000 micro-paise (56.2500 paise)
Billing Summary:
  Intervals processed:         4
  Annual intervals per meter:  35040
  Accumulated Energy Charge:   Rs 6.41 (641 paise)
  Fixed Monthly Charge:        Rs 50.00 (5000 paise)
  Total Customer Bill:         Rs 56.41
```