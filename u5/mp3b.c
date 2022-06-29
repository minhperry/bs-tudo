#include "mp3.h"

void idTagDir(const char *dirName, char *comment) {
    // Unterverzeichnisse sollen nicht gesucht werden

    /* HIER MUESST IHR EUREN CODE EINFUEGEN */
    int isFile = 0;  // 0 = Dir, 1 = File
    struct stat stb;
    if (stat(dirName, &stb) != -1) {
        if (S_ISREG(stb.st_mode) != 0) {
            isFile = 1;
        }
    }

    if (!strncmp(".", dirName, 2) || !strncmp("..", dirName, 3))
        return;

    if (isFile != 0) {
        printf("%s: Ist kein Verzeichnis\n", dirName);
        return;
    }

    DIR *dir;
    struct dirent *ent;

    dir = opendir(dirName);
    if (dir == NULL) {
        puts("Verzeichnis exsitiert nicht!");
        return;
    }

    printf("%s: Betrete Verzeichnis ...\n", dirName);
    chdir(dirName);
    char *name;
    while ((ent = readdir(dir)) != NULL) {
        name = ent->d_name;
        // printf("%s\n", name);
        if (!strncmp(name + strlen(name) - 4, ".mp3", 4)) {
            // printf("Datei: %s\n", name);
            idTagFile(name, NULL);
        }
    }

    printf("%s: Verlasse Verzeichnis ...\n", dirName);
    chdir("..");
    closedir(dir);
}
