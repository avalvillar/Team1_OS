#ifndef PCB_H_INCLUDED
#define PCB_H_INCLUDED

#define PCB_PRIORITY_MAX 15

enum state_type {
	new = 0, 
	ready, 
	running, 
	interrupted, 
	waiting, 
	halted, 

	last_error // invalid type, used for bounds checking
};

typedef struct pcb {
    unsigned long pid;        // process ID #, a unique number
	enum state_type state;    // process state (running, waiting, etc.)
	unsigned short priority;  // priorities 0=highest, 15=lowest
	unsigned long pc;         // holds the current pc value when preempted
} PCB;

typedef PCB * PCB_p;

PCB_p PCB_construct(void); // returns a pcb pointer to heap allocation
void PCB_destruct(PCB_p p);  // deallocates pcb from the heap
void PCB_init(PCB_p p);       // sets default values for member data
void PCB_set_pid(PCB_p p, unsigned long pid);
void PCB_set_state(PCB_p p, enum state_type state);
void PCB_set_priority(PCB_p p, unsigned short priority);
void PCB_set_pc(PCB_p p, unsigned long pc);
unsigned long PCB_get_pid(PCB_p p);  // returns pid of the process
enum state_type PCB_get_state(PCB_p p);
unsigned short PCB_get_priority(PCB_p p);
unsigned long PCB_get_pc(PCB_p p);

void PCB_toString(PCB_p p, char *s);  // returns a string representing the contents of the pcb

#endif // PCB_H_INCLUDED