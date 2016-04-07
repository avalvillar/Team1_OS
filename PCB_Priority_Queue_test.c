#include "PCB_Priority_Queue.h"
#include "PCB_Queue.h"
#include "PCB.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	printf("\nPCB_Priority_Queue_test:\n\n");
	PCB_Priority_Queue_p pq = PCB_Priority_Queue_construct();
	int i;
	for (i = 0; i < 10; i++) {
		int j;
		for (j = 0; j < 10; j++) {
			PCB_p pcbp = PCB_construct();
			PCB_init(pcbp);
			PCB_set_priority(pcbp, rand() % (PCB_PRIORITY_MAX + 1));
			PCB_set_pid(pcbp, rand());
			printf("Added: ");
			PCB_print(pcbp);
			PCB_Priority_Queue_enqueue(pq, pcbp);
		}
		PCB_Priority_Queue_print(pq);
		int k;
		int kmax = rand() % 3 + 4;
		for (k = 0; k < kmax; k++) {
			printf("Removed: ");
			PCB_p pcbp = PCB_Priority_Queue_dequeue(pq);
			PCB_print(pcbp);
			PCB_destruct(pcbp);
		}
		PCB_Priority_Queue_print(pq);
		printf("\n");
	}

	return 0;
}