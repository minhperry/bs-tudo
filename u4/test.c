#include <stdio.h>  /* für NULL */
#include <stdlib.h> /* für exit(int) */

#include "bst.h"

static inline unsigned int int_pow2(unsigned int x) {
    return 1 << x;
}

// Hilfsfunktion, entspricht floor(log2(x)) aus math.h für Ganzzahlen
static inline unsigned int int_log2(unsigned int x) {
    /* Sehr effizient, aber weniger portabel: */
    // return 31 - __builtin_clz(x);

    /* von uns genutzte portable Methode: */
    unsigned int log = 0;
    while (x >>= 1)
        log++;
    return log;
}

int main() {
    for (int i = 1; i <= 8; i++) {
        printf("log 2 of %d = %d  ", i, int_log2(i));
        printf("2^%d = %d\n", i, int_pow2(i));
    }
}