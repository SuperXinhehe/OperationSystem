#include "FIFOQueue_h.h"
#include "READYQueue_h.h"
#include <stdio.h>

int READYq_enqueue(READYq *rq, Node* e) {
	int priority = e->init_pcb->priority;
	FIFOq *qi = rq->q->index[priority];
	FIFOq_enqueue(qi,e);
	rq->q->index[priority] = qi;
	return 0;
}

void print_READYq(READYq *rq) {
	if(!rq) {
		printf("EMPTY QUEUE\n");
	}
	else {
		for(int i = 0;i<rq->q->priority_number;i++) {
			// if the ith queue exist in priority queue print
			if(!rq->q) {
				printf("Q%d: %s\n",i,FIFOq_toString(rq->q->index[i]));
			}
		}
	}
}