/*
This is the header file that works in conjunction with the PCB_Queue.c and the
driver PCB_Queue_test.c; Contained will be the prototypes for functions that will be 
used during the program.
*/

/* Needed includes */
#include <stdio.h>
#include <stdlib.h>

/*
The structure for the linked list implementation - in this case they are
called nodes with the names Node, Head, and Tail.
Fields are:
	PCB_p * - the specific PCB structure.
	node * - to the next node in the list.
*/
typedef struct node {
	PCB_p *pcb;
	struct node *next;
} Node;

/* Static variables to keep the front and back locations of the queue. */
static Node *head, *tail;

/*Boolean needed for multiple use in the program. */
typedef int boolean;
#define true 1
#define false 0

/* Prototypes for the functions. */
Node FIFOq_construct(void); /* Constructor. */
int FIFOq_is_empty(FIFOq); /* Check if queue is empty. */
void FIFOq_enqueue(FIFOq, Node); /* Attach a node to the tail of queue. */
PCB_p FIFOq_dequeue(FIFOq); /* Remove the head node of queue. */
void FIFOq_toString(FIFOq); /* To string method for the queue. */

/* Prototypes for the test functions in the driver program. */
//void test1();
//void test2();
//void test3();
//void test4();
//void test5();

/* include the needed PCB_Queue.c */
#include "PCB_Queue.c"