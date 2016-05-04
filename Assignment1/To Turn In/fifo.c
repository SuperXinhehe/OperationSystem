#include <stdio.h>
#include <stdlib.h>

#include "fifo.h"

/*
 * Creates the queue and returns a pointer to the new queue.
 */
FIFOq_p FiFoCreateQueue(){
	FIFOq_p theFIFOq = malloc(sizeof(FIFOq));
	theFIFOq -> head = NULL;
	theFIFOq -> tail = NULL;
	theFIFOq -> size = 0;
	return theFIFOq;
}

/*
 * Creates a node containing the given PCB pointer.
 */
FifoNode_p FifoCreateNode(PCB_p *thisData){
	FifoNode_p result = malloc(sizeof(FifoNode));
	result -> data = *thisData;
	result -> next_node = NULL;
	return result;
}

/*
 * Returns true if queue is empty, false otherwise.
 */
bool Fifo_is_empty(FIFOq *thisQueue) {
	return (thisQueue -> head == NULL);
}

/**
 * Enqueue's a node to the back of the queue.
 */
void Fifo_enqueue(FIFOq *thisQueue, FifoNode_p thisNode) {
	if(thisQueue -> head == NULL){
		thisQueue -> head = thisNode;
		(thisQueue -> head)->next_node = thisQueue -> tail;
	}
	else{
		(thisQueue->tail)->next_node = thisNode;
	}
	thisQueue -> tail = thisNode;
	thisNode -> next_node = NULL;
	thisQueue -> size += 1;
}

/*
 * Removes the earliest added PCB to this queue and returns the node.
 */
FifoNode_p Fifo_dequeue(FIFOq *thisQueue) {
	FifoNode_p result = thisQueue->head;
	if(thisQueue -> head != NULL){
		thisQueue -> head = thisQueue -> head -> next_node;
		thisQueue -> size = thisQueue -> size -1;
	}
	return result;
}

/*
 * Prints out String representation of the FIFO Queue, in the format of
 * Q:Count=1: P1-* contents: [contents of most recently added PCB]
 */
void Fifo_toString(FIFOq *theFIFOq) {
	if(Fifo_is_empty(theFIFOq)) {
		printf("Empty Queue");
	}
	else {
		FifoNode_p root = theFIFOq->head;
		int i = 2;
		printf("Q:Count=%d: ",theFIFOq->size);
		printf("P1-");
		while (root -> next_node != NULL) {
			printf("P%d-", i);
			root = root -> next_node;
			i++;
		}
		printf("* ");
	}
}
