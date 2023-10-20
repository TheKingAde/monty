#include "monty.h"

/**
 * handle_add - adds the top two elements of the stack
 * @stack: pointer to a pointer to the stack
 * @line_number: tracks the line number
 */
void handle_add(stack_t **stack, unsigned int line_number)
{
	int result;
	stack_t *temp;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	result = (*stack)->n + (*stack)->next->n;

	(*stack)->next->n = result;
	*stack = (*stack)->next;
	free(temp);
}
/**
 * handle_nop - The opcode nop doesn't do anything.
 * @stack: pointer to a pointer to the stack
 * @line_number: Tracks the line number
 */
void handle_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
#include "monty.h"

/**
 * handle_sub - subtracts the top element from the second top element
 * @stack: pointer to a pointer to the stack
 * @line_number: tracks the line number
 */
void handle_sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n -= (*stack)->n;
	handle_pop(stack, line_number);
}
