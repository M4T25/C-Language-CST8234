CC = gcc
CC_FLAGS = -g -ansi -pedantic -Wall -w
FILES = main.c student.c

compile: main.c student.c
	$(CC) $(CC_FLAGS) -o program $(FILES)
	
execute:
	./program students.dat
	
clean:
	rm * .o