#include "4a.h"

#include <stdio.h>  /* für NULL */
#include <stdlib.h> /* für exit(int) */

#include "bst.h"

void buddy_free(void *addr) {
    // Diese Funktion sollt ihr implementieren
    if (addr == NULL) {
        exit(0);
    }
    // Wie viel Blöcke ist vor addr?
    int nodepos = size_to_chunks(addr);

    // Mit 0-Indexing, dann wird k-th Block äquivalent zu 2^(n-1)+k-te Knoten im BST
    // also wird die Anzahl der Blöcke vor dem Addresse gleich Index - 1
    int nodeindex = (1 << (BUDDY_LEVEL - 1)) + nodepos - 1;

    node_t node = bst_root();

    set_node_content(&(node[nodeindex]), NODE_FREE);
    if (node_start_addr(node) != addr) {
        perror("Startadresse ist nicht in einem belegten Speicherbereich!");
        exit(255);
    }
    // Aufrechterhaltung der Invariante (vereinige Buddies, wo nötig)
    bst_housekeeping(bst_root());
}
