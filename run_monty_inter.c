#define  _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "monty.h"

/**
 * free_tokens - frees the global op_toks array of strings.
 * Return: no return.
 */
void free_tokens(void)
{
size_t i = 0;
if (op_toks == NULL)
return;
for (i = 0; op_toks[i]; i++)
free(op_toks[i]);
free(op_toks);
}
/**
 * get_opcode_functions - matches an opcode with its corresponding function.
 * @opcode: the opcode to match.
 * Return: pointer to the corresponding function.
 */
void (*get_opcode_functions(char *opcode))(stack_t**, unsigned int)
{
int i;
instruction_t opcode_fs[] = {
{"push", _push},
{"pall", _pall},
{"pint", _pint},
{"pop", _pop},
{"swap", _swap},
{"add", _add},
{"nop", _nop},
{NULL, NULL}
};
for (i = 0; opcode_fs[i].opcode; i++)
{
if (strcmp(opcode, opcode_fs[i].opcode) == 0)
return (opcode_fs[i].f);
}
return (NULL);
}
/**
 * run_monty_inter - executes a monty bytecode script.
 * @F: file descriptor.
 * Return: EXIT_SUCCESS (Success)
 *         or error (Failure).
 */
int run_monty_inter(FILE *F)
{
stack_t *stack = NULL;
char *line = NULL;
size_t len = 0;
size_t status = EXIT_SUCCESS;
unsigned int line_number = 0;
unsigned int len_prev_tok = 0;
void (*opcode_f)(stack_t**, unsigned int);

if (init_stack(&stack) == EXIT_FAILURE)
return (EXIT_FAILURE);
while (getline(&line, &len, F) != -1)
{
line_number++;
if (op_toks[0][0] == '#')
{
free_tokens();
continue;
}
opcode_f = get_opcode_functions(op_toks[0]);
if (opcode_f == NULL)
{
free_stack(&stack);
status = unknown_instruction(op_toks[0], line_number);
free_tokens();
break;
}
len_prev_tok = token_len();
opcode_f(&stack, line_number);
if (token_len() != len_prev_tok)
{
if (op_toks && op_toks[len_prev_tok])
status = atoi(op_toks[len_prev_tok]);
else
status = EXIT_FAILURE;
free_tokens();
break;
}
free_tokens();
}
free_stack(&stack);
if (line != NULL && *line == 0)
{
free(line);
return (malloc_error());
}
free(line);
return (status);
}
