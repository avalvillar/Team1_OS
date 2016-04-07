#include "PCB_Priority_Queue.h"
#include "PCB_Queue.h"
#include "PCB.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	enum PCB_ERROR error = PCB_SUCCESS;
	printf("\nPCB_Priority_Queue_test:\n\n");
	PCB_Priority_Queue_p pq = PCB_Priority_Queue_construct(&error);
	int i;
	for (i = 0; i < 10; i++) {
		int j;
		for (j = 0; j < 10; j++) {
			PCB_p pcbp = PCB_construct(&error);
			PCB_init(pcbp, &error);
			PCB_set_priority(pcbp, rand() % (PCB_PRIORITY_MAX + 1), &error);
			PCB_set_pid(pcbp, rand(), &error);
			printf("Added: ");
			PCB_print(pcbp, &error);
			PCB_Priority_Queue_enqueue(pq, pcbp, &error);
		}
		PCB_Priority_Queue_print(pq, &error);
		int k;
		int kmax = rand() % 3 + 4;
		for (k = 0; k < kmax; k++) {
			printf("Removed: ");
			PCB_p pcbp = PCB_Priority_Queue_dequeue(pq, &error);
			PCB_print(pcbp, &error);
			PCB_destruct(pcbp, &error);
		}
		PCB_Priority_Queue_print(pq, &error);
		printf("\n");
	}

	return 0;
}