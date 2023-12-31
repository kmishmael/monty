#include "monty.h"

/**
 * pint - pint
 * @stack: the stack
 * @line_number: line_number
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: ", line_number);
		fprintf(stderr, "can't pint, stack empty\n");
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - pop removes node at the top of the stack
 * @stack: the stack
 * @line_number: line_number
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *h;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	h = *stack;
	*stack = (*stack)->next;
	free(h);
}

/**
 * add - adds nodes
 * @stack: the stack
 * @line_number: line number
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *head;
	int res;

	head = *stack;
	if (head && head->next)
	{
		res = head->n + head->next->n;
		head->next->n = res;
		*stack = head->next;
		free(head);
	}
	else
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * _swap - swap some stuff
 * @stack: the stack
 * @line_number: line number
 * Return: void
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *head = NULL;

	head = *stack;
	if (head == NULL || head->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_dlistint(*stack);
		free(global_data.buffer);
		fclose(global_data.fptr);
		exit(EXIT_FAILURE);
	}
	head = *stack;
	*stack = (*stack)->next;
	head->next = (*stack)->next;
	head->prev = *stack;
	(*stack)->next = head;
	(*stack)->prev = NULL;
}

/**
 * nop - no operation performed
 * @stack: double pointer to the top of stack
 * @line_number: line number of current instruction
 *
 * Return: void
 */
void nop(__attribute__ ((unused))stack_t **stack, __attribute__
	((unused))unsigned int line_number)
{
}
