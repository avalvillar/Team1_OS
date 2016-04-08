#include "PCB_Queue.h"
#include "PCB.h"
#include <stdio.h>
#include <string.h>

str = "these strings are concatenated";
int main() {	
	//printf("\n elements \n");
	PCB_p p1 = PCB_construct();
	//printf("string %s", p1);
	//PCB_init(p1);
	char string[100];
	//PCB_toString(p1, string);
	//printf("%s\n", string);

	PCB_set_pid(p1, 64);
	PCB_set_state(p1, PCB_STATE_READY);
	PCB_set_priority(p1, 8);
	PCB_set_pc(p1, 128);
	//PCB_toString(p1, string);
	//printf("%s\n", string);
	
	//second p2
	PCB_p p2 = PCB_construct();
	PCB_init(p2);
	//PCB_toString(p2, string);
//	printf("%s\n", string);

	PCB_set_pid(p2, 65);
	PCB_set_state(p2, PCB_STATE_RUNNING);
	PCB_set_priority(p2, 7);
	PCB_set_pc(p2, 118);
	
	//3rd element
	PCB_p p3 = PCB_construct();
	PCB_init(p3);

	PCB_set_pid(p3, 66);
	PCB_set_state(p3, PCB_STATE_RUNNING);
	PCB_set_priority(p3, 6);
	PCB_set_pc(p3, 108);
	//PCB_toString(p3, string);
	//printf("%s\n", string);

	char string2[100];// testing

	PCB_Queue_p list = PCB_Queue_construct();
	printf("\nTest for enqueue \n");

	PCB_Queue_enqueue(list,p1);
	//PCB_Queue_toString2(list); //new
	strcpy(string2,"P1->");
	printf("\nQ: Count = %d : %s\n",list->size,string2);
	PCB_toString(p1, string); //new
	printf("Contents : %s", string);   // new

	PCB_Queue_enqueue(list,p2);
	//PCB_Queue_toString2(list); //new
	strcat(string2,"P2->");
	printf("\nQ: Count = %d : %s\n",list->size,string2);
	PCB_toString(p2, string); //new
	printf("Contents : %s", string);	  //new

	PCB_Queue_enqueue(list,p3);
	//PCB_Queue_toString2(list); //new
	strcat(string2,"P3->");
	printf("\nQ: Count = %d : %s\n",list->size,string2);
	PCB_toString(p3, string); //new
	printf("Contents : %s", string);	  //new

	char *testing = string2;
	printf("\n\nTest for denqueue\n");
	printf("\nQ: Count = %d : %s",list->size,string2);
	PCB_p pcbp = PCB_Queue_dequeue(list);
	testing = (testing+4);
	strcpy(string2,testing);
	printf("\nQ: Count = %d : %s\n",list->size,string2);
	PCB_toString(pcbp, string);
	printf("Contents : %s\n\n", string);
	
	PCB_destruct(p1);
	PCB_destruct(p2);

	return 0;
}