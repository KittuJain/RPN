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
	assertEqual(operate(56,24,'-'), 32);
}

void test_operate_performs_add_if_given_two_operands_and_a_multiply_sign (){
	assertEqual(operate(4,12,'*'), 48);
}

void test_operate_performs_add_if_given_two_operands_and_a_divide_sign (){
	assertEqual(operate(12,4,'/'), 3);
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

void test_getValue_gets_the_value_between_two_points (){
	STRING expression = "2 3 +";
	Token *token = createToken(1, 0, 0);
	assertEqual(strcmp(getValue(expression, 0, 0, token), "2"),0);
}

void test_evaluate_evals_the_result_of_1_1_sum_as_2 (){
	String expression = calloc(STRING_SIZE,1);
	strcpy(expression,"1 1 +");
	assertEqual(evaluate(expression).status, 2);
}

void test_evaluate_evals_the_result_of_3_3_sum_as_6 (){
	String expression = calloc(STRING_SIZE,1);
	strcpy(expression,"3 3 +");
	assertEqual(evaluate(expression).status, 6);
}

void test_evaluate_evals_the_result_of_3_2_sum_as_5 (){
	String expression = calloc(STRING_SIZE,1);
	strcpy(expression,"3 2 +");
	assertEqual(evaluate(expression).status, 5);
}

void test_evaluate_evals_the_result_of_2_3_sum_as_5 (){
	String expression = calloc(STRING_SIZE,1);
	strcpy(expression,"2 3 +");
	assertEqual(evaluate(expression).status, 5);
}

void test_evaluate_evals_the_result_of_difference_between_2_3_as_minus_1 (){
	String expression = calloc(STRING_SIZE,1);
	strcpy(expression,"2 3 -");
	assertEqual(evaluate(expression).status, -1);
}

void test_evaluate_evals_the_result_of_product_of_2_3_as_6 (){
	String expression = calloc(STRING_SIZE,1);
	strcpy(expression,"2 3 *");
	assertEqual(evaluate(expression).status, 6);
}
void test_evaluate_evals_the_result_of_division_of_2_3_as_0 (){
	String expression = calloc(STRING_SIZE,1);
	strcpy(expression,"2 3 /");
	assertEqual(evaluate(expression).status, 0);
}

void test_evaluate_evals_the_result_of_2_3_4_sum_diff_as_minus_5 (){
	String expression = calloc(STRING_SIZE,1);
	strcpy(expression,"2 3 4 + -");
	assertEqual(evaluate(expression).status, -5);
}

void test_evaluate_works_fine_with_operators_not_separated_by_spaces (){
	assertEqual(evaluate("5 4+").status,9);
	assertEqual(evaluate("5 4 3+-").status,-2);
}

void test_evaluate_evals_the_result_of_postfix_operation_for_multiple_operators (){
	assertEqual(evaluate("2 4 6 + *").status,20);
	assertEqual(evaluate("5 4 6 5 + + -").status,-10);
	assertEqual(evaluate("5 4 6 5 8 2 + + + + +").status,30);
}

void test_evaluate_evals_the_result_of_postfix_operation_for_multi_digit_operands (){
	assertEqual(evaluate("20 4 *").status,80);
	assertEqual(evaluate("20000 400 +").status,20400);
}

void test_evaluate_evals_the_result_of_postfix_operation_when_operators_are_between_operands (){
	assertEqual(evaluate("2 4 * 2 +").status,10);
	assertEqual(evaluate("2 2 2 * 2 - 3 + +").status, 7);
	assertEqual(evaluate("2 2 2 2 2 * * 2 + + 2 - *").status,20);
	assertEqual(evaluate("2 2 - 2 2 2 * 2 - - -").status,0);
}

// void test_evaluate_returns_error_for_less_operands_or_operators (){
// 	assertEqual(evaluate("2 +").error,1);
// }