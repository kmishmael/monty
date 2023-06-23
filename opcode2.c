#include "monty.h"

/**
 * sub - subracts two numbers at the top of the stack
 * @stack: pointer to the stack
 * @line_number: line number the sub command occurs
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *head;
	int res;

	head = *stack;
	if (head && head->next)
	{
		res = head->next->n - head->n;
		head->next->n = res;
		*stack = head->next;
		free(head);
	}
	else
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * _div - divides two numbers at the top of the stack
 * @stack: pointer to the stack
 * @line_number: line number the sub command occurs
 * Return: void
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *head;
	int res;

	head = *stack;
	if (head && head->next)
	{
		if (head->n == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", line_number);
			free_dlistint(*stack);
			exit(EXIT_FAILURE);
		}
		res = head->next->n / head->n;
		head->next->n = res;
		*stack = head->next;
		free(head);
	}
	else
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * mul - multiplies two numbers at the top of the stack
 * @stack: pointer to the stack
 * @line_number: line number the sub command occurs
 * Return: void
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *head;
	int res;

	head = *stack;
	if (head && head->next)
	{
		res = head->next->n * head->n;
		head->next->n = res;
		*stack = head->next;
		free(head);
	}
	else
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * mod - modulus two numbers at the top of the stack
 * @stack: pointer to the stack
 * @line_number: line number the sub command occurs
 * Return: void
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *head;
	int res;

	head = *stack;
	if (head && head->next)
	{
		if (head->n == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", line_number);
			free_dlistint(*stack);
			exit(EXIT_FAILURE);
		}
		res = head->next->n % head->n;
		head->next->n = res;
		*stack = head->next;
		free(head);
	}
	else
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * pchar - pint
 * @stack: the stack
 * @line_number: line_number
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (((*stack)->n >= 65 && (*stack)->n <= 90) ||
			((*stack)->n >= 97 && (*stack)->n <= 122))
	{
		printf("%c\n", (*stack)->n);
	}
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
}
