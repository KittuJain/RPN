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

void test_evaluate_evals_the_result_of_3_2_sum_as_5 (){
	String expression = calloc(sizeof(String),1);
	strcpy(expression,"3 2 +");
	assertEqual(evaluate(expression), 5);
}

void test_evaluate_evals_the_result_of_1_1_subtract_as_0 (){
	String expression = calloc(sizeof(String),1);
	strcpy(expression,"1 1 -");
	assertEqual(evaluate(expression), 0);
}

void test_evaluate_evals_the_result_of_3_2_subtract_as_1 (){
	String expression = calloc(sizeof(String),1);
	strcpy(expression,"3 2 -");
	assertEqual(evaluate(expression), 1);
}

void test_evaluate_evals_the_result_of_2_3_subtract_as_minus1 (){
	String expression = calloc(sizeof(String),1);
	strcpy(expression,"2 3 -");
	assertEqual(evaluate(expression), -1);
}

void test_evaluate_evals_the_result_of_3_2_multiply_as_6 (){
	String expression = calloc(sizeof(String),1);
	strcpy(expression,"3 2 *");
	assertEqual(evaluate(expression), 6);
}

void test_evaluate_evals_the_result_of_2_3_divide_as_0 (){
	String expression = calloc(sizeof(String),1);
	strcpy(expression,"2 3 /");
	assertEqual(evaluate(expression), 0);
}

void test_evaluate_evals_the_result_of_3_2_divide_as_1 (){
	String expression = calloc(sizeof(String),1);
	strcpy(expression,"3 2 /");
	assertEqual(evaluate(expression), 1);
}

void test_evaluate_evals_the_result_of_2_3_4_add_minus_as_minus_5 (){
	String expression = calloc(sizeof(String),1);
	strcpy(expression,"2 3 4 + -");
	assertEqual(evaluate(expression), -5);
}

void test_evaluate_evals_the_result_of_2_8_5_minus_add_as_5 (){
	String expression = calloc(sizeof(String),1);
	strcpy(expression,"2 8 5 - +");
	assertEqual(evaluate(expression), 5);
}