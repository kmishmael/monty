#include "monty.h"

/**
 * pint - pint
 * @stack: the stack
 * @line_number: line_number
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: ", line_number);
		fprintf(stderr, "can't pint, stack empty\n");
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - pop
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
		free_dlistint(*stack);
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
		delete_dnodeint_at_index(stack, 0);
		(*stack)->n = res;
	}
	else
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * swap - swap some stuff
 * @stack: the stack
 * @line_number: line number
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *head = NULL;

	head = *stack;
	if (head == NULL || head->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	head = *stack;
	*stack = (*stack)->next;
	head->next = (*stack)->next;
	head->prev = *stack;
	(*stack)->next = head;
	(*stack)->prev = NULL;
}
