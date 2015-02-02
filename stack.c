#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Stack createStack(void){
	LinkedList* list = calloc(sizeof(LinkedList), 1);
	Stack stack = {list, list->tail};
	return stack;
}

int push (Stack *stack, void* data){
	Node_ptr node = create_node(data);
	int count = add_to_list(stack->list,node);
	return (count < 0) ? -1 : stack->list->count;
}

void* pop (Stack *stack){
	int count = 0;
	Node_ptr walker = stack->list->head;
	Node_ptr previousNode = NULL;
	int index = stack->list->count-1;

	if(stack->list->count == 0)
		return (void*)-1;
	
	while(walker != NULL){
		if(count == index){
			if(index == (stack->list->count-1)){
				stack->list->tail = previousNode;
				stack->list->count--;
				return walker->data;
			}
			previousNode->next = walker->next;
			stack->list->count--;
			return walker->data;
		}
		previousNode = walker;
		walker = walker->next;
		count++;
	}
	return NULL;
}