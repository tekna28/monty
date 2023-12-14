#include "monty.h"
#include <stdio.h>

/**
 * usage_error - prints an error message if the user
 *               does not give any file or more than
 *               one argument to the program.
 *
 * Return: EXIT_FAILURE.
 */
int usage_error(void)
{
  fprintf(stderr, "USAGE: monty file\n");
  return (EXIT_FAILURE);
}

/**
 * file_open_error - prints an error message if for
 *                   any reason, it’s not possible to
 *                   open the file.
 *
 * Return: EXIT_FAILURE.
 */
int file_open_error(char *file_name)
{
  fprintf(stderr, "Error: Can't open file %s\n", file_name);
  return (EXIT_FAILURE);
}

/**
 * unknown_instruction - prints an error message if the
 *                       file contains an invalid instruction.
 *
 * Return: EXIT_FAILURE.
 */
int unknown_instruction(char *op_code, unsigned int line_number)
{
  fprintf(stderr, "L%u: unknown instruction %s\n", line_number, op_code);
  return (EXIT_FAILURE);
}

/**
 * malloc_error - prints an error message if
 *                malloc can't work anymore.
 *
 * Return: EXIT_FAILURE.
 */
int malloc_error(void)
{
  fprintf(stderr, "Error: malloc failed\n");
  return (EXIT_FAILURE);
}

/**
 * no_int_error - prints invalid push argument error message.
 *
 * @line_number: Line number in Monty bytecodesfile
 *               where error occurred.
 * Return: EXIT_FAILURE
 */
int no_int_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push an integer\n", line_number);
	return (EXIT_FAILURE);
}
