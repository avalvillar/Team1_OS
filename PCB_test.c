#include "PCB.h"
#include <stdio.h>

int main() {
	enum PCB_ERROR error = PCB_SUCCESS;
	PCB_p p = PCB_construct(&error);
	PCB_init(p, &error);
	PCB_print(p, &error);

	PCB_set_pid(p, 64, &error);
	PCB_set_state(p, PCB_STATE_READY, &error);
	PCB_set_priority(p, 8, &error);
	PCB_set_pc(p, 128, &error);
	PCB_print(p, &error);

	PCB_destruct(p, &error);


	return 0;
}