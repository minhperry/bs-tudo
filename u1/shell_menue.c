#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    // Wählbare Optionen
    int maxsize = 4;
    char *opt[10];

    opt[0] = "-l";
    opt[1] = "-a";
    opt[2] = "-t";
    opt[3] = "exit";

restart:
    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, opt[i]);
    }

    // Eingabe lesen
    printf("Auswahl: ");
    int eing;

    if (scanf("%d", &eing) < 1) {
        printf("Ungültige Eingabe!\n");
        return 1;
    }

    // Eingabe checken
    if (eing <= 0 || eing > maxsize) {
        printf("Eingabe zu groß oder zu klein!\n");
        return 1;
    }
    printf("Es wurde %s gewählt.\n", opt[eing - 1]);

    if (eing == 4) {
        return 0;
    }

    // das beliebig fork-exec-wait Schema
    pid_t pid = fork();
    if (pid < 0) {
        return 1;
    } else if (pid > 0) {
        int s;
        waitpid(pid, &s, 0);
        printf("PID von pwd: %d.\n", pid);
        printf("Eingabe %d\n", eing);
        goto restart;
        return 0;
    } else {
        execlp("ls", "ls", opt[eing - 1], 0);
    }

    return 0;
}