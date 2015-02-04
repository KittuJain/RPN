#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Stack createStack(void){
	LinkedList* list = calloc(sizeof(LinkedList), 1);
	Stack stack = {list, list->head};
	return stack;
}

int push (Stack *stack, void* data){
	Node_ptr node = create_node(data);
	int count = add_to_list(stack->list,node);
	stack->top = stack->list->head;
	return (count < 0) ? -1 : stack->list->count;
}

void* pop (Stack *stack){
	int count = stack->list->count;
	return (count == 0) ? (void*)(-1) : deleteElementAt(stack->list, count - 1);
}