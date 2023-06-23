#ifndef MONTY_H_
#define MONTY_H_
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct global_data - global data
 * @buffer: getline buffer
 * @fptr: file pointer
*/
typedef struct global_data
{
	char *buffer;
	FILE *fptr;
} global_data_t;
extern global_data_t global_data;
stack_t *add_dnodeint(stack_t **head, const int n);
stack_t *add_dnodeint_end(stack_t **head, const int n);
int delete_dnodeint_at_index(stack_t **head, unsigned int index);
void (*get_function(char *code)) (stack_t **, unsigned int);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, __attribute__ ((unused))unsigned int line_number);
void free_dlistint(stack_t *head);
void handle_line(char *code, char *buffer, int line_number, stack_t **stack);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
int delete_dnodeint_at_index(stack_t **head, unsigned int index);
void add(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
/**
 * nop - no operation performed
 * @stack: double pointer to the top of stack
 * @line_number: line number of current instruction
 *
 * Return: void
 */
void nop(__attribute__ ((unused))stack_t **stack, __attribute__ ((unused))
	unsigned int line_number);
void free_things(void);
int is_number(char *num);
#endif
