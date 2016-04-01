#include "FIFOQueue_h.h"
#ifndef READYQUEUE_H
#define READYQUEUE_H

typedef struct Priority_Queue {
	FIFOq **index;
	int priority_number;
}PRIORITYq;

typedef struct ReadyQueue {
	// could be redundent level will be the size of the priority queue
	int level_priority;
	PRIORITYq *q;
	ReadyQueue() {
		level_priority = 16;
		int i;
		// q->index = malloc(sizeof(PRIORITYq) + sizeof(FIFOq*) * level_priority);
		for(i = 0; i < level_priority; i++) {
			FIFOq* fifoq;
			q->index[i] = fifoq;
			q->priority_number = i;
		}
	}
} READYq;

int READYq_enqueue(READYq,Node);
void print_READYq(READYq);

#endif