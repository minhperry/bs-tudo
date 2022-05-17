#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int ANZ_GAESTE = 64;
int ANZ_SERVICEK = 15;
int ANZ_UMRUEHREN = 5;
int TROEDEL_DAUER = 100000;

/// Verbraucht ein bisschen Zeit
void troedeln() {
    for (int i = 0; i < TROEDEL_DAUER; ++i) {
    }
}

/// Kocht für den gegebenen Gast.
void kochen(int gast) {
    printf("Koche fuer Gast: ");
    for (int i = 0; i < ANZ_UMRUEHREN; ++i) {
        printf("%4d ", gast);
    }
    printf("\nSuppe fertig!\n");
}

/// Auftragsbeschreibung für einen Servicekraft
struct zu_bedienen {
    int erster_gast;
    int bis_gast;
};

/// Auftragsbeschreibung für Servicekraft mit Nummer `servicek` erstellen.
struct zu_bedienen bedienliste_fuer(int servicek) {
    int todo = (ANZ_GAESTE / ANZ_SERVICEK);
    struct zu_bedienen result;
    result.erster_gast = servicek * todo;
    result.bis_gast = servicek * todo + todo;
    if (servicek == ANZ_SERVICEK - 1) {
        result.bis_gast = ANZ_GAESTE;
    }
    return result;
}

/// Routine für einen Servicekraft
void *bedienen(void *arg) {
    troedeln();
    struct zu_bedienen *gaeste = (struct zu_bedienen *)(arg);
    for (int i = gaeste->erster_gast; i < gaeste->bis_gast; ++i) {
        kochen(i);
    }
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    /// Ab hier Code ergänzen

    struct zu_bedienen zubedienen[ANZ_SERVICEK];

    pthread_t tid[ANZ_GAESTE];

    for (int i = 0; i < ANZ_SERVICEK; i++) {
        zubedienen[i] = bedienliste_fuer(i);
        pthread_create(&tid[i], NULL, bedienen, &zubedienen[i]);
    }

    for (int i = 0; i < ANZ_SERVICEK; i++) {
        pthread_join(tid[i], NULL);
    }

    return EXIT_SUCCESS;
}
