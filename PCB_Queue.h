//PCB_Queue_Header

typedef struct node {
	PCB_p *pcb;
	struct node *next;
} Node, Head;

FIFOq_is_empty(FIFOq);
FIFOq_enqueue(FIFOq, Node);
FIFOq_dequeue(FIFOq);