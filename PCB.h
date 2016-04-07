#pragma once
#include "PCB_Errors.h"
#define PCB_PRIORITY_MAX 15

enum PCB_STATE_TYPE {
	PCB_STATE_NEW = 0, 
	PCB_STATE_READY, 
	PCB_STATE_RUNNING, 
	PCB_STATE_INTERRUPTED, 
	PCB_STATE_WAITING, 
	PCB_STATE_HALTED,
	
	PCB_STATE_ERROR, // Used as return value if null pointer is passed to getter.

	PCB_STATE_LAST_ERROR // invalid type, used for bounds checking
};


typedef struct pcb {
    unsigned long pid;        // process ID #, a unique number
	enum PCB_STATE_TYPE state;    // process state (running, waiting, etc.)
	unsigned short priority;  // priorities 0=highest, 15=lowest
	unsigned long pc;         // holds the current pc value when preempted
} PCB;

typedef PCB * PCB_p;

PCB_p PCB_construct(enum PCB_ERROR *error); // returns a pcb pointer to heap allocation
void PCB_destruct(PCB_p p, enum PCB_ERROR *error);  // deallocates pcb from the heap
void PCB_init(PCB_p p, enum PCB_ERROR* error);       // sets default values for member data
void PCB_set_pid(PCB_p p, unsigned long pid, enum PCB_ERROR  *error);///////
void PCB_set_state(PCB_p p, enum PCB_STATE_TYPE state, enum PCB_ERROR  *error);
void PCB_set_priority(PCB_p p, unsigned short priority, enum PCB_ERROR *error);
void PCB_set_pc(PCB_p p, unsigned long pc, enum PCB_ERROR *error);
unsigned long PCB_get_pid(PCB_p p, enum PCB_ERROR *error);  // returns pid of the process
enum PCB_STATE_TYPE PCB_get_state(PCB_p p, enum PCB_ERROR *error);
unsigned short PCB_get_priority(PCB_p p, enum PCB_ERROR *error);
unsigned long PCB_get_pc(PCB_p p, enum PCB_ERROR *error);

void PCB_print(PCB_p p, enum PCB_ERROR *error);  // a string representing the contents of the pcb
