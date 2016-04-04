#include "PCB_Queue.h"
#include "pcb.h"

int main() {
	printf("\n elements \n");
	PCB_p p1 = PCB_construct();
	PCB_init(p1);
	char string[100];
	//PCB_toString(p1, string);
	printf("%s\n", string);

	PCB_set_pid(p1, 64);
	PCB_set_state(p1, ready);
	PCB_set_priority(p1, 8);
	PCB_set_pc(p1, 128);
	PCB_toString(p1, string);
	printf("%s\n", string);
	
	//second p2
	PCB_p p2 = PCB_construct();
	PCB_init(p2);
	//PCB_toString(p2, string);
	printf("%s\n", string);

	PCB_set_pid(p2, 65);
	PCB_set_state(p2, running);
	PCB_set_priority(p2, 7);
	PCB_set_pc(p2, 118);
	PCB_toString(p2, string);
	printf("%s\n", string);

	PCB_Queue_p list = PCB_Queue_construct();
	PCB_Queue_enqueue(list,p1);
	PCB_Queue_enqueue(list,p2);
	
	printf("\nTest for enqueue \n");
	PCB_Queue_toString(list);	

	printf("\nTest for denqueue \n");
	struct node * tempNode = dequeue(list);
	PCB_Queue_toString(list);	
	
	printf("\nTest for denqueue values \n");
	PCB_toString(tempNode->value, string);
	printf("%s\n", string);

	
	PCB_destruct(p1);
	PCB_destruct(p2);


	return 0;
}