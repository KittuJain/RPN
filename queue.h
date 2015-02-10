#include "linkedList.h"
typedef struct queue Queue;

struct queue{
	LinkedList* list;
	Node_ptr front;
	Node_ptr rear;
};

Queue createQueue(void);
int enqueue(Queue*, void*);
void* dequeue(Queue*);