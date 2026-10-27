#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>

/*
 * Task 08: Trace the Compilation Process
 * Demonstrates the 4 stages of C translation:
 *   1. Preprocessing (gcc -E main.c -o main.i) -> Macro expansion, header inclusion, comment removal
 *   2. Compilation   (gcc -S main.i -o main.s) -> Translates C to assembly language
 *   3. Assembly      (gcc -c main.s -o main.o) -> Converts assembly to machine code (object file)
 *   4. Linking       (gcc main.o -o billing)   -> Resolves symbols with C runtime libraries
 */

#define SYSTEM_NAME "Grama Jyothi Electricity Billing System"
#define VERSION_TEXT "Version 1.0 (C11 Strict)"

int main(void) {
    printf("=== %s ===\n", SYSTEM_NAME);
    printf("Release: %s\n\n", VERSION_TEXT);
    printf("Compilation stages demonstrated:\n");
    printf("  Stage 1 (Preprocessing): gcc -E main.c -o main.i\n");
    printf("  Stage 2 (Compilation):   gcc -S main.c -o main.s\n");
    printf("  Stage 3 (Assembly):      gcc -c main.c -o main.o\n");
    printf("  Stage 4 (Linking):       gcc main.o -o billing.exe\n");
    return 0;
}
