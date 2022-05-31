#ifndef __VORGABE_H__
	/**
 	 * DIESE DATEI NICHT BEARBEITEN!
 	 */
	#define __VORGABE_H__

	#include <semaphore.h>

	#define INGREDIENTS_NUM 5			/// Anzahl der verschiedenen Spirituosen.
	#define BARTENDER_NUM 6				/// Anzahl der Bartender.
	#define RECIPES_PER_BARTENDER 2		/// Anzahl der Rezeptkreationen, die ein Bartender mischt, bevor er sich beendet.
	#define RECIPE_SIZE 4				/// Anzahl der Spirituosen einer Rezeptkreation.

	typedef struct ingredient {			/// Definiere Struktur für Spirituose mit "ingredient_t" als Alias.
		char name[256];					/// Der Name dieser Spirituosen.
		int time_needed;				/// Die Zeit in Sekunden, die zur Verarbeitung dieser Spirituosen benötigt wird.
		int bottles;					/// Die initiale Anzahl der vorhandenen Flaschen dieser Spirituosen.
		sem_t sem;						/// Die noch verfügbare Flaschenzahl als Semaphore.
	} ingredient_t;

	/// Vorgegebene Spirituosen
	extern ingredient_t ingredients[INGREDIENTS_NUM];

	/// Funktion, die ein zufälliges Rezept generiert und  
	/// im als Argument angegebenen Array speichert 
	/// (d.h. von euch mit der richtigen Länge anzulegenden!)
	void get_recipe(ingredient_t * recipe_buffer[]);

	extern pthread_mutex_t lock;
	extern int restart;
	extern pthread_t bartenders[BARTENDER_NUM];

	/// a3_a.c

	void init_semaphores();
	void destroy_semaphores();

	/// a3_b.c / a3_c.c / a3_d.c

	void *work(void *arg);

#endif
