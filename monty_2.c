#include "monty.h"
/**
 * queue_f - prints the top
 * @stack_head: stack stack_head
 * @line_number: line_noumber
 * Return: no return
*/
void queue_f(stack_t **stack_head, unsigned int line_number)
{
	(void)stack_head;
	(void)line_number;
	bs.lifi = 1;
}

/**
 * add_queue - add node to the tail stack
 * @n: new_value
 * @stack_head: stack_head of the stack
 * Return: no return
*/
void add_queue(stack_t **stack_head, int n)
{
	stack_t *newnode, *aux;

	aux = *stack_head;
	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		printf("Error\n");
	}
	newnode->n = n;
	newnode->next = NULL;
	if (aux)
	{
		while (aux->next)
			aux = aux->next;
	}
	if (!aux)
	{
		*stack_head = newnode;
		newnode->prev = NULL;
	}
	else
	{
		aux->next = newnode;
		newnode->prev = aux;
	}
}

/**
 * push_f - add node to the stack
 * @stack_head: stack stack_head
 * @line_number: line_noumber
 * Return: no return
*/
void push_f(stack_t **stack_head, unsigned int line_number)
{
	int k, m = 0, flg = 0;

	if (bs.arg)
	{
		if (bs.arg[0] == '-')
			m++;
		for (; bs.arg[m] != '\0'; m++)
		{
			if (bs.arg[m] > 57 || bs.arg[m] < 48)
				flg = 1; }
		if (flg == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(bs.fl);
			free(bs.content);
			stack_freeing(*stack_head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(bs.fl);
		free(bs.content);
		stack_freeing(*stack_head);
		exit(EXIT_FAILURE); }
	k = atoi(bs.arg);
	if (bs.lifi == 0)
		add_node(stack_head, k);
	else
		add_queue(stack_head, k);
}

/**
 * pstr_f - prints the string starting at the top of the stack,
 * followed by a new
 * @stack_head: stack stack_head
 * @line_number: line_noumber
 * Return: no return
*/
void pstr_f(stack_t **stack_head, unsigned int line_number)
{
	stack_t *k;
	(void)line_number;

	k = *stack_head;
	while (k)
	{
		if (k->n > 127 || k->n <= 0)
		{
			break;
		}
		printf("%c", k->n);
		k = k->next;
	}
	printf("\n");
}

/**
 * pop_f - prints the top
 * @stack_head: stack stack_head
 * @line_number: line_noumber
 * Return: no return
*/
void pop_f(stack_t **stack_head, unsigned int line_number)
{
	stack_t *k;

	if (*stack_head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(bs.fl);
		free(bs.content);
		stack_freeing(*stack_head);
		exit(EXIT_FAILURE);
	}
	k = *stack_head;
	*stack_head = k->next;
	free(k);
}
