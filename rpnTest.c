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
	char number = '1';
	assertEqual(toInteger(number), 1);
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
	Token token = createToken();
	assertEqual(token.type, 0);
	assertEqual(token.start_point, 0);
	assertEqual(token.end_point, 0);
}

void test_createNode_creates_node_of_Token_type (){
	Token token = createToken();
	Node* tokenNode = create_node(&token);
	assertEqual(((Token*)(tokenNode->data))->type, token.type);
	assertEqual(((Token*)(tokenNode->data))->start_point, token.start_point);
	assertEqual(((Token*)(tokenNode->data))->end_point, token.end_point);
}

void test_add_to_list_adds_the_given_TokenNode_in_the_list (){
	LinkedList list = createList();
	Token token = createToken();
	Node* tokenNode = create_node(&token);
	int result = add_to_list(&list,tokenNode);
	assert(list.head==tokenNode);
	assert(list.tail==tokenNode);
	assertEqual(list.count, 1);
}