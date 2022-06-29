#include "mp3.h"

void idTagFile(const char *fileName, char *comment) {
    /* HIER MUESST IHR EUREN CODE EINFUEGEN */
    // 5a.1
    int isFile = 0;  // 0 = Verzeichnis, 1 = Datei

    struct stat stb;
    // stat() Rückgabewert = -1 falls Fehler, 0 sonst
    if (stat(fileName, &stb) != -1) {
        if (S_ISREG(stb.st_mode) != 0) {
            isFile = 1;
            // printf("This is a file\n");
        } else {
            /*
            printf("%s: ist ein Verzeichnis\n", fileName);
            return;
            */
            idTagDir(fileName, NULL);
        }
    }

    // strncmp(str1, str2, n) -> Compares the first n char of str1 and str2
    if (!strncmp(".", fileName, 2) || !strncmp("..", fileName, 3))
        return;

    /* HIER MUESST IHR EUREN CODE EINFUEGEN */
    // 5a.2
    FILE *file;
    // Nur wenn die Name ein File ist können wir checken ob es ein MP3 ist
    if (isFile == 1) {
        if (strncmp(fileName + strlen(fileName) - 4, ".mp3", 4)) {
            printf("%s: ausgelassen\n", fileName);
            return;
        }
    }
    // rb = read binary, r = read -> meistens für Textdatei
    file = fopen(fileName, "rb");
    // NULL falls die Datei nicht exisitert
    if (file == NULL) {
        printf("%s: nicht existierend Datei\n", fileName);
        return;
    }

    /* Hier ist ein kleiner Codeschnipsel, den ihr in euren Code einbauen sollt,		*
     * um an geeigneter Stelle zu ueberpruefen, ob es sich um eine MP3-Datei handelt. 	*
     *											*
     *	if (strncmp(fileName + strlen(fileName) - 4, ".mp3", 4)) {			*
     *		printf("%s: ausgelassen\n", fileName);					*
     *		return;									*
     *	}										*
     *											*/

    /* HIER MUESST IHR EUREN CODE EINFUEGEN */
    // 5a.3
    char buffer[ID3_SIZE];
    // Bringt dem Lesezeiger zum Ende mit Offset -128 (also zuerst EOF und danach -128 Bytes nach rechts bzw 128 nach links)
    fseek(file, -ID3_SIZE, SEEK_END);
    // Falls nicht genau 128 Bytes abgelesen werden dann brecht es ab
    if (fread(buffer, 1, ID3_SIZE, file) != ID3_SIZE) {
        fclose(file);
        return;
    }
    printTag(bytesToIdTag(buffer));
    fclose(file);
}

struct mp3file data;
/* Die Informationen im Puffer, auf den buffer verweist, *
 * wird in einem struct abgelegt.			 */
struct mp3file *bytesToIdTag(char *buffer) {
    /* HIER MUESST IHR EUREN CODE EINFUEGEN */
    // 5a.4
    /*
        Source: https://id3.org/ID3v1

        MP3 ID3 Tag 1.0 -- 128 bytes
        (c) 1996, 1997 NamkraD (Eric Kemp)
        Seek end of file, then -128, if first 3 bytes='TAG' then it has info layed out as follows...

        0..2 == 'TAG' (3 Bytes)
        3..32 == Song Name (30 bytes)
        33..62 == Artist (30 Bytes)
        63..92 == Album Name (30 Bytes)
        93..96 == Year (4 Bytes)
        97..126 == Comment (30 Bytes)
        127 == 1 Byte Song Genre Identifier (get the listing of song Genre Types to know what byte = what)
    */
    // malloc funktioniert nie?!?!
    // Schluesselwort TAG checken
    if (!(buffer[0] == 'T' && buffer[1] == 'A' && buffer[2] == 'G')) {
        puts("Kein TAG gefunden!");
        return NULL;
    }
    // strncpy(dest, src, size_t n) copies n bytes from src to dest
    strncpy(data.titel, buffer + 3, 30);
    strncpy(data.interpret, buffer + 33, 30);  // Intepret = Author
    strncpy(data.album, buffer + 63, 30);
    strncpy(data.jahr, buffer + 93, 4);
    strncpy(data.kommentar, buffer + 97, 30);
    data.genre = buffer[127];
    return &data;
}

/*				       *
 * Es werden die in dem struct mp3file *
 * abgelegten Informationen ausgegeben *
 *				       */
void printTag(struct mp3file *mp3) {
    /* HIER MUESST IHR EUREN CODE EINFUEGEN */
    // 5a.5
    if (mp3 == NULL) {
        puts("Kein Daten verfügbar");
        return;
    }
    puts("------------------------------------------");
    printf("Title: %s\n", mp3->titel);
    printf("Author: %s\n", mp3->interpret);
    printf("Album: %s\n", mp3->album);
    printf("Year: %s\n", mp3->jahr);
    printf("Comment: %s\n", mp3->kommentar);
    printf("Genre: %s\n", translateGenre(mp3->genre));
    puts("------------------------------------------");
}
