#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "monty.h"

char **op_toks;

/**
 * _push - The opcode push pushes an element to the stack.
 *
 *@stack: pointer to the top node of stack_t linked list.
 *@line_number: current line number of the monty bytecodefile.
 * Return: no return.
 */
void _push(stack_t **stack, unsigned int line_number)
{
  stack_t *temp, *new;
	int i;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		set_opcode_tokens_error(malloc_error());
		return;
	}

	if (op_toks[1] == NULL)
	{
		set_opcode_tokens_error(no_int_error(line_number));
		return;
	}

	for (i = 0; op_toks[1][i]; i++)
	{
		if (op_toks[1][i] == '-' && i == 0)
			continue;
		if (op_toks[1][i] < '0' || op_toks[1][i] > '9')
		{
			set_opcode_tokens_error(no_int_error(line_number));
			return;
		}
	}
	new->n = atoi(op_toks[1]);
	/* INSERTION AT FRONT (stack mode)*/
	if (check_mode(*stack) == 0)
	{
		temp = (*stack)->next;
		new->prev = *stack;
		new->next = temp;
		if (temp)
			temp->prev = new;
		(*stack)->next = new;
	}
	/* INSERTION AT END (queue mode) */
	else
	{
		temp = *stack;
		while (temp->next)
			temp = temp->next;
		new->prev = temp;
		new->next = NULL;
		temp->next = new;
	}
}

/**
 * _pall - The opcode pall prints all the values on
 *        the stack, starting from the top of the stack.
 *
 *@stack: pointer to the top node of stack_t linked list.
 *@line_number: current line number of the monty bytecodefile.
 * Return: no return.
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = (*stack)->next;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
	(void)line_number;
}
