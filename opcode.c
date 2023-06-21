#include "monty.h"

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

void pop(stack_t **stack, unsigned line_number)
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