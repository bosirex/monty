#include "monty.h"

/**
  *rotl_f- rotates the stack to the top
  *@stack_head: stack stack_head
  *@line_number: line_noumber
  *Return: no return
 */
void rotl_f(stack_t **stack_head,  __attribute__((unused)) unsigned int line_number)
{
	stack_t *temp = *stack_head, *aux;

	if (*stack_head == NULL || (*stack_head)->next == NULL)
	{
		return;
	}
	aux = (*stack_head)->next;
	aux->prev = NULL;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = *stack_head;
	(*stack_head)->next = NULL;
	(*stack_head)->prev = temp;
	(*stack_head) = aux;
}

/**
  *rotr_f- rotates the stack to the bottom
  *@stack_head: stack stack_head
  *@line_number: line_noumber
  *Return: no return
 */
void rotr_f(stack_t **stack_head, __attribute__((unused)) unsigned int line_number)
{
	stack_t *cpy;

	cpy = *stack_head;
	if (*stack_head == NULL || (*stack_head)->next == NULL)
	{
		return;
	}
	while (cpy->next)
	{
		cpy = cpy->next;
	}
	cpy->next = *stack_head;
	cpy->prev->next = NULL;
	cpy->prev = NULL;
	(*stack_head)->prev = cpy;
	(*stack_head) = cpy;
}

/**
 * stack_f - prints the top
 * @stack_head: stack stack_head
 * @line_number: line_noumber
 * Return: no return
*/
void stack_f(stack_t **stack_head, unsigned int line_number)
{
	(void)stack_head;
	(void)line_number;
	bs.lifi = 0;
}

/**
  *sub_f- sustration
  *@stack_head: stack stack_head
  *@line_number: line_noumber
  *Return: no return
 */
void sub_f(stack_t **stack_head, unsigned int line_number)
{
	stack_t *aux;
	int sus, nods;

	aux = *stack_head;
	for (nods = 0; aux != NULL; nods++)
		aux = aux->next;
	if (nods < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		fclose(bs.fl);
		free(bs.content);
		stack_freeing(*stack_head);
		exit(EXIT_FAILURE);
	}
	aux = *stack_head;
	sus = aux->next->n - aux->n;
	aux->next->n = sus;
	*stack_head = aux->next;
	free(aux);
}

/**
 * swap_f - adds the top two elements of the stack.
 * @stack_head: stack stack_head
 * @line_number: line_noumber
 * Return: no return
*/
void swap_f(stack_t **stack_head, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(bs.fl);
		free(bs.content);
		stack_freeing(*stack_head);
		exit(EXIT_FAILURE);
	}
	k = *stack_head;
	aux = k->n;
	k->n = k->next->n;
	k->next->n = aux;
}
