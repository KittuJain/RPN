#include "stack.h"
#define STRING char*
#define INT_SIZE sizeof(int)
#define STRING_SIZE sizeof(STRING)
typedef struct token Token;
typedef struct result Result;

int isOperator(char);
int isOperand(char);
int toInteger(STRING);
int isSpace(char);
int operate(int, int, char);
int evaluate(STRING);
STRING getValue(STRING, int, int, Token*);
char getSymbol (STRING, int);
Token* createToken(int, int, int);
LinkedList* populateListWithToken (STRING);

struct token{
	int type;
	int start_point;
	int end_point;
};

struct result{
	int error;
	int status;	
};
