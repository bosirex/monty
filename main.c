#include "monty.h"

extern_var_t fl;

/**
 * main - interpreter
 * @argc: no. of arguments.
 * @argv: file location.
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
	FILE *file;

	/* arg error */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	/* open file error */
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	read_file(file);
	fclose(file);
	return (0);
}

/**
 * read_file - honestly, idk.
 * @file: idk.
 */
void read_file(FILE *file)
{
	char *_line = NULL;
	size_t _lenght = 0;
	int j;
	stack_t *head = NULL;

	fl.file = file;

	/* get new line from fp's buffer */
	j = 1;
	while (getline(&_line, &_lenght, file) != -1)
	{
		if (_not_empty(_line))
		{
			fl.data = cleaning_spaces(_line);
			if (fl.data.value != NULL)
			{
				fl.int_val = atoi(fl.data.value);
			}
			fl.data.line_no = j;
			fl.line = _line;
			execute(&head);
		}
		j++;
	}
	free(_line);
	stack_free(head);
}

/**
 * execute - honestly, idk.
 * @stack: stack pointer.
 * Return: 0.
 */
void execute(stack_t **stack)
{
	instruction_t functions[] = {
		{"push", _push}, {"pall", _pall}, {"pint", _pint},
		{"pop", _pop}, {"swap", _swap}, {"add", _add},
		{"sub", _sub}, {"nop", _nop}, {"div", _div},
		{"mul", _mul}, {"mod", _mod}, {"pchar", _pchar},
		{"pstr", _pstr}, {NULL, NULL}
	};
	int j;

	for (j = 0; functions[j].opcode; j++)
	{
		if (!strcmp(fl.data.op_func, functions[j].opcode))
		{
			functions[j].f(stack, fl.data.line_no);
			break;
		}
	}
	if (!functions[j].opcode)
	{

		fprintf(stderr, "L%d: unknown instruction", fl.data.line_no);
		fprintf(stderr, " %s\n", fl.data.op_func);
		free(fl.line);
		fclose(fl.file);
		stack_free(*stack);
		exit(EXIT_FAILURE);
	}
}
/**
 * stack_free - honestly, idk.
 * @head: idk.
 * Return: less find out god.
 */
void stack_free(stack_t *head)
{
	stack_t *last;
	stack_t *prev_Node;

	last = head;

	if (last)
	{
		prev_Node = last->prev;

		while (prev_Node)
		{
			free(last);
			last = prev_Node;
			prev_Node = prev_Node->prev;
		}
		free(last);
	}
}