#include "stack.h"
#define STRING char*
#define INT_SIZE sizeof(int)
typedef struct token Token;

int isOperator(char);
int isOperand(char);
int toInteger(char);
int operate(int, int, char);

struct token{
	int type;
	int start_point;
	int end_point;
};

Token createToken();