include flag.mk

CC=gcc
CFLAGS=-O3 -g0 -s -std=c11

.PHONY: all

all: engine magic etago throttle periodic listen

engine: engine.c decrypt.c
	$(CC) $(CFLAGS) engine.c decrypt.c -o engine -D FLAG=$(FLAG_ENGINE) -D KEY=$(KEY)

magic: magic.c decrypt.c
	$(CC) $(CFLAGS) magic.c decrypt.c -o magic -D FLAG=$(FLAG_WING) -D KEY=$(KEY)

etago: etago.c decrypt.c
	$(CC) $(CFLAGS) etago.c decrypt.c -o etago -D FLAG=$(FLAG_ETA) -D KEY=$(KEY)

throttle: throttle.c decrypt.c
	$(CC) $(CFLAGS) throttle.c decrypt.c -o throttle -D FLAG=$(FLAG_LAND) -D KEY=$(KEY)

periodic: periodic.c
	$(CC) $(CFLAGS) periodic.c -O0 -g0 -s -std=c11 -o periodic

listen: listen.c
	$(CC) $(CFLAGS) listen.c -O0 -g0 -s -std=c11 -o listen
