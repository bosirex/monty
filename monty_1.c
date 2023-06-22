#ifndef MONTY
#define MONTY
#define  _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
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

/**
 * struct contents  - opcode and its function
 * @op_func: the opcode
 * @value: function to handle the opcode
 * @line_no: number of the line
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct contents
{
	char *op_func;
	char *value;
	int line_no;
} contents_v;

/**
 * struct stakit  - opcode and its function
 * @int_val: value.
 * @data: contents.
 * @file: file.
 * @line: idk.
 * Description: honestly, idk.
 */
typedef struct stakit
{
	int int_val;
	contents_v data;
	FILE *file;
	char *line;
} extern_var_t;
extern extern_var_t fl;

int main(int argc, char *argv[]);
void read_file(FILE *file);
void execute(stack_t **stack);
size_t _not_empty(char *line);
contents_v cleaning_spaces(char *line);

void _push(stack_t **top, unsigned int line_no);
void _pall(stack_t **top, unsigned int line_no);
void _pint(stack_t **top, unsigned int line_no);
void _pop(stack_t **top, unsigned int line_no);
void _swap(stack_t **top, unsigned int line_no);
void _add(stack_t **top, unsigned int line_no);
void _sub(stack_t **head, unsigned int line_no);
void _mul(stack_t **head, unsigned int line_no);
void _nop(stack_t **head, unsigned int line_no);
void _div(stack_t **head, unsigned int line_no);
void _mod(stack_t **head, unsigned int line_no);
void _pchar(stack_t **head, unsigned int line_no);
void _pstr(stack_t **head, unsigned int line_no);

void stack_free(stack_t *head);
#endif