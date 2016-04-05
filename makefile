CFLAGS=-Wall -std=c99

all: PCB_Queue_test PCB_test

PCB_Queue_test: PCB_Queue.o PCB.o PCB_Queue_test.o
	gcc PCB_Queue.o PCB.o PCB_Queue_test.o -o PCB_Queue_test
PCB_test: PCB.o PCB_test.o
	gcc PCB_test.o PCB.o -o PCB_test


PCB_Queue_test.o: PCB_Queue_test.c
	gcc $(CFLAGS) -c PCB_Queue_test.c
PCB_test.o: PCB_test.c
	gcc $(CFLAGS) -c PCB_test.c
PCB_Priority_Queue.o: PCB_Priority_Queue.c 
	gcc $(CFLAGS) -c PCB_Priority_Queue.c
PCB_Queue.o: PCB_Queue.c
	gcc $(CFLAGS) -c PCB_Queue.c 
PCB.o: PCB.c
	gcc $(CFLAGS) -c PCB.c
