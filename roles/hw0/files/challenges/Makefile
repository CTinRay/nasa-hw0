include flag.mk

CC=gcc
CFLAGS=-O3 -g0 -s

engine: engine.c
	$(CC) $(CFLAGS) engine.c decrypt.c -o engine -D FLAG=$(FLAG_ENGINE) -D KEY=$(KEY)
