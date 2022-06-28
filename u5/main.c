#include <stdio.h>
#include <string.h>

#include "mp3.h"

int main(int argc, char **argv) {
    int i;

    if (argc < 2) {
        printf("Bitte gib' mindestens eine Datei mit an: mp3 <datei1> [datei2] [...]\n");
        return 1;
    }

    for (i = 1; i < argc; i++) {
        idTagFile(argv[i], NULL);
    }

    return 0;
}

/* Als Parameter ist entweder ein Integer oder ein Character zulaessig.	   *
 * Die Funktion wandelt den Code fuer ein Genre in einen lesbaren Text um. */
const char *genres[] = {"Blues",
                        "Classic Rock",
                        "Country",
                        "Dance",
                        "Disco",
                        "Funk",
                        "Grunge",
                        "Hip-Hop",
                        "Jazz",
                        "Metal",
                        "New Age",
                        "Oldies",
                        "Other",
                        "Pop",
                        "Rhythm and Blues",
                        "Rap",
                        "Reggae",
                        "Rock",
                        "Techno",
                        "Industrial",
                        "Alternative",
                        "Ska",
                        "Death Metal",
                        "Pranks",
                        "Soundtrack",
                        "Euro-Techno",
                        "Ambient",
                        "Trip-Hop",
                        "Vocal",
                        "Jazz&Funk",
                        "Fusion",
                        "Trance",
                        "Classical",
                        "Instrumental",
                        "Acid",
                        "House",
                        "Game",
                        "Sound Clip",
                        "Gospel",
                        "Noise",
                        "Alternative Rock",
                        "Bass",
                        "Soul",
                        "Punk",
                        "Space",
                        "Meditative",
                        "Instrumental Pop",
                        "Instrumental Rock",
                        "Ethnic",
                        "Gothic",
                        "Darkwave",
                        "Techno-Industrial",
                        "Electronic",
                        "Pop-Folk",
                        "Eurodance",
                        "Dream",
                        "Southern Rock",
                        "Comedy",
                        "Cult",
                        "Gangsta",
                        "Top 40",
                        "Christian Rap",
                        "Pop/Funk",
                        "Jungle",
                        "Native US",
                        "Cabaret",
                        "New Wave",
                        "Psychedelic",
                        "Rave",
                        "Showtunes",
                        "Trailer",
                        "Lo-Fi",
                        "Tribal",
                        "Acid Punk",
                        "Acid Jazz",
                        "Polka",
                        "Retro",
                        "Musical",
                        "Rock & Roll",
                        "Hard Rock",
                        "Folk"};

const char *translateGenre(int genre_id) {
    if (genre_id >= 0 && genre_id <= 80) {
        return genres[genre_id];
    } else {
        return "undefined";
    }
}
