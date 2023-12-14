#include "monty.h"
#include <stdio.h>
#include <stddef.h>

/**
 * token_len - gets the length of current
 *             op_toks (opcode tokens).
 *
 * Return: Length of current op_toks.
 */
unsigned int token_len(void)
{
	unsigned int len_toks = 0;

	while (op_toks[len_toks])
		len_toks++;
	return (len_toks);
}

/**
 * set_opcode_tokens_error - Sets the last element of
 *                           op_toks (opcode tokens)
 *                           to be an error code.
 *
 *@error: integer.
 */
void set_opcode_tokens_error(int error)
{
  int len_toks = 0;
  int i = 0;
  char **new_toks = NULL;
  (void) error;
	len_toks = token_len();
	new_toks = malloc(sizeof(char *) * (len_toks + 2));
	if (op_toks == NULL)
	{
		malloc_error();
		return;
	}
	while (i < len_toks)
	{
		new_toks[i] = op_toks[i];
		i++;
	}
	new_toks[i] = NULL;
	free(op_toks);
	op_toks = new_toks;
}
