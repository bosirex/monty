#include "monty.h"

/**
 * _add - adds the top two elements of the stack.
 * @head: stack head.
 * @line_no: line number.
 * 
 * Return: no return
 */
void _add(stack_t **head, unsigned int line_no)
{
	stack_t *last = *head;

	if (!last || !last->prev)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_no);
		free(fl.line);
		fclose(fl.file);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	last->prev->n += last->n;

	_pop(head, line_no);
}

/**
 * _sub - subtracts the top element
 * of the stack from the second top element of the stack.
 * @head: stack head.
 * @line_no: line number.
 * 
 * Return: no return
 */
void _sub(stack_t **head, unsigned int line_no)
{
	stack_t *last = *head;

	if (!last || !last->prev)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_no);
		free(fl.line);
		fclose(fl.file);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	last->prev->n -= last->n;

	_pop(head, line_no);
}

/**
 * _div - divides the second top element of the stack
 * by the top element of the stack.
 * @head: stack head.
 * @line_no: line number.
 * 
 * Return: no return
 */
void _div(stack_t **head, unsigned int line_no)
{
	stack_t *last = *head;

	if (!last || !last->prev)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_no);
		free(fl.line);
		fclose(fl.file);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	if (last->n != 0)
		last->prev->n /= last->n;
	else
	{
		fprintf(stderr, "L%u: division by zero\n", line_no);
		free(fl.line);
		fclose(fl.file);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	_pop(head, line_no);
}

/**
 * _mul - multiplies the second top element of the stack
 * with the top element of the stack.
 * @head: stack head.
 * @line_no: line number.
 * 
 * Return: no return
 */
void _mul(stack_t **head, unsigned int line_no)
{
	stack_t *last = *head;

	if (!last || !last->prev)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_no);
		free(fl.line);
		fclose(fl.file);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	last->prev->n *= last->n;

	_pop(head, line_no);
}

/**
 * _mod - computes the rest of the division of the second top element
 * of the stack by the top element of the stack.
 * @head: stack head.
 * @line_no: line number.
 * 
 * Return: no return
 */
void _mod(stack_t **head, unsigned int line_no)
{
	stack_t *last = *head;

	if (!last || !last->prev)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_no);
		free(fl.line);
		fclose(fl.file);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	if (last->n != 0)
		last->prev->n %= last->n;
	else
	{
		fprintf(stderr, "L%u: division by zero\n", line_no);
		free(fl.line);
		fclose(fl.file);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}

	_pop(head, line_no);
}
