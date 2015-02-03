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

int evaluate(char *expression){
	Stack stack = createStack();
	int i = 0, *sum, *data, value1, value2;

	while(expression[i] != '\0'){

		if(expression[i] != 32 && expression[i] != 43){
			data = (int*)calloc(INT_SIZE, 1);
			*data = toInteger(expression[i]);
			push(&stack,data);
		}
		if(expression[i] == '+'){
			sum = (int*)calloc(INT_SIZE, 1);
			value1 = *(int*)pop(&stack);
			value2 = *(int*)pop(&stack);
			*sum = add(value1, value2);
			push(&stack,sum);
		}
		i++;
	}
	return *(int*)pop(&stack);
}

