#include "PCB.h"
#include <stdio.h>

int main() {
	
	PCB_p p = PCB_construct(PCB_SUCCESS);
	PCB_init(p, PCB_SUCCESS);
	char string[100];
	PCB_toString(p, string, PCB_SUCCESS);
	printf("%s\n", string);

	PCB_set_pid(p, 64, PCB_SUCCESS);
	PCB_set_state(p, PCB_STATE_READY, PCB_SUCCESS);
	PCB_set_priority(p, 8, PCB_SUCCESS);
	PCB_set_pc(p, 128, PCB_SUCCESS);
	PCB_toString(p, string, PCB_SUCCESS);
	printf("%s\n", string);

	PCB_destruct(p, PCB_SUCCESS);

	return 0;
}