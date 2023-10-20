#include "monty.h"

int mode = MODE_STACK;

/**
 * handle_stack - sets the mode to stack (LIFO)
 * @stack: pointer to a pointer to the stack
 * @line_number: tracks the line number
 */
void handle_stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	mode = MODE_STACK;
}

/**
 * handle_queue - sets the mode to queue (FIFO)
 * @stack: pointer to a pointer to the stack
 * @line_number: tracks the line number
 */
void handle_queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	mode = MODE_QUEUE;
}
