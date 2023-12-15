#include <stdio.h>
#include <stddef.h>
#include "monty.h"

/**
 * pint_error - prints pint error message.
 *
 * @line_number: line number where error occurred.
 * Return: EXIT_FAILURE
 */
int pint_error(unsigned int line_number)
{
fprintf(stderr, "L%d: can't pint, the stack is empty\n", line_number);
return (EXIT_FAILURE);
}

/**
 * pop_error - prints pop error message.
 *
 * @line_number: Line number where error occured.
 * Return: EXIT_FAILURE
 */
int pop_error(unsigned int line_number)
{
fprintf(stderr, "L%u: can't remove top elt from empty stack\n", line_number);
return (EXIT_FAILURE);
}
/**
 * stack_error - prints monty math function error message.
 *
 * @line_number: line number where error occurred.
 * @op: operation where error occurred.
 * Return: EXIT_FAILURE
 */
int stack_error(unsigned int line_number, char *op)
{
fprintf(stderr, "L%u: can't %s, the stack is too short\n", line_number, op);
return (EXIT_FAILURE);
}
