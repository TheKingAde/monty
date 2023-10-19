#include "monty.h"

/**
 * handle_push - pushes an element to the stack
 * @stack: pointer to a pointer to the stack
 * @line_number: Tracks the line number
 *
 */
void handle_push(stack_t **stack, unsigned int line_number)
{
	char *arg = strtok(NULL, " \t\n");
	stack_t *new_node = malloc(sizeof(stack_t));

	if (arg == NULL || !is_integer(arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = atoi(arg);
	new_node->prev = *stack;
	*stack = new_node;
}
/**
 * handle_pall - prints all the values on the stack, starting from the top
 * @stack: pointer to a pointer to the stack
 * @line_number: tracks number of lines
 *
 */
void handle_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->prev;
	}
}
/**
 * handle_pint - prints the value at the top of the stack
 * @stack: pointer to a pointer to the stack
 * @line_number: tracks the line number
 */
void handle_pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
