#include "monty.h"
/**
* execute_fn - executes the opcode
* @stack: stack_head linked list - stack
* @line_number: line_counter
* @fl: pointer to monty file
* @content: line content
* Return: no return
*/
int execute_fn(char *content, stack_t **stack, unsigned int line_number, FILE *fl)
{
	instruction_t opst[] = {
				{"push", push_f}, {"pall", pall_f}, {"pint", pint_f},
				{"pop", pop_f},
				{"swap", swap_f},
				{"add", add_f},
				{"nop", nop_f},
				{"sub", sub_f},
				{"div", div_f},
				{"mul", mul_f},
				{"mod", mod_f},
				{"pchar", pchar_f},
				{"pstr", pstr_f},
				{"rotl", rotl_f},
				{"rotr", rotr_f},
				{"queue", queue_f},
				{"stack", stack_f},
				{NULL, NULL}
				};
	unsigned int j = 0;
	char *ops;

	ops = strtok(content, " \n\t");
	if (ops && ops[0] == '#')
		return (0);
	bs.arg = strtok(NULL, " \n\t");
	while (opst[j].opcode && ops)
	{
		if (strcmp(ops, opst[j].opcode) == 0)
		{	opst[j].f(stack, line_number);
			return (0);
		}
		j++;
	}
	if (ops && opst[j].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", line_number, ops);
		fclose(fl);
		free(content);
		stack_freeing(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
