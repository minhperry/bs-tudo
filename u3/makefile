CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -D_POSIX_C_SOURCE=200112L

all: clean b c d

b: vorgabe.o a3_a.o a3_b.o
	$(CC) -pthread -o a3_b $^

c: vorgabe.o a3_a.o a3_c.o
	$(CC) -pthread -o a3_c $^

d: vorgabe.o a3_a.o a3_d.o
	$(CC) -pthread -o a3_d $^

.c.o:
	$(CC) -pthread $(CFLAGS) -c -o $@ $^

.PHONY: all clean

clean:
	rm -f a3_a.o a3_b.o a3_c.o a3_d.o vorgabe.o a3_b a3_c a3_d


