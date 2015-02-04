#include "stack.h"
#define STRING char*
#define INT_SIZE sizeof(int)
typedef struct token Token;

int isOperator(char);
int isOperand(char);
int toInteger(STRING);
int isSpace(char);
int operate(int, int, char);
int evaluate(STRING);
STRING getValue(STRING, int, int);
char getSymbol (STRING, int);
LinkedList* populateListWithToken (STRING);

struct token{
	int type;
	int start_point;
	int end_point;
};

Token* createToken(int, int, int);