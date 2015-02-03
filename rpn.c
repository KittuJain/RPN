#include "rpn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int toInteger (char numberChar){
	return numberChar - 48;
}

int add (int num1, int num2){
	return num1 + num2;
}

int sub (int num1, int num2){
	return num1 - num2;
}

int mul (int num1, int num2){
	return num1 * num2;
}

int divide (int num1, int num2){
	return num1 / num2;
}

int evaluate(char *expression){
	Stack stack = createStack();
	int i = 0, *sum, *data;

	while(expression[i] != '\0'){
		
		if(expression[i] > 47 && expression[i] < 58){
			data = (int*)calloc(INT_SIZE, 1);
			*data = toInteger(expression[i]);
			push(&stack,data);
		}
		
		if(expression[i] == '+'){
			sum = (int*)calloc(INT_SIZE, 1);
			*sum = add(*(int*)pop(&stack), *(int*)pop(&stack));
			push(&stack,sum);
		}
		if(expression[i] == '-'){
			sum = (int*)calloc(INT_SIZE, 1);
			*sum = sub(*(int*)pop(&stack), *(int*)pop(&stack));
			push(&stack,sum);
		}
		if(expression[i] == '*'){
			sum = (int*)calloc(INT_SIZE, 1);
			*sum = mul(*(int*)pop(&stack), *(int*)pop(&stack));
			push(&stack,sum);
		}
		if(expression[i] == '/'){
			sum = (int*)calloc(INT_SIZE, 1);
			*sum = divide(*(int*)pop(&stack), *(int*)pop(&stack));
			push(&stack,sum);
		}
		i++;
	}
	return *(int*)pop(&stack);
}

