#include "PCB.h"
#include <stdlib.h>
#include <stdio.h>

PCB_p PCB_construct(enum PCB_ERROR *error) {
	void *memPtr = malloc(sizeof(PCB));
	if (memPtr == NULL) {
		*error = PCB_MEM_ALLOC_FAIL;
		return memPtr;
	} 
	return memPtr;
}

void PCB_destruct(PCB_p p, enum PCB_ERROR *error) {
	if (p == NULL) {
		*error = PCB_NULL_POINTER; //Unsure if even needed. 
		return;
	}
	free(p);
}

void PCB_init(PCB_p p, enum PCB_ERROR *error) {
	if (p == NULL) {
		*error = PCB_NULL_POINTER;
		return;
	}
	PCB_set_pid(p, 0, PCB_SUCCESS);
	PCB_set_state(p, PCB_STATE_NEW, PCB_SUCCESS);
	PCB_set_priority(p, PCB_PRIORITY_MAX, PCB_SUCCESS);
	PCB_set_pc(p, 0, PCB_SUCCESS);
}

void PCB_set_pid(PCB_p p, unsigned long pid, enum PCB_ERROR *error) {
	if (p == NULL) {
		*error = PCB_NULL_POINTER;
		return;
	}
	if (pid < 0) {
		*error = PCB_INVALID_ARG;
		return;
	}
	p->pid = pid;
}

void PCB_set_state(PCB_p p, enum PCB_STATE_TYPE state, enum PCB_ERROR *error) {
	if (p == NULL) {
		*error = PCB_NULL_POINTER;
		return;
	}
	if (state < 0 || state >= PCB_STATE_LAST_ERROR) {
		*error = PCB_INVALID_ARG;
		return;
	}
	p->state = state;
}

void PCB_set_priority(PCB_p p, unsigned short priority, enum PCB_ERROR *error) {
	if (p == NULL) {
		*error = PCB_NULL_POINTER;
		return;
	}
	if (priority > PCB_PRIORITY_MAX || priority < 0) {
		*error = PCB_INVALID_ARG;
		return;
	}
	p->priority = priority;
}

void PCB_set_pc(PCB_p p, unsigned long pc, enum PCB_ERROR *error) {
	if (p == NULL) {
		*error = PCB_NULL_POINTER;
		return;
	}
	if (pc < 0) {
		*error = PCB_INVALID_ARG;
		return;
	}
	p->pc = pc;
}

unsigned long PCB_get_pid(PCB_p p, enum PCB_ERROR *error) {
	if (p == NULL) {
		*error = PCB_NULL_POINTER;
		return 0;
	}
	return p->pid;
}  

enum PCB_STATE_TYPE PCB_get_state(PCB_p p, enum PCB_ERROR *error) {
	if (p == NULL) {
		*error = PCB_NULL_POINTER;
		return PCB_STATE_ERROR;
	}
	return p->state;
}

unsigned short PCB_get_priority(PCB_p p, enum PCB_ERROR *error) {
	if (p == NULL) {
		*error = PCB_NULL_POINTER;
		return 0;
	}
	return p->priority;
}

unsigned long PCB_get_pc(PCB_p p, enum PCB_ERROR *error) {
	if (p == NULL) {
		*error = PCB_NULL_POINTER;
		return 0;
	}
	return p->pc;
} 

void PCB_toString(PCB_p p, char *s, enum PCB_ERROR *error) {
	if (p == NULL || s == NULL) {
		*error = PCB_NULL_POINTER;
		return;
	}
	sprintf(s, "PID: 0x%lX, Priority: 0x%X, State: %u, PC: 0x%lX", 
			PCB_get_pid(p, PCB_SUCCESS), PCB_get_priority(p, PCB_SUCCESS),
			PCB_get_state(p, PCB_SUCCESS), PCB_get_pc(p, PCB_SUCCESS));
	return;
}
