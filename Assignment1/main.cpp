#include "FIFOQueue_h.h"
#include "FIFOQueue.cpp"
#include "READYQueue_h.h"
#include "READYQueue.c"
#include <stdio.h>
int main(int argc, char* argv[]) {
	FIFOq *q = new FIFOq();
	printf("if the queue is empty:%s \n",FIFOq_is_empty(q) ? "true":"false");
	PCB_p raw_pcb = PCB_construct();
	PCB_init(raw_pcb);
	PCB_set_pid(raw_pcb,2);
	printf("%s",PCB_toString(raw_pcb));
	Node *node = (Node*) malloc(sizeof(Node));
	node -> init_pcb = raw_pcb;
	node -> next_node = NULL;
	FIFOq_enqueue(q,node);
	printf("%s\n",FIFOq_toString(q));
	FIFOq_dequeue(q);
	FIFOq_dequeue(q);

	READYq *rq = new ReadyQueue();

	// printf("%s",PCB_toString(raw_pcb));
	// unsigned long id = PCB_get_pid(raw_pcb);
	// printf("\n");
	// printf("%lu",raw_pcb->pid);
	// printf("%lu",id);
	// printf("\n");
	// return 0;
}