#include "pcb.c"
#include "pcb_h.h"
#include "FIFOQueue_h.h"
#include <stdio.h>
#define EMPTY_QUEUE 1
#define NO_ERROR 0

bool FIFOq_is_empty(FIFOq *queue) {
	if(!queue->node) {
		return true;
	}
	else return false;
}

int FIFOq_enqueue(FIFOq *queue, Node *e) {
	queue->size = queue->size + 1;
	if(FIFOq_is_empty(queue)) {
		queue->node = e;
	}
	else {
		Node *root = queue->node;
		while(root->next_node) {
			root = root->next_node;
		}
		root->next_node = (Node*) malloc(sizeof(Node));
		root->next_node = e;
	}
	printf("PCB ENQUEUE: %s",PCB_toString(e->init_pcb));
	return 0;
}

int FIFOq_dequeue(FIFOq *queue) {
	if(FIFOq_is_empty(queue)) {
		printf("%s","EMPTY QUEUE\n");
	}
	else {
		queue->size = queue->size - 1;
		PCB_p p;
		Node *root = queue->node;
		p = root->init_pcb;
		printf("%s","PCB DEQUEUE: ");
		printf("%s",PCB_toString(p));
		PCB_deconstruct(p);
		queue->node = queue->node->next_node;
		root->init_pcb = NULL;
	}
	return 0;
}
// print out the queue for remaining pcbs
char * FIFOq_toString(FIFOq *queue) {
	char * c = new char[255];
	if(FIFOq_is_empty(queue)) {
		sprintf(c,"Empty Queue");
		return c;
	}
	else {
		Node *root = queue->node;
		PCB_p p;
		char content[255];
		strcpy(content,"Q:Count=%d: ",queue->size);
		int i = 1;
		printf("Q:Count=%d: ",queue->size);
		while(root != NULL) {
			// every node should have a init_pcb
			p = root->init_pcb;
			if(i==1) {
				printf("P%ld-",PCB_get_pid(p));
			}
			else printf(">P%ld-",PCB_get_pid(p));
			// sprintf(c,"content: %s\n",);
			strcat(content,PCB_toString(p));
			strcat(content,";");
			root = root->next_node;
			i = i + 1;
		}
		printf("* contents:%s",contents);
		return c;
	}
}
