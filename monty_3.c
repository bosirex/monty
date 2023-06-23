#include "monty.h"
/**
 * pint_f - prints the top
 * @stack_head: stack stack_head
 * @line_number: line_noumber
 * Return: no return
*/
void pint_f(stack_t **stack_head, unsigned int line_number)
{
	if (*stack_head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		fclose(bs.fl);
		free(bs.content);
		stack_freeing(*stack_head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack_head)->n);
}

/**
 * pchar_f - prints the char at the top of the stack,
 * followed by a new line
 * @stack_head: stack stack_head
 * @line_number: line_noumber
 * Return: no return
*/
void pchar_f(stack_t **stack_head, unsigned int line_number)
{
	stack_t *k;

	k = *stack_head;
	if (!k)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		fclose(bs.fl);
		free(bs.content);
		stack_freeing(*stack_head);
		exit(EXIT_FAILURE);
	}
	if (k->n > 127 || k->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		fclose(bs.fl);
		free(bs.content);
		stack_freeing(*stack_head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", k->n);
}

/**
 * pall_f - prints the stack
 * @stack_head: stack stack_head
 * @line_number: no used
 * Return: no return
*/
void pall_f(stack_t **stack_head, unsigned int line_number)
{
	stack_t *k;
	(void)line_number;

	k = *stack_head;
	if (k == NULL)
		return;
	while (k)
	{
		printf("%d\n", k->n);
		k = k->next;
	}
}

/**
  *nop_f- nothing
  *@stack_head: stack stack_head
  *@line_number: line number
  *Return: no return
 */
void nop_f(stack_t **stack_head, unsigned int line_number)
{
	(void) line_number;
	(void) stack_head;
}

/**
 * mul_f - multiplies the top two elements of the stack.
 * @stack_head: stack stack_head
 * @line_number: line_noumber
 * Return: no return
*/
void mul_f(stack_t **stack_head, unsigned int line_number)
{
	stack_t *k;
	int lenth = 0, aux;

	k = *stack_head;
	while (k)
	{
		k = k->next;
		lenth++;
	}
	if (lenth < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		fclose(bs.fl);
		free(bs.content);
		stack_freeing(*stack_head);
		exit(EXIT_FAILURE);
	}
	k = *stack_head;
	aux = k->next->n * k->n;
	k->next->n = aux;
	*stack_head = k->next;
	free(k);
}
