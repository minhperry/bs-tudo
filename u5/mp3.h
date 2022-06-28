#ifndef _MP3_H_
#define _MP3_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "mp3.h"
 
#define ID3_SIZE 128
struct mp3file {
	char interpret[31];
	char titel[31];
	char album[31];
	char kommentar[31];
	char jahr[5];
	char genre;
};

void idTagFile(const char *,char *);
void idTagDir(const char *,char *);
struct mp3file *bytesToIdTag(char *);
void printTag(struct mp3file *);
const char *translateGenre(int genre_id);

#endif
