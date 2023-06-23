#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct bs_s - variables -args, file, line content
 * @arg: value
 * @fl: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct bs_s
{
	char *arg;
	FILE *fl;
	char *content;
	int lifi;
}  bs_t;
extern bs_t bs;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_noumber);
} instruction_t;
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int fl);
char  *clean_line(char *content);
void push_f(stack_t **stack_head, unsigned int number);
void pall_f(stack_t **stack_head, unsigned int number);
void pint_f(stack_t **stack_head, unsigned int number);
int execute_fn(char *content, stack_t **stack_head, unsigned int line_number, FILE *fl);
void stack_freeing(stack_t *stack_head);
void pop_f(stack_t **stack_head, unsigned int line_number);
void swap_f(stack_t **stack_head, unsigned int line_number);
void add_f(stack_t **stack_head, unsigned int line_number);
void nop_f(stack_t **stack_head, unsigned int line_number);
void sub_f(stack_t **stack_head, unsigned int line_number);
void div_f(stack_t **stack_head, unsigned int line_number);
void mul_f(stack_t **stack_head, unsigned int line_number);
void mod_f(stack_t **stack_head, unsigned int line_number);
void pchar_f(stack_t **stack_head, unsigned int line_number);
void pstr_f(stack_t **stack_head, unsigned int line_number);
void rotl_f(stack_t **stack_head, unsigned int line_number);
void rotr_f(stack_t **stack_head, __attribute__((unused)) unsigned int line_number);
void add_node(stack_t **stack_head, int n);
void add_queue(stack_t **stack_head, int n);
void queue_f(stack_t **stack_head, unsigned int line_number);
void stack_f(stack_t **stack_head, unsigned int line_number);
#endif
