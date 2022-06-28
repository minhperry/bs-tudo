#include "4b.h"

#include <stdio.h>  /* für NULL */
#include <stdlib.h> /* für exit(int) */

static void *recursive_alloc(node_t node, char request_id, size_t size) {
    // Diese rekrusive Funktion könnt ihr als Hilfsfunktion implementieren
}

void *buddy_alloc(char request_id, size_t size) {
    if (size == 0) {
        return NULL;
    }
}
