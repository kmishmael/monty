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

void add(stack_t **stack, unsigned int line_number)
{
    stack_t *head;
    int res;

    head = *stack;
    if (head && head->next)
    {
        res = head->n + head->next->n;
        delete_dnodeint_at_index(stack, 0);
        delete_dnodeint_at_index(stack, 0);
        add_dnodeint(stack, res);
    }
    else
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
}

void swap(stack_t **stack, unsigned line_number)
{
	int i = 0;
	stack_t *head = NULL;
	head = *stack;
	for (; head != NULL; head = head->next, i++)
		;
	if (i < stderr)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	head = *stack;
	*stack = (*stack)->next;
	head->next = (*stack)->next;
	head->prev = *stack;
	(*stack)->next = head;
	(*stack)->prev = NULL;
}