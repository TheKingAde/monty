#include "monty.h"

/**
 * process_line - determines what to run
 * @line: pointer to the current line
 * @line_number: keeps track of the number of lines
 * @stack: pointer to a pointer to stack
 *
 */
void process_line(char *line, unsigned int line_number, stack_t **stack)
{
	instruction_t instructions[] = {
		{"push", handle_push},
		{"pall", handle_pall},
		{"pint", handle_pint},
		{"pop", handle_pop},
		{"swap", handle_swap},
		{"add", handle_add},
		{"nop", handle_nop},
		{"sub", handle_sub},
		{"div", handle_div},
		{"mul", handle_mul},
		{"mod", handle_mod},
		{"pchar", handle_pchar},
		{"pstr", handle_pstr},
		{"rotl", handle_rotl},
		{"rotr", handle_rotr},
		{"stack", handle_stack},
		{"queue", handle_queue},
		{NULL, NULL}
	};
	char *opcode = strtok(line, " \t\n");
	instruction_t *instruction;

	if (!opcode || opcode[0] == '#')
		return;

	for (instruction = instructions; instruction->opcode; instruction++)
	{
		if (strcmp(instruction->opcode, opcode) == 0)
		{
			instruction->f(stack, line_number);
			return;
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
/**
 * process_file - processes file
 * @filename: pointer to files
 * @stack: pointer to a pointer to stack
 *
 */
void process_file(const char *filename, stack_t **stack)
{
	FILE *file = fopen(filename, "r");
	char line[100];
	unsigned int line_number = 0;

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), file))
	{
		line_number++;
		process_line(line, line_number, stack);
	}

	fclose(file);
}

