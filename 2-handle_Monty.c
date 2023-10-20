#include "monty.h"

/**
 * handle_mod - computes the rest of the division
 * @stack: pointer to a pointer to the stack
 * @line_number: tracks the line number
 */
void handle_mod(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n %= (*stack)->n;
	handle_pop(stack, line_number);
}
#include "monty.h"
#include <ctype.h>

/**
 * handle_pchar - prints the character at the top of the stack
 * @stack: pointer to a pointer to the stack
 * @line_number: tracks the line number
 */
void handle_pchar(stack_t **stack, unsigned int line_number)
{
	int value;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = (*stack)->n;

	if (value < 0 || value > 127 || !isprint(value))
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	putchar(value);
	putchar('\n');
}
/**
 * handle_pstr - prints a string based on integer values on the stack
 * @stack: pointer to a pointer to the stack
 * @line_number: tracks the number of lines
 */
void handle_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	while (current && current->n != 0 && current->n >= 0 && current->n <= 127)
	{
		printf("%c", current->n);
		current = current->prev;
	}
	printf("\n");
}
/**
 * handle_rotl - rotates the stack to the top
 * @stack: pointer to a pointer to the stack
 * @line_number: tracks the number of lines
 */
void handle_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *last;
	stack_t *first;

	(void)line_number;

	if (!stack || !*stack || !(*stack)->next)
	{
		return;
	}

	last = *stack;
	first = last->next;

	while (last->next)
	{
		last = last->next;
	}

	last->next = *stack;
	(*stack)->prev = last;
	(*stack)->next = NULL;
	first->prev = NULL;
	*stack = first;
}
