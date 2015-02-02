#define String char*
typedef struct linked_list LinkedList;
typedef struct node Node;
typedef struct node* Node_ptr;
typedef struct student Student;

struct linked_list{
	Node_ptr head;
	Node_ptr tail;
	int count;
};

struct node{
	void* data;
	Node_ptr next;
};

struct student{
	int id;
	int marks;
};

LinkedList createList(void);
Node* create_node(void *data);
int add_to_list(LinkedList *,Node *);
void* get_first_element(LinkedList);
void* get_last_element(LinkedList);
void traverse(LinkedList, void (*)(void *data));
void* getElementAt(LinkedList, int);
int indexOf(LinkedList, void *);
void* deleteElementAt(LinkedList*, int);
int asArray(LinkedList, void **);
LinkedList * filter(LinkedList, int (*)(void *));