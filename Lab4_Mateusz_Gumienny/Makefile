CC = gcc
CC_FLAGS = -g -ansi -pedantic -Wall
FILES = temp.c wind.c gust.c main.c

compile: temp.c wind.c gust.c main.c
	$(CC) $(CC_FLAGS) -o mypgm $(FILES) 

exe:
	./mypgm < sensors_output.txt
clean:
	rm * .o