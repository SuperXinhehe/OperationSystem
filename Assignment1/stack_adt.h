// interface (stack_adt.h)
#ifndef STACK_ADT
#define STACK_ADT

const int capacity = 10;
typedef struct {
	int items[capacity];
	int top;
} StackADT;

void clear(StackADT* stack);
int size(StackADT* stack);
int pop(StackADT* stack);
void push(StackADT* stack,int value);

#endif STACK_ADT
