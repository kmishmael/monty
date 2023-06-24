#include "monty.h"


/**
 * pstr - pstr
 * @stack: the stack
 * @line_number: line_number
 * Return: void
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL;

	(void)line_number;
	current = *stack;
	while (current != NULL)
	{
		if ((current->n >= 65 && current->n <= 90) ||
				(current->n >= 97 && current->n <= 122))
		{
			printf("%c", current->n);
		}
		else
		{
			break;
		}
		current = current->next;
	}
	printf("\n");
}

/**
 * rotl - reverse a linked list
 * @stack: the stack
 * @line_number: line_number
 * Return: void
*/
void rotl(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *current = *stack;
	stack_t *new = NULL;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	while (current->next != NULL)
	{
		current = current->next;
	}
	new = (*stack)->next;
	current->next = *stack;
	(*stack)->next = NULL;
	*stack = new;
}

/**
 * rotr - rotates a linked list
 * @stack: the stack itself
 * @line_number: line number the code occurs
 * Return: void
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *h = NULL;

	(void)line_number;
	if (*stack == NULL)
		return;
	if ((*stack)->next == NULL)
		return;
	h = *stack;
	for (; h->next != NULL; h = h->next)
		;
	h->prev->next = NULL;
	h->next = *stack;
	h->prev = NULL;
	(*stack)->prev = h;
	*stack = h;
}
