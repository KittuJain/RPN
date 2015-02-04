#include "expr_assert.h"
#include "rpn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test_isOperator_returns_1_for_add_sign (){
	char symbol = '+';
	assertEqual(isOperator(symbol), 1);
}

void test_isOperator_returns_0_for_non_add_sign (){
	char symbol = '1';
	assertEqual(isOperator(symbol), 0);
}

void test_isOperand_returns_1_for_3 (){
	char symbol = '3';
	assertEqual(isOperand(symbol), 1);
}

void test_isOperand_returns_0_for_other_values (){
	char symbol = 'c';
	assertEqual(isOperand(symbol), 0);
}

void test_toInteger_converts_char_to_Int (){
	STRING number = "1";
	assertEqual(toInteger(number), 1);
}

void test_toInteger_converts_string_to_Int (){
	STRING number = "123";
	assertEqual(toInteger(number), 123);
}

void test_operate_performs_add_if_given_two_operands_and_a_plus_sign (){
	assertEqual(operate(12,12,'+'), 24);
}

void test_operate_performs_add_if_given_two_operands_and_a_minus_sign (){
	assertEqual(operate(24,56,'-'), 32);
}

void test_operate_performs_add_if_given_two_operands_and_a_multiply_sign (){
	assertEqual(operate(4,12,'*'), 48);
}

void test_operate_performs_add_if_given_two_operands_and_a_divide_sign (){
	assertEqual(operate(4,12,'/'), 3);
}

void test_createToken_creates_an_empty_token (){
	Token* token = createToken(0,0,0);
	assertEqual(token->type, 0);
	assertEqual(token->start_point, 0);
	assertEqual(token->end_point, 0);
}

void test_populateListWithToken_gives_the_linked_list_of_tokens_in_the_given_string(){
	LinkedList *list;
	list = populateListWithToken("2 3 +");
	assertEqual(list->count,5);
	assertEqual(((Token*)list->head->data)->type,1);
	assertEqual(((Token*)list->tail->data)->type,2);
}

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