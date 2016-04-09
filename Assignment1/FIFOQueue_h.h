#include "pcb_h.h"
#ifndef FIFOQUEUE_H
#define FIFOQUEUE_H

typedef struct Node {
	PCB_p init_pcb; 
	struct Node* next_node;
} Node;

// constructor and initializer
typedef struct FIFOq {
	Node* node;
	int size;
	FIFOq(Node* n): node(n),size(1) {}
	FIFOq() : node(),size(0) {}
} FIFOq;

// FIFOq::FIFOq(Node* node_): node(node_),size(1) {}

bool FIFOq_is_empty(FIFOq);
int FIFOq_enqueue(FIFOq,Node);
int FIFOq_dequeue(FIFOq);
char* FIFOq_toString(FIFOq);

#endif 