#include "stack.h"
#define String char*
#define INT_SIZE sizeof(int)

int toInteger (char);
int add (int, int);
int sub (int, int);
int mul (int, int);
int divide (int, int);
int evaluate(char *expression);