#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

LinkedList createList(void){
	LinkedList list = {NULL,NULL,0};
	return list;
}

Node_ptr create_node(void *data){
	Node_ptr node;
	node = malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	return node;
}

int add_to_list(LinkedList* list,Node_ptr node){
	if(list->head == NULL || list->tail == NULL){
		list->head = node;
		list->tail = node;
	}
	else{
		list->tail->next = node;
		list->tail = node;		
	}
	list->count++;
	return 1;
}

void *get_first_element(LinkedList list){
	return list.head->data;
}

void *get_last_element(LinkedList list){
	return list.tail->data;
}

void traverse(LinkedList list, void (*function_ptr)(void *data)){
	Node_ptr walker = list.head;
	while(walker != NULL){
		function_ptr(walker->data);
		walker = walker->next;
	}
}

void* getElementAt(LinkedList list, int index){
	int count = 0;
	Node_ptr walker = list.head;
	while(walker != NULL){
		if(count==index)
			return walker->data;
		count++;
		walker = walker->next;
	}
	return NULL;
}

int indexOf(LinkedList list, void* element){
	int count = 0;
	Node_ptr walker = list.head;
	while(walker != NULL){
		if(walker->data==element)
			return count;
		count++;
		walker = walker->next;
	}
	return -1;
}

void* deleteElementAt(LinkedList *list, int index) {
	int count = 0;
	Node_ptr walker = list->head;
	Node_ptr previousNode = NULL;

	while(walker != NULL){
		
		if(index == 0){
			list->head = walker->next;
		
			if(list->count == 1){
				list->tail = NULL;
			}
		
			list->count--;
			return walker->data;
		}
		
		if(count == index){
			if(index == (list->count-1)){
				list->tail = previousNode;
				list->count--;
				return walker->data;
			}
			previousNode->next = walker->next;
			list->count--;
			return walker->data;
		}

		previousNode = walker;
		walker = walker->next;
		count++;
	}
	return NULL;
}

int asArray(LinkedList list, void **array){
	int counter = 0;
	Node_ptr walker = list.head;
	while(walker != NULL){
		array[counter] = walker->data;
		counter++;
		walker = walker->next;
	}
	return 1;
}

LinkedList* filter(LinkedList list, int (*function_ptr)(void* data)){
	int counter = 0;

	LinkedList *filteredList ;
	Node_ptr walker = list.head;

	filteredList = calloc(sizeof(LinkedList),1);


	while(walker != NULL){
		if(function_ptr(walker->data)==1){
			Node *node = create_node(walker->data);
			add_to_list(filteredList, node);
		}
		walker = walker->next;
	}

	return filteredList;
}