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

int toInteger (char numberChar){
	return numberChar - 48;
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

Token createToken (){
	Token token = {0,0,0};
	return token;
}