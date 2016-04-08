#include "PCB_Queue.h"
#include "PCB.h"
#include "PCB_Errors.h"
#include <stdio.h>
#include <string.h>

int main() {	
	enum PCB_ERROR error = PCB_SUCCESS;
	//printf("\n elements \n");
	PCB_p p1 = PCB_construct(&error);
	//printf("string %s", p1);
	//PCB_init(p1);
	//PCB_toString(p1, string);
	//printf("%s\n", string);

	PCB_set_pid(p1, 64, &error);
	PCB_set_state(p1, PCB_STATE_READY, &error);
	PCB_set_priority(p1, 8, &error);
	PCB_set_pc(p1, 128, &error);
	//PCB_toString(p1, string);
	//printf("%s\n", string);
	
	//second p2
	PCB_p p2 = PCB_construct(&error);
	PCB_init(p2, &error);
	//PCB_toString(p2, string);

//	printf("%s\n", string);

	PCB_set_pid(p2, 65, &error);
	PCB_set_state(p2, PCB_STATE_RUNNING, &error);
	PCB_set_priority(p2, 7, &error);
	PCB_set_pc(p2, 118, &error);
	
	//3rd element
	PCB_p p3 = PCB_construct(&error);
	PCB_init(p3, &error);

	PCB_set_pid(p3, 66, &error);
	PCB_set_state(p3, PCB_STATE_RUNNING, &error);
	PCB_set_priority(p3, 6, &error);
	PCB_set_pc(p3, 108, &error);
	//PCB_toString(p3, string);
	//printf("%s\n", string);

	char string2[100];// testing

	PCB_Queue_p list = PCB_Queue_construct(&error);
	printf("\nTest for enqueue \n");

	PCB_Queue_enqueue(list,p1, &error);
	//PCB_Queue_toString2(list); //new
	strcpy(string2,"P1->");
	printf("\nQ: Count = %d : %s\n",list->size,string2);
	printf("contents: ");
	PCB_print(p1, &error); //new

	PCB_Queue_enqueue(list,p2, &error);
	//PCB_Queue_toString2(list); //new
	strcat(string2,"P2->");
	printf("\nQ: Count = %d : %s\n",list->size,string2);
	printf("contents: ");
	PCB_print(p2, &error); //new
  //new

	PCB_Queue_enqueue(list,p3, &error);
	//PCB_Queue_toString2(list); //new
	strcat(string2,"P3->");
	printf("\nQ: Count = %d : %s\n",list->size,string2);
	printf("contents: ");
	PCB_print(p3, &error); //new

	char *testing = string2;
	printf("\n\nTest for dequeue\n");
	printf("\nQ: Count = %d : %s",list->size,string2);
	PCB_p pcbp = PCB_Queue_dequeue(list, &error);
	testing = (testing+4);
	strcpy(string2,testing);
	printf("\nQ: Count = %d : %s\n",list->size,string2);
	printf("contents: ");
	PCB_print(pcbp, &error);
	
	PCB_destruct(p1, &error);
	PCB_destruct(p2, &error);

	return 0;
}