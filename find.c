#include "monty.h"
/**
 *find - function to execute
 *@index: arguments
 *@top: beginning of the stack
 *@count: iterates through the loop
 *@file: contains the monty codes
 *Return: 0 on success
 */
int find(char *index, stack_t **top, unsigned int count, FILE *file)
{
	instruction_t operands[] = {
		{"push", push_node},
		{"pall", pall_node},
		{"pint", pint_node},
		{"pop", pop_node},
		{"swap", swap_node},
		{"add", add_node},
		{"nop", nop_node},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *operand;

	operand = strtok(index, "\n\t");
	if (operand && operand[0] == '#')
		return (0);
	parse.args = strtok(NULL, "\n\t");
	while (operands[i].opcode && operand)
	{
		if (strcmp(operand, operands[i].opcode) == 0)
		{
			operands[i].f(top, count);
			return (0);
		}
		i++;
	}
	if (operand && operands[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", count, operand);
		fclose(file);
		free(index);
		free_list(*top);
		exit(EXIT_FAILURE);
	}
	return (1);
}	
