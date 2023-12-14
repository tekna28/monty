#include "monty.h"
#include <sys/types.h>
#include <stdio.h>
#include <stddef.h>
#include <sys/stat.h>
#include <fcntl.h>

/**
 * main - main function for the monty interpreter.
 *
 *@argc: number of arguments.
 *@argv: arguments.
 * Return: EXIT_SUCCESS (Success)
 *         or EXIT_FAILURE (Error).
 */
int main(int argc, char **argv)
{
  FILE *F = NULL;
  int exit = EXIT_SUCCESS;

  if (argc != 2)
    return (usage_error());

  F = fopen(argv[1], "r");
  if (F == NULL)
    return (file_open_error(argv[1]));

  exit = run_monty_inter(F);
  fclose(F);

  return (exit);
}
