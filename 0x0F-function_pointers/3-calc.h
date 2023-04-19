#ifndef CALCTASK_H
#define CALCTASK_H

#include <stdlib.h>
#include <stdio.h>

/**
 * struct op - Struct op
 *
 * @op: The operator
 * @fanc: The function associated
 */
typedef struct op
{
	char *op;
	int (*fanc)(int k, int r);
} op_t;


int op_add(int k, int r);
int op_sub(int k, int r);
int op_mul(int k, int r);
int op_div(int k, int r);
int op_mod(int k, int r);

int (*get_op_func(char *s))(int, int);

#endif
