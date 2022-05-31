#include <stdio.h>
#include <stdlib.h>
/// Zusätzliche Header-Dateien hier!
#include <unistd.h>

#include "vorgabe.h"

void *work(void *arg) {
    int my_num = *((int *)arg);

    printf("[BT %d] Ich bin bereit zu arbeiten!\n", my_num);

    for (int _ = 0; _ < RECIPES_PER_BARTENDER; _++) {
        ingredient_t *ingred[RECIPE_SIZE];
        get_recipe(ingred);

        for (int i = 0; i < INGREDIENTS_NUM; i++) {
            // Eine Flasche holen
            ingredient_t ing = ingredients[i];
            // Spirituose verarbeiten
            sleep(ing.time_needed);
        }
    }

    return NULL;
}
