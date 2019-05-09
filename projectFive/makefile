all: A B 

A: master.o
	gcc -o master master.o 

B: worker.o
	gcc -o worker worker.o

master.o: master.c
	gcc -c  master.c

worker.o: worker.c
	gcc -c worker.c
