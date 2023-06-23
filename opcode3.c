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
