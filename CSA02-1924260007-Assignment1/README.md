# CSA02 C Programming Assignment 1: Rural Electricity Billing System

**Student Name:** Madhankumar M  
**Register Number:** 1924260007  
**Course:** CSA02 – C Programming (CO1 Assessment 1)  
**Institution:** SIMATS Engineering  
**Compiler:** GCC 4.9.2 (`gcc.exe (tdm64-1) 4.9.2` on Windows x86_64-w64-mingw32)  
**Standard & Flags:** `-std=c11 -Wall -Wextra -Wpedantic`  

---

## 1. Compiler Environment Verification

To verify the installed compiler environment on Windows:
```powershell
gcc --version
```
Expected output:
```text
gcc.exe (tdm64-1) 4.9.2
Copyright (C) 2014 Free Software Foundation, Inc.
```

### Windows MinGW Format-String Architecture Note
Under MinGW / TDM-GCC on Windows, GCC defaults to Microsoft's legacy C runtime (`msvcrt.dll`), which does not support C99/C11 format specifiers (`%zu`, `%lld`, `inttypes.h` macros like `PRId64` / `SCNd64`) without emitting compiler warnings under strict `-std=c11 -Wall -Wextra -Wpedantic`.  
To resolve this cleanly and portably without suppressing compiler warnings, every source file defines:
```c
#define __USE_MINGW_ANSI_STDIO 1
```
before including `<stdio.h>`. This instructs MinGW to link against compliant ANSI/ISO C99/C11 stdio routines, guaranteeing zero warnings and exact 64-bit I/O formatting.

---

## 2. Compilation and Execution Guide

All tasks are strictly compliant with ISO C11 and compile with **0 errors and 0 warnings** under `gcc -std=c11 -Wall -Wextra -Wpedantic`.

### Task 01: Problem Understanding & Rollover Arithmetic
```powershell
gcc -std=c11 -Wall -Wextra -Wpedantic Task01/main.c -o Task01/main.exe
.\Task01\main.exe
```

### Task 02: Data Types, Sizes, Ranges & Precision
```powershell
gcc -std=c11 -Wall -Wextra -Wpedantic Task02/main.c -o Task02/main.exe
.\Task02\main.exe
```

### Task 03: Tariff Constants & Slab Billing
```powershell
gcc -std=c11 -Wall -Wextra -Wpedantic Task03/main.c -o Task03/main.exe
.\Task03\main.exe
```

### Task 04: Safe Preprocessor Macros & Inline Functions
```powershell
gcc -std=c11 -Wall -Wextra -Wpedantic Task04/main.c -o Task04/main.exe
gcc -E Task04/main.c -o Task04/main.i
.\Task04\main.exe
```

### Task 05: Modular Architecture & Conditional Debug Mode
Normal build:
```powershell
gcc -std=c11 -Wall -Wextra -Wpedantic Task05/main.c Task05/tariff.c -o Task05/main.exe
.\Task05\main.exe
```
Debug build (activates `[DEBUG]` instrumentation via `-DDEBUG`):
```powershell
gcc -std=c11 -Wall -Wextra -Wpedantic -DDEBUG Task05/main.c Task05/tariff.c -o Task05/main_debug.exe
.\Task05\main_debug.exe
```

### Task 06: Formatted Input & Validation
```powershell
gcc -std=c11 -Wall -Wextra -Wpedantic Task06/main.c -o Task06/main.exe
.\Task06\main.exe
# Sample input: 101 Domestic 1000 1150
```

### Task 07: Type Conversion, Division & Precision
```powershell
gcc -std=c11 -Wall -Wextra -Wpedantic Task07/main.c -o Task07/main.exe
.\Task07\main.exe
```

### Task 08: Compilation Pipeline Stages
```powershell
gcc -std=c11 -Wall -Wextra -Wpedantic -E Task08/main.c -o Task08/main.i
gcc -std=c11 -Wall -Wextra -Wpedantic -S Task08/main.c -o Task08/main.s
gcc -std=c11 -Wall -Wextra -Wpedantic -c Task08/main.c -o Task08/main.o
gcc Task08/main.o -o Task08/billing.exe
gcc -std=c11 -Wall -Wextra -Wpedantic Task08/main.c -o Task08/main.exe
.\Task08\billing.exe
```

### Task 09: Full Billing Implementation & Rigorous Validation
```powershell
gcc -std=c11 -Wall -Wextra -Wpedantic Task09/main.c -o Task09/main.exe
.\Task09\main.exe
# Sample test: Previous = 1000, Current = 1150 -> Units = 150, Bill = Rs 162.50
```

### Task 10: Multi-Scale Aggregation (Village, Taluk, District)
```powershell
gcc -std=c11 -Wall -Wextra -Wpedantic Task10/main.c -o Task10/main.exe
.\Task10\main.exe
```

### Task 11: Recommended Production Architecture
```powershell
gcc -std=c11 -Wall -Wextra -Wpedantic Task11/main.c -o Task11/main.exe
.\Task11\main.exe
```

### Task 12: Day-4 Design Challenge (Smart Meter TOD Billing)
*Note: Run from within the `Task12` folder so that `tariff.cfg` is read properly.*
```powershell
gcc -std=c11 -Wall -Wextra -Wpedantic Task12/main.c -o Task12/main.exe
cd Task12
.\main.exe
cd ..
```

---

## 3. Task Overview and Summary

| Task | Title | Bloom Level | Summary |
|---|---|---|---|
| **Task 01** | Problem Understanding | K4 (Analyse) | Defines problem inputs/outputs, business invariants, and demonstrates unsigned 16-bit register rollover modulo 65536. |
| **Task 02** | Data Types & Ranges | K4 (Analyse) | Analyzes C types, `sizeof`, ranges from `limits.h`, completes starter code, and demonstrates float error vs integer paise. |
| **Task 03** | Constants Definition | K3 (Apply) | Implements modular tariff macros and slab calculation; verifies one-point revision when `RATE2_PAISE` changes. |
| **Task 04** | Macro Safety | K4 (Analyse) | Analyzes macro expansion, parentheses pitfalls in `SQUARE(a+1)`, double evaluation in `MAX(i++, j)`, and inline functions. |
| **Task 05** | Header Files & Debug | K3 (Apply) | Implements separate compilation (`billing.h`, `tariff.c`, `main.c`) with include guards and zero-overhead `#ifdef DEBUG`. |
| **Task 06** | Formatted I/O & Validation | K3 (Apply) | Reads and validates structured input (`scanf` return value, positive IDs, 16-bit readings) and prints rupee/paise amounts. |
| **Task 07** | Type Conversion & Precision | K4 (Analyse) | Demonstrates 4 type-conversion surprises (integer division, binary float inaccuracy, cast truncation, narrowing overflow). |
| **Task 08** | Compilation Stages | K3 (Apply) | Traces `-E`, `-S`, `-c`, and linking; classifies compile-time, link-time, and runtime errors with fixes. |
| **Task 09** | Full Billing Implementation | K3 (Apply) | Complete, bulletproof billing engine accepting readings 1000 and 1150; validates whitespace, letters, negatives, and rollover. |
| **Task 10** | Expectation vs Execution | K4 (Analyse) | Evaluates scaling across 4,000, 60,000, and 800,000 households; measures 32-bit `int` overflow and float losses. |
| **Task 11** | Final Architecture Defence | K5 (Evaluate) | Recommends `uint16_t` meter registers, `uint32_t` units, `int64_t` paise, and centralized tariff constants. |
| **Task 12** | Day-4 Design Challenge | K5 (Evaluate) | Adapts system for smart meters: 15-minute Wh intervals (35,040/year), Time-of-Day 20% peak surcharge, and runtime `tariff.cfg`. |

---

## 4. How to Capture Genuine Terminal Screenshots on Windows

To capture genuine terminal output screenshots for university assessment:
1. Open PowerShell or Command Prompt.
2. Compile and run the task using the commands above.
3. Press **Win + Shift + S** to open the Windows Snipping Tool overlay.
4. Select the terminal window showing the compile command, execution command, and program output.
5. Save the captured screenshot directly into the task folder as `TaskXX/output.png` (e.g. `Task01/output.png`, `Task02/output.png`, etc.).

---

## 5. Progressive Git Commit History

To maintain a clean, progressive repository history conforming to the assignment rubric:
```powershell
git init
git config user.name "Madhankumar M"
git config user.email "1924260007@saveetha.com"

git add Task01/ && git commit -m "Complete Task 01: Problem analysis and 16-bit meter rollover arithmetic"
git add Task02/ && git commit -m "Complete Task 02: Data types, limits, completed starter code, and float error demo"
git add Task03/ && git commit -m "Complete Task 03: Tariff constants, completed compute_bill starter code, and slab testing"
git add Task04/ && git commit -m "Complete Task 04: Safe parenthesised macros, side-effect pitfall demo, and inline functions"
git add Task05/ && git commit -m "Complete Task 05: Multi-file program structure, include guards, and conditional DEBUG mode"
git add Task06/ && git commit -m "Complete Task 06: Formatted input validation with scanf and rupee-paise formatting"
git add Task07/ && git commit -m "Complete Task 07: Type conversion analysis, 4 surprise demonstrations, and integer paise accounting"
git add Task08/ && git commit -m "Complete Task 08: Full 4-stage compilation pipeline trace and error classification"
git add Task09/ && git commit -m "Complete Task 09: Bulletproof billing engine with whitespace-safe input validation and tests"
git add Task10/ && git commit -m "Complete Task 10: Multi-scale execution comparison and 32-bit overflow analysis"
git add Task11/ && git commit -m "Complete Task 11: Final architectural recommendation and district scalability defence"
git add Task12/ && git commit -m "Complete Task 12: Smart-meter ToD billing design challenge with runtime tariff configuration"
git add README.md REPORT_TEMPLATE.md && git commit -m "Complete Assignment 1 documentation, test records, and comprehensive report"
```
