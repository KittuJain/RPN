#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Queue createQueue(void){
	LinkedList* list = calloc(sizeof(LinkedList), 1);
	Queue queue = {list, list->head, list->tail};
	return queue;
}

int enqueue(Queue *queue, void* data){
	int count = add_to_list(queue->list, create_node(data));
	queue->front = queue->list->head;
	queue->rear = queue->list->tail;
	return (count < 0) ? -1 : queue->list->count;
}

void* dequeue(Queue* queue){
	int count = queue->list->count;
	return (count == 0) ? (void*)(-1) : deleteElementAt(queue->list, 0);	
}