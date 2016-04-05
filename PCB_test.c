#include "PCB.h"
#include <stdio.h>

int main() {
	PCB_p p = PCB_construct();
	PCB_init(p);
	char string[100];
	PCB_toString(p, string);
	printf("%s\n", string);

	PCB_set_pid(p, 64);
	PCB_set_state(p, PCB_STATE_READY);
	PCB_set_priority(p, 8);
	PCB_set_pc(p, 128);
	PCB_toString(p, string);
	printf("%s\n", string);

	PCB_destruct(p);

	return 0;
}