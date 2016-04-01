#include "pcb.h"
#include <stdlib.h>
#include <stdio.h>

PCB_p PCB_construct(void) {
	return malloc(sizeof(PCB));
}

void PCB_destruct(PCB_p p) {
	free(p);
}

int PCB_init(PCB_p p) {
	PCB_set_pid(p, 0);
	PCB_set_state(p, new);
	PCB_set_priority(p, PCB_PRIORITY_MAX);
	PCB_set_pc(p, 0);
	return 0;
}

int PCB_set_pid(PCB_p p, unsigned long pid) {
	p->pid = pid;
	return 0;
}

int PCB_set_state(PCB_p p, enum state_type state) {
	p->state = state;
	return 0;
}

int PCB_set_priority(PCB_p p, unsigned short priority) {
	if (priority > PCB_PRIORITY_MAX) return 1;
	p->priority = priority;
	return 0;
}

int PCB_set_pc(PCB_p p, unsigned long pc) {
	p->pc = pc;
	return 0;
}

unsigned long PCB_get_pid(PCB_p p) {
	return p->pid;
}  

enum state_type PCB_get_state(PCB_p p) {
	return p->state;
}

unsigned short PCB_get_priority(PCB_p p) {
	return p->priority;
}

unsigned long PCB_get_pc(PCB_p p) {
	return p->pc;
} 

int PCB_toString(PCB_p p, char *s) {
	if (s == NULL) return 1;
	sprintf(s, "PID: %#0X, Priority: %#0X, State: %u, PC: %#0X", 
			PCB_get_pid(p), PCB_get_priority(p), PCB_get_state(p), PCB_get_pc(p));
	return 0;
}