#include <stdio.h>
#include <stdlib.h>
/// Zusätzliche Header-Dateien hier!
#include <semaphore.h>

#include "vorgabe.h"

void init_semaphores() {
    // Für jede Flasche ein Semaphor intialisieren
    for (int i = 0; i < INGREDIENTS_NUM; i++) {
        sem_init(&ingredients[i].sem, 0, 1);
    }
}

void destroy_semaphores() {
    // Für jede Flasche ihr Semaphor entfernen
    for (int i = 0; i < INGREDIENTS_NUM; i++) {
        sem_destroy(&ingredients[i].sem);
    }
}
