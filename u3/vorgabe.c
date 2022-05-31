/**
 * DIESE DATEI NICHT BEARBEITEN!
 */
#include <time.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "vorgabe.h"
pthread_mutex_t lock;
int restart;
pthread_t bartenders[BARTENDER_NUM];

ingredient_t ingredients[INGREDIENTS_NUM] = { 
	{"Whiskey", 3, 3, {{0}}},
	{"Vodka", 2, 2, {{0}}},
	{"Rum", 2, 2, {{0}}},
    {"Wein", 4, 2, {{0}}},
	{"Cola", 1, 4, {{0}}} 
};

/// Funktion, die ein zufälliges Rezept generiert und  
/// im als Argument angegebenen Array speichert
/// (d.h. von euch mit der richtigen Länge anzulegenden!)
void get_recipe(ingredient_t * recipe_buffer[]) {
	
	ingredient_t *ingredients_left[INGREDIENTS_NUM];

	for (int i = 0; i < INGREDIENTS_NUM; i++) {
		ingredients_left[i] = &(ingredients[i]);
	}

	for (int i = 0; i < RECIPE_SIZE; i++) {
		int rand_index = rand() % (INGREDIENTS_NUM - i);
		recipe_buffer[i] = ingredients_left[rand_index];
		for (int j = rand_index; j < INGREDIENTS_NUM - i - 1; j++) {
			ingredients_left[j] = ingredients_left[j + 1];
		}
	}
}

int main() {
	srand(time(NULL));	/// Zufallszahlengenerator initialisieren

	restart = 1;

	while (restart) {
		restart = 0;

		pthread_mutex_init(&lock, NULL);

		printf("[ ! ] Semaphoren initialisieren...\n");
		init_semaphores();
		printf("[ ! ] Semaphoren initialisiert.\n");

		/// Nummernvariablen zur Übergabe an die Threads anlegen
		int bartender_nums[BARTENDER_NUM];
		for (int i = 0; i < BARTENDER_NUM; i++) {
			bartender_nums[i] = i;
		}

		/// Bartender-Threads anlegen
		for (int i = 0; i < BARTENDER_NUM; i++) {
			if (pthread_create(&bartenders[i], NULL, &work, &(bartender_nums[i]))) {
				perror("pthread_create");
				exit(1);
			}
		}

		/// Bartender-Threads einsammeln
		for (int i = 0; i < BARTENDER_NUM; i++) {
			if (pthread_join(bartenders[i], NULL)) {
				perror("pthread_join");
				exit(1);
			}
		}

		printf("[ ! ] Alle Bartender beendet.\n");

		if (pthread_mutex_destroy(&lock)) {
			perror("pthread_mutex_destroy");
			exit(1);
		}

		printf("[ ! ] Semaphoren zerstören...\n");
		destroy_semaphores();
		printf("[ ! ] Semaphoren zerstört.\n");
	}

	printf("[!!!] Beende Programm.\n");

	return 0;
}
