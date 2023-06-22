#include "monty.h"

/**
 * _nop - nothing to do here.
 * @head: stack head.
 * @line_no: line number.
 * 
 * Return: no return
 */
void _nop(stack_t **head, unsigned int line_no)
{
	*head = *head;
	line_no = line_no;
}

/**
 * _pchar - prints the value at the top of the stack,
 * followed by a new line.
 * @head: stack head.
 * @line_no: line number.
 * 
 * Return: no return
 */
void _pchar(stack_t **head, unsigned int line_no)
{
	if (!(*head))
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_no);
		free(fl.line);
		fclose(fl.file);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	if (isascii((*head)->n))
		printf("%c\n", (char)((*head)->n));
	else
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_no);
		free(fl.line);
		fclose(fl.file);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
}

/**
 * _pstr - prints the value at the top of the stack,
 * followed by a new line.
 * @head: stack head.
 * @line_no: line number.
 * 
 * Return: no return
 */
void _pstr(stack_t **head, unsigned int line_no)
{
	stack_t *aux = *head;

	(void)line_no;

	if (!head || !(*head))
	{
		putchar(10);
		return;
	}
	while (aux)
	{
		if (isascii(aux->n) && aux->n != 0)
		{
			printf("%c", (char)(aux->n));
		}
		else
			break;
		aux = aux->prev;
	}
	putchar(10);
}
