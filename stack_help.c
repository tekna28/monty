#include "monty.h"
#include <stdio.h>
#include <stddef.h>

/**
 * free_stack - Frees a stack_t stack.
 * @stack: pointer to the top or bottom of
 *         the stack_t doubly linked list.
 */
void free_stack(stack_t **stack)
{
	stack_t *temp = *stack;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

/**
 * init_stack - Initializes a stack_t stack.
 * @stack: pointer to an unitialized stack_t stack.
 *
 * Return: EXIT_SUCCESS (Success)
 *         or EXIT_FAILURE (error).
 */
int init_stack(stack_t **stack)
{
	stack_t *s;

	s = malloc(sizeof(stack_t));
	if (s == NULL)
		return (malloc_error());

	s->n = 0;
	s->prev = NULL;
	s->next = NULL;

	*stack = s;

	return (EXIT_SUCCESS);
}

/**
 * check_mode - Checks if a stack_t doubly linked
 *              list is in stack or queue mode.
 * @stack: pointer to the top or bottom
 *         of a stack_t doubly linked list.
 *
 * Return: If the stack_t is in stack mode - (0).
 *         If the stack_t is in queue mode - (1).
 *         Otherwise - (2).
 */
int check_mode(stack_t *stack)
{
	if (stack->n == 0)
		return (0);
	else if (stack->n == 1)
		return (1);
	else
	return (2);
}
