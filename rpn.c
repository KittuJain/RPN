#include "rpn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int isOperator(char symbol){
	if(symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/')
		return 1;
	return 0;
}

int isOperand (char number){
	if(number> 47 && number < 58)
		return 1;
	return 0;
}

int isSpace (char ch){
	if(ch == 32)
		return 1;
	return 0;
}

int toInteger (STRING expression){
	int i, number = 0;
	for(i = 0; i < strlen(expression); i++ ){
		number = number*10 + (expression[i] - 48);
	}
	return number;
}

STRING getValue (STRING expression, int start, int end){
	int i, count = 0 ;
	STRING value;
	for(i = start; i <= end; i++){
		value[count] = expression[i];
		count++;
	}
	return value;
}

char getSymbol (STRING expression, int start){
	return expression[start];
}

int operate(int num1, int num2, char operator){
	switch(operator){
		case '+' : return num2 + num1;
		case '-' : return num2 - num1;
		case '*' : return num2 * num1;
		case '/' : return num2 / num1;
		default : return -1;
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
	int count,length,start,type;
	LinkedList* list = calloc(1,sizeof(LinkedList));
	Node_ptr* tokenNode;
	Token* token;

	for(count=0,length= strlen(expression) ; count<length ; count++){

		if(isOperator(expression[count]))
			token = createToken(2,count,count);

		else if(isOperand(expression[count])){
			start = count;
			while(isOperand(expression[count+1]))
				count++;

			token = createToken(1,start,count);
		}

		else
			token = createToken(3,count,count);

		tokenNode = malloc(sizeof(Node_ptr));
		*tokenNode = create_node(token);
		add_to_list(list,*tokenNode);
	}
	return list;
}
