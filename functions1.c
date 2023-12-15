#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "monty.h"

/**
 * _swap - swaps the top two elements of the stack.
 * @stack:pointer to the top node of a stack_t doubly linked list.
 * @line_number:current line number of a monty bytecodesfile.
 */
void _swap(stack_t **stack, unsigned int line_number)
{
stack_t *temp;

if ((*stack)->next == NULL || (*stack)->next->next == NULL)
{
set_opcode_tokens_error(stack_error(line_number, "swap"));
return;
}
temp = (*stack)->next->next;
(*stack)->next->next = temp->next;
(*stack)->next->prev = temp;
if (temp->next)
temp->next->prev = (*stack)->next;
temp->next = (*stack)->next;
temp->prev = *stack;
(*stack)->next = temp;
}

/**
 * _add - adds the top two elements of the stack.
 * @stack:pointer to the top node of a stack_t doubly linked list.
 * @line_number:current line number of a monty bytecodesfile.
 *
 * Return: no return.
 */
void _add(stack_t **stack, unsigned int line_number)
{
if ((*stack)->next == NULL || (*stack)->next->next == NULL)
{
set_opcode_tokens_error(stack_error(line_number, "add"));
return;
}
(*stack)->next->next->n += (*stack)->next->n;
_pop(stack, line_number);
}
/**
 * _nop - doesn’t do anything.
 * @stack:pointer to the top node of a stack_t doubly linked list.
 * @line_number:current line number of a monty bytecodesfile.
 * Return: no return.
 */
void _nop(stack_t **stack, unsigned int line_number)
{
(void)stack;
(void)line_number;
}
