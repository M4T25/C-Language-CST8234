#constants
CC = gcc
CC_FLAGS = -g -Wall -ansi -pedantic -std=c99 -w
FILES = a1Main.c validation.c display.c registration.c withdraw.c


make: a1Main.c validation.c display.c registration.c withdraw.c
	$(CC) -o registration $(FILES) $(CC_FLAGS)

clean:
	rm * .o