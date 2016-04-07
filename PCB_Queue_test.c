#include "PCB_Queue.h"
#include "PCB.h"
#include <stdio.h>

int main() {
	enum PCB_ERROR error = PCB_SUCCESS;
	printf("\n elements \n");
	PCB_p p1 = PCB_construct(&error);
	PCB_init(p1, &error);
	// PCB_print(p1, &error);

	PCB_set_pid(p1, 64, &error);
	PCB_set_state(p1, PCB_STATE_READY, &error);
	PCB_set_priority(p1, 8, &error);
	PCB_set_pc(p1, 128, &error);
	// PCB_print(p1, &error);
	
	//second p2
	PCB_p p2 = PCB_construct(&error);
	PCB_init(p2, &error);
	// PCB_print(p2, &error);

	PCB_set_pid(p2, 65, &error);
	PCB_set_state(p2, PCB_STATE_RUNNING, &error);
	PCB_set_priority(p2, 7, &error);
	PCB_set_pc(p2, 118, &error);
	// PCB_print(p2, &error);

	PCB_Queue_p list = PCB_Queue_construct(&error);
	PCB_Queue_enqueue(list,p1, &error);
	PCB_Queue_enqueue(list,p2, &error);
	
	printf("\nTest for enqueue \n");
	PCB_Queue_print(list, &error);	

	printf("\nTest for denqueue \n");
	PCB_p pcbp = PCB_Queue_dequeue(list, &error);
	PCB_Queue_print(list, &error);	
	
	printf("\nTest for denqueue values \n");
	PCB_print(pcbp, &error);

	
	PCB_destruct(p1, &error);
	PCB_destruct(p2, &error);


	return 0;
}