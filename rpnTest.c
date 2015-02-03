#include "expr_assert.h"
#include "rpn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test_evaluate_evals_the_result_of_1_1_sum_as_2 (){
	String expression = calloc(sizeof(String),1);
	strcpy(expression,"1 1 +");
	assertEqual(evaluate(expression), 2);
}

void test_evaluate_evals_the_result_of_3_3_sum_as_6 (){
	String expression = calloc(sizeof(String),1);
	strcpy(expression,"3 3 +");
	assertEqual(evaluate(expression), 6);
}