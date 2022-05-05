#include <stdio.h>
#include <time.h>

// globale Variablen
int globalInit = 500;
int globalUninit;

int getFibo(int n) {
    // n ist auch als lokale Variable betrachtet
    printf("Adresse von n = %d ist %p\n", n, &n);

    // Haltbedingung: fib1 = fib2 = 1
    if ((n == 2) || (n == 1)) {
        return 1;
    } else {
        // fib n = fib n-2 + fib n-1
        return getFibo(n - 2) + getFibo(n - 1);
    }
}

int main(void) {
    // Variablen mit versch. Datentypen
    int intNr = 4;
    double doubleNr = 20.0;

    // Zeit messen
    time_t begin = time(NULL);
    printf("Die %d. Fibonacci-Zahl lautet: %d\n", intNr, getFibo(intNr));
    time_t end = time(NULL);
    printf("Dauer: %d\n", (end - begin));

    // Ausgabe von Adressen
    printf("Adresse von globalInit ist %p\n", &globalInit);
    printf("Adresse von globalUninit ist %p\n", &globalUninit);
    printf("Adresse von intNr ist %p\n", &intNr);
    printf("Adresse von doubleNr ist %p\n", &doubleNr);

    return 0;
}
