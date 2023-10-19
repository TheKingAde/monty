#include "monty.h"

/**
 * main - morty code
 * @argc: number of char in the array
 * @argv: pointer to the char in the array
 *
 * Return: EXIT_SUCCESS
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	stack_t *temp = stack;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	process_file(argv[1], &stack);
	while (stack)
	{
		stack = stack->prev;
		free(temp);
	}
	return (EXIT_SUCCESS);
}
