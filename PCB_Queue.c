/*
This is the .C file that works in conjunction with the PCB_Queue.h and the
driver PCB_Queue_test.c; Contained will be the functions listed in the header 
file, fully implemented. 
*/

Node FIFOq_construct() {
	head = malloc(sizeof(Node));
	tail = malloc(sizeof(Node));
	tail = NULL;
	head = tail;
	return head;
}

int FIFOq_is_empty(FIFOq) {
	boolean isEmpty = 0;
	if (head == NULL) {
		empty = 1;
	}
	return isEmpty;
}

FIFOq_enqueue(FIFOq, Node) {
	if (head == NULL) {
		head = Node;
		tail = Node;
	}
	else {
		tail->next = Node;
		tail = Node;
	}
}

PCB_p FIFOq_dequeue(FIFOq) {
	PCB_p *temp;
	if (FIFOq_is_empty(FIFOq)) {
		temp = head;
	}
	else {
		temp = head->pcb;
		head = head->next;
		free(head);
	}
	return temp;
}

//FIFOq_toString(FIFOq);