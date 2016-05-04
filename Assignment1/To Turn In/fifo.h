#include "pcb_h.h"
#include <stdbool.h>
#ifndef FIFOq_h
#define FIFOq_h

typedef struct FifoNode {
	PCB_p data;
	struct FifoNode *next_node;
} FifoNode;
typedef FifoNode * FifoNode_p;

// constructor and initializer
typedef struct FIFOq {
	FifoNode* head;
	FifoNode* tail;
	int size;
}FIFOq;
typedef FIFOq * FIFOq_p;

FIFOq_p FiFoCreateQueue();
FifoNode_p FifoCreateNode(PCB_p *thePCB);
bool Fifo_is_empty(FIFOq *theFIFOq);
void Fifo_enqueue(FIFOq_p theFIFOq, FifoNode_p theFifoNode);
FifoNode_p Fifo_dequeue(FIFOq *theFIFOq);
void Fifo_toString(FIFOq *theFIFOq);

#endif
