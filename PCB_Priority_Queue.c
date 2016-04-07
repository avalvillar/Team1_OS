#include <stdlib.h>
#include <stdio.h>
#include "PCB_Priority_Queue.h"
#include "PCB_Queue.h"
#include "PCB.h"

PCB_Priority_Queue_p PCB_Priority_Queue_construct(void) {
	PCB_Priority_Queue_p pq = malloc(sizeof(struct PCB_Priority_Queue));
	if (pq == NULL) return NULL;
	int i;
	for (i = 0; i <= PCB_PRIORITY_MAX; i++) {
		pq->queues[i] = PCB_Queue_construct();
	}
	return pq;
}

void PCB_Priority_Queue_enqueue(PCB_Priority_Queue_p pq, PCB_p pcb) {
	if (pq == NULL || pcb == NULL) return;
	PCB_Queue_p queue = pq->queues[PCB_get_priority(pcb)];
	PCB_Queue_enqueue(queue, pcb);
}

PCB_p PCB_Priority_Queue_dequeue(PCB_Priority_Queue_p pq) {
	if (pq == NULL) return NULL;
	int i = 0;
	while (PCB_Queue_is_empty(pq->queues[i])) {
		if (i > PCB_PRIORITY_MAX) return NULL;
		i++;
	}
	return PCB_Queue_dequeue(pq->queues[i]);
}

void PCB_Priority_Queue_print(PCB_Priority_Queue_p pq) {
	int i;
	for (i = 0; i <= PCB_PRIORITY_MAX; i++) {
		PCB_Queue_p q = pq->queues[i];
		printf("Q%u: Count=%u: ", i, q->size);
		struct node *n = q->first_node_ptr;
		while (n != NULL) {
			printf("->%X", n->value->pid);
			n = n->next_node;
		}
		printf("-*\n");
	}
}