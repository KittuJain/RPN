#include "rpn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isOperator(char symbol){
	STRING operators = "+-*/\0";
	int i = 0;
	
	while(operators[i] != '\0'){
		if(operators[i] == symbol)
			return 1;
		i++;
	}
	return 0;
}

int isOperand (char number){
	return (number > 47 && number < 58) ? 1 : 0;
}

int isSpace (char ch){
	return (ch == 32) ? 1 : 0;
}

int toInteger (STRING expression){
	int i = 0, number = 0;
	while(i < strlen(expression)){
		number = number*10 + (expression[i] - 48);
		i++;
	}
	return number;
}

STRING getValue (STRING expression, int start, int end, Token *token){
	int i = start, count = 0 ;
	STRING value;
	value = malloc(STRING_SIZE * (token->end_point - token->start_point));
	while(i <= end){
		value[count] = expression[i];
		count++;
		i++;
	}
	return value;
}

char getSymbol (STRING expression, int start){
	return expression[start];
}

int operate(int num1, int num2, char operator){
	switch(operator){
		case '+' : return num1 + num2;
		case '-' : return num1 - num2;
		case '*' : return num1 * num2;
		case '/' : return num1 / num2;
		default  : return -1;
	}
}

Token* createToken(int type,int start,int end){
	Token* token;
	token = malloc(sizeof(Token));
	token->type = type;
	token->start_point = start;
	token->end_point = end;
	return token;
}

LinkedList* populateListWithToken (STRING expression){
	int count, length, start, type;
	LinkedList* list = calloc(1,sizeof(LinkedList));
	Node_ptr* tokenNode;
	Token* token;

	for(count = 0, length = strlen(expression) ; count < length ; count++){

		if(isOperand(expression[count])){
			start = count;
			while(isOperand(expression[count+1]))
				count++;
			token = createToken(1,start,count);
		}
		if(isOperator(expression[count]))
			token = createToken(2,count,count);

		if(isSpace(expression[count]))
			token = createToken(3,count,count);
		
		tokenNode = calloc(sizeof(Node_ptr),1);
		*tokenNode = create_node(token);
		add_to_list(list,*tokenNode);
	}
	return list;
}

void pushValues (Stack stack, STRING expression, Token *token){
	int *value;
	value = malloc(INT_SIZE);
	*value = toInteger(getValue(expression, token->start_point, token->end_point, token));
	push(&stack, value);
}

void popValuesAndCalculateResult (Stack stack, Token *token, STRING expression){
	char symbol;
	int *calculatedResult;
	symbol = getSymbol(expression, token->start_point);
	calculatedResult = (int*)calloc(INT_SIZE, 1);
	*calculatedResult = operate(*(int*)pop(&stack), *(int*)pop(&stack), symbol);
	push(&stack, calculatedResult);
}

Result generateResult (LinkedList *list, Stack stack, STRING expression, Token *token){
	Node_ptr walker = list->head;
	Result result = {0,0};
	int operatorCount = 0, operandCount = 0;
	while(walker != NULL){
		token = ((Token*)(walker->data));
		if(token -> type == 1){
			pushValues(stack, expression, token);
			operandCount ++;
		}

		if(token -> type == 2){
			if(stack.list->count <= 1) return (Result){1,0};
			popValuesAndCalculateResult(stack, token, expression);
			operatorCount++;
		}
		walker = walker->next;
	}
	if(operandCount != operatorCount+1) return (Result){1,0};	
	return (Result){0, *(int*)pop(&stack)};
}

Result evaluate (STRING expression){
	Token *token;
	LinkedList *list = populateListWithToken(expression);
	return generateResult(list, createStack(), expression, token);
}