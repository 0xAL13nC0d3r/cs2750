all: A B

A: master.o
	gcc master.o -o all

B: worker.o
	gcc worker.o -o all

master.o: master.c
	gcc -c -o master.o master.c

worker.o: worker.c
	gcc -c -o worker.o worker.c
