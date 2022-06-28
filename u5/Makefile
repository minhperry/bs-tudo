CC=gcc
FLAGS=-Wall -D_XOPEN_SOURCE -D_POSIX_SOURCE
FLAGS_EVIL=-Werror -pedantic -ansi

all: mp3 mp3c

mp3: main.c mp3a.c mp3b.c
	$(CC) $(FLAGS) -o $@ $^

mp3c: main.c mp3c.c mp3b.c
	$(CC) $(FLAGS) -o $@ $^

mp3_evil: main.c mp3a.c mp3b.c mp3c.c
	$(CC) $(FLAGS) $(FLAGS_EVIL) -o mp3 $^

clean: 
	rm -f mp3

.PHONY: clean mp3_evil

mp3: mp3.h

mp3c: mp3.h

