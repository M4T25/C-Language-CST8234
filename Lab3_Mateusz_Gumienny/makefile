CFLAGS = -g -pedantic -Wall

all: final

final: lab3main.o prntArr.o srtArr.o rndmArr.o rvrsArr.o
	gcc $(CFLAGS) lab3main.o prntArr.o srtArr.o rndmArr.o rvrsArr.o -o arraym2

lab3main.o: lab3main.c lab3.h
	gcc $(CFLAGS) -c lab3main.c

lab3print.o: prntArr.c lab3.h
	gcc $(CFLAGS) -c prntArr.c

lab3sort_array.o: srtArr.c lab3.h
	gcc $(CFLAGS) -c srtArr.c

lab3rand_array.o: rndmArr.c lab3.h
	gcc $(CFLAGS) -c rndmArr.c

lab3reverse_array.o: rvrsArr.c lab3.h
	gcc $(CFLAGS) -c rvrsArr.c


run: final
	./arraym2

clean:
	rm lab3main.o prntArr.o srtArr.o rndArr.o rvrsArr.o
