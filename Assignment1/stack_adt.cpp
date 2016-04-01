#include "stack_adt.h"
void clear(StackADT* stack) {
	stack->top = -1;
}

int size(StackADT* stack) {
	return stack-> top + 1;
}

int pop(StackADT* stack) {
	stack->top -= 1;
	return stack->items[stack->top+1];
}

void push(StackADT* stack,int value) {
	stack->top += 1;
	stack->items[stack->top] = value;
}

