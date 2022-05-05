#include <stdio.h>
#include <stdlib.h>
// Zur Nutzung von atoi()

int getFibo(int n) {
    if ((n == 2) || (n == 1)) {
        return 1;
    } else {
        return getFibo(n - 2) + getFibo(n - 1);
    }
}

int main(int argc, char** argv) {
    if (argc == 1) {
        printf("Fehler: Keine Obergrenze angegeben\n");
    } else if (argc > 2) {
        printf("Fehler: Zu viel Argumenten angegeben\n");
    } else {
        // atoi = ascii to int
        int n = atoi(argv[1]);
        if (n < 0) {
            printf("Fehler: Negative Zahl als Obergrenze angegeben\n");
        } else if (n == 0) {
            printf("Fehler: 0. Zahl existiert nicht oder kein Zahl angegeben\n");
        } else {
            printf("Die %d. Fibonacci-Zahl lautet: %d\n", n, getFibo(n));
        }
    }
}
