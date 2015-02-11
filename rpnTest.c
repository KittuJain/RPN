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
	Token_ptr token = createToken(0,0,0);
	assertEqual(token->type, 0);
	assertEqual(token->start_point, 0);
	assertEqual(token->end_point, 0);
}

void test_populateListWithToken_gives_the_linked_list_of_tokens_in_the_given_string(){
	LinkedList *list;
	list = populateListWithToken("2 3 +");
	assertEqual(list->count,5);
	assertEqual(((Token_ptr)list->head->data)->type,1);
	assertEqual(((Token_ptr)list->tail->data)->type,2);
}

void test_populateListWithToken_gives_the_linked_list_of_tokens_of_long_string(){
	LinkedList *list;
	list = populateListWithToken("2 3 4 + -");
	assertEqual(list->count,9);
	assertEqual(((Token_ptr)list->head->data)->type,1);
	assertEqual(((Token_ptr)list->tail->data)->type,2);
}

void test_getValue_gets_the_value_between_two_points (){
	STRING expression = "2 3 +";
	Token_ptr token = createToken(1, 0, 0);
	assertEqual(strcmp(getValue(expression, 0, 0, token), "2"),0);
}

void test_getValue_gets_the_value_between_given_two_points (){
	STRING expression = "2 30 +";
	Token_ptr token = createToken(1, 2, 3);
	assertEqual(strcmp(getValue(expression, 2, 3, token), "30"),0);
}

void test_generateResult_generates_the_result_of_the_expression_of_sum_of_1_1 (){
	Token_ptr token;
	LinkedList *list = populateListWithToken("1 1 +");
	Stack stack = createStack();
	assertEqual(generateResult(list, stack, "1 1 +", token).status,2);
}

void test_generateResult_generates_the_result_of_long_expressions_also (){
	Token_ptr token;
	LinkedList *list = populateListWithToken("5 4 6 5 8 2 + + + + +");
	Stack stack = createStack();
	assertEqual(generateResult(list, stack, "5 4 6 5 8 2 + + + + +", token).status,30);
}

void test_evaluate_evals_the_result_of_1_1_sum_as_2 (){
	STRING expression = calloc(STRING_SIZE,1);
	strcpy(expression,"1 1 +");
	assertEqual(evaluate(expression).status, 2);
}

void test_evaluate_evals_the_result_of_3_3_sum_as_6 (){
	STRING expression = calloc(STRING_SIZE,1);
	strcpy(expression,"3 3 +");
	assertEqual(evaluate(expression).status, 6);
}

void test_evaluate_evals_the_result_of_3_2_sum_as_5 (){
	STRING expression = calloc(STRING_SIZE,1);
	strcpy(expression,"3 2 +");
	assertEqual(evaluate(expression).status, 5);
}

void test_evaluate_evals_the_result_of_2_3_sum_as_5 (){
	STRING expression = calloc(STRING_SIZE,1);
	strcpy(expression,"2 3 +");
	assertEqual(evaluate(expression).status, 5);
}

void test_evaluate_evals_the_result_of_difference_between_2_3_as_minus_1 (){
	STRING expression = calloc(STRING_SIZE,1);
	strcpy(expression,"2 3 -");
	assertEqual(evaluate(expression).status, -1);
}

void test_evaluate_evals_the_result_of_product_of_2_3_as_6 (){
	STRING expression = calloc(STRING_SIZE,1);
	strcpy(expression,"2 3 *");
	assertEqual(evaluate(expression).status, 6);
}
void test_evaluate_evals_the_result_of_division_of_2_3_as_0 (){
	STRING expression = calloc(STRING_SIZE,1);
	strcpy(expression,"2 3 /");
	assertEqual(evaluate(expression).status, 0);
}

void test_evaluate_evals_the_result_of_2_3_4_sum_diff_as_minus_5 (){
	STRING expression = calloc(STRING_SIZE,1);
	strcpy(expression,"2 3 4 + -");
	assertEqual(evaluate(expression).status, -5);
}

void test_evaluate_works_fine_with_operators_not_separated_by_spaces (){
	assertEqual(evaluate("5 4+").status,9);
	assertEqual(evaluate("5 4 3+-").status,-2);
}

void test_evaluate_evals_the_result_of_2_4_6_sum_mul_as_20 (){
	assertEqual(evaluate("2 4 6 + *").status,20);
}

void test_evaluate_evals_the_result_of_5_4_6_5_sum_sum_minus_as_minus_10 (){
	assertEqual(evaluate("5 4 6 5 + + -").status,-10);
}

void test_evaluate_evals_the_result_of_5_4_6_5_8_2_sum_sum_sum_sum_sum_as_30 (){
	assertEqual(evaluate("5 4 6 5 8 2 + + + + +").status,30);
}

void test_evaluate_evals_the_result_of_20_4_mul_as_80 (){
	assertEqual(evaluate("20 4 *").status,80);
}

void test_evaluate_evals_the_result_of_20000_400_sum_as_20400 (){
	assertEqual(evaluate("20000 400 +").status,20400);
}

void test_evaluate_evals_the_result_of_2_4_mul_2_sum_as_10 (){
	assertEqual(evaluate("2 4 * 2 +").status,10);
}

void test_evaluate_evals_the_result_of_2_2_2_mul_2_minus_3_sum_sum_as_7 (){
	assertEqual(evaluate("2 2 2 * 2 - 3 + +").status, 7);
}

void test_evaluate_evals_the_result_of_2_2_2_2_2_mul_mul_2_sum_sum_2_minus_mul_as_20(){
	assertEqual(evaluate("2 2 2 2 2 * * 2 + + 2 - *").status,20);
}

void test_evaluate_evals_the_result_of_2_2_minus_2_2_2_mul_2_minus_minus_minus_as_0 (){
	assertEqual(evaluate("2 2 - 2 2 2 * 2 - - -").status,0);
}

void test_evaluate_returns_1_when_there_are_less_operands (){
	assertEqual(evaluate("2 -").error,1);
}

void test_evaluate_returns_1_when_there_are_more_operators (){
	assertEqual(evaluate("2 - +").error,1);
}

void test_evaluate_returns_0_for_fair_calculation (){
	assertEqual(evaluate("2 2 +").error,0);
}

void test_getPrecedence_gets_precedence_of_an_operator (){
	assertEqual(getPrecedence("+"),2);
	assertEqual(getPrecedence("-"),2);
	assertEqual(getPrecedence("*"),3);
	assertEqual(getPrecedence("/"),3);
}

void test_stringifyQueue_stringifies_the_elements_of_queue (){
	Queue operands = createQueue();
	enqueue(&operands, (void*)"2");
	enqueue(&operands, (void*)"3");
	enqueue(&operands, (void*)"+");
	assertEqual(strcmp(stringifyQueue(operands, "2 + 3"), "2 3 +"),0);
}

void test_newPrecedenceGreater_returns_true_when_operator_greater (){
	STRING operator = "*";
	Stack operators = createStack();
	push(&operators, (void*)"+");
	assertEqual(newPrecedenceGreater(operator, operators),1);
}

void test_infixToPostfix_converts_an_infix_expression_to_postfix (){
	STRING expression = calloc(STRING_SIZE,1);
	strcpy(expression,"1 1 +");
	assertEqual(strcmp(infixToPostfix("1 + 1"),expression),0);
}

void test_infixToPostfix_converts_an_infix_expression_to_postfix_for_mul_operation (){
	STRING expression = calloc(STRING_SIZE,1);
	strcpy(expression,"2 4 *");
	assertEqual(strcmp(infixToPostfix("2 * 4"),expression),0);
}

void test_infixToPostfix_converts_an_infix_expression_to_postfix_for_mul_operation_on_twoDigit_nums (){
	STRING expression = calloc(STRING_SIZE,1);
	strcpy(expression,"20 4 *");
	assertEqual(strcmp(infixToPostfix("20 * 4"),expression),0);
}

void test_infixToPostfix_converts_an_infix_expression_to_postfix_for_multiple_digit_numbers (){
	STRING expression = calloc(STRING_SIZE,1);
	strcpy(expression,"20000 400 +");
	assertEqual(strcmp(infixToPostfix("20000 + 400"),expression),0);
}

void test_infixToPostfix_converts_an_infix_expression_to_postfix_for_minus_operator (){
	STRING expression = calloc(STRING_SIZE,1);
	strcpy(expression,"2 2 -");
	assertEqual(strcmp(infixToPostfix("2 - 2"),expression),0);
}

void test_infixToPostfix_converts_an_infix_expression_to_postfix_for_complex_operation (){
	STRING expression = calloc(STRING_SIZE,1);
	strcpy(expression,"2 4 * 2 +");
	assertEqual(strcmp(infixToPostfix("2 * 4 + 2"),expression),0);
}

void test_infixToPostfix_converts_an_infix_expression_to_postfix_for_complex_expressions (){
	assertEqual(strcmp(infixToPostfix("3 + 4 * 2 / 1"),"3 4 2 * 1 / +"),0);
}