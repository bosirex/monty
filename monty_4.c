#include "monty.h"
/**
 * add_f - adds the top two elements of the stack.
 * @stack_head: stack stack_head
 * @line_number: line_noumber
 * Return: no return
*/
void add_f(stack_t **stack_head, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		fclose(bs.fl);
		free(bs.content);
		stack_freeing(*stack_head);
		exit(EXIT_FAILURE);
	}
	k = *stack_head;
	aux = k->n + k->next->n;
	k->next->n = aux;
	*stack_head = k->next;
	free(k);
}

/**
 * div_f - divides the top two elements of the stack.
 * @stack_head: stack stack_head
 * @line_number: line_noumber
 * Return: no return
*/
void div_f(stack_t **stack_head, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		fclose(bs.fl);
		free(bs.content);
		stack_freeing(*stack_head);
		exit(EXIT_FAILURE);
	}
	k = *stack_head;
	if (k->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(bs.fl);
		free(bs.content);
		stack_freeing(*stack_head);
		exit(EXIT_FAILURE);
	}
	aux = k->next->n / k->n;
	k->next->n = aux;
	*stack_head = k->next;
	free(k);
}

/**
 * mod_f - computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @stack_head: stack stack_head
 * @line_number: line_noumber
 * Return: no return
*/
void mod_f(stack_t **stack_head, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		fclose(bs.fl);
		free(bs.content);
		stack_freeing(*stack_head);
		exit(EXIT_FAILURE);
	}
	k = *stack_head;
	if (k->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(bs.fl);
		free(bs.content);
		stack_freeing(*stack_head);
		exit(EXIT_FAILURE);
	}
	aux = k->next->n % k->n;
	k->next->n = aux;
	*stack_head = k->next;
	free(k);
}

/**
 * add_node - add node to the stack_head stack
 * @stack_head: stack_head of the stack
 * @n: new_value
 * Return: no return
*/
void add_node(stack_t **stack_head, int n)
{

	stack_t *newnode, *aux;

	aux = *stack_head;
	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{ printf("Error\n");
		exit(0); }
	if (aux)
		aux->prev = newnode;
	newnode->n = n;
	newnode->next = *stack_head;
	newnode->prev = NULL;
	*stack_head = newnode;
}

/**
* stack_freeing - frees a doubly linked list
* @stack_head: stack_head of the stack
*/
void stack_freeing(stack_t *stack_head)
{
	stack_t *aux;

	aux = stack_head;
	while (stack_head)
	{
		aux = stack_head->next;
		free(stack_head);
		stack_head = aux;
	}
}
