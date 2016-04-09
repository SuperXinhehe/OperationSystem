#include "pcb.c"
#include "pcb_h.h"
#include <stdio.h>
int main(int argc, char* argv[]) {
	// FIFOq *q = new FIFOq();
	// printf("if the queue is empty:%s \n",FIFOq_is_empty(q) ? "true":"false");
	PCB_p raw_pcb = PCB_construct();
	PCB_p pcb2 = PCB_construct();
	PCB_init(raw_pcb);
	PCB_init(pcb2);
	PCB_set_pid(raw_pcb,2);
	PCB_set_pid(pcb2,4);
	printf("%s",PCB_toString(raw_pcb));
	printf("%s","\n");
	printf("%s",PCB_toString(pcb2));
	printf("%s","\n");
}