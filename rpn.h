#include "stack.h"
#include "queue.h"
#define STRING char*
#define INT_SIZE sizeof(int)
#define CHAR_SIZE sizeof(char)
#define STRING_SIZE sizeof(STRING)
typedef struct token Token;
typedef struct token* Token_ptr;
typedef struct result Result;

int isOperator(char);
int isOperand(char);
int toInteger(STRING);
int isSpace(char);
int operate(int, int, char);
Result evaluate(STRING);
STRING getValue(STRING, int, int, Token*);
char getSymbol (STRING, int);
Token* createToken(int, int, int);
LinkedList* populateListWithToken (STRING);
Result generateResult (LinkedList*, Stack, STRING, Token*);
void pushValues (Stack, STRING, Token*);
void popValuesAndCalculateResult (Stack, Token*, STRING);
STRING infixToPostfix(STRING expression);
void populateStackAndQueue (LinkedList*, Token_ptr, STRING, Queue, Stack);
int getPrecedence(STRING);
STRING stringifyQueue(Queue operands, STRING);
int newPrecedenceGreater(STRING, Stack);


struct token{
	int type;
	int start_point;
	int end_point;
};

struct result{
	int error;
	int status;	
};