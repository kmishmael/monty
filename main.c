#define _POSIX_C_SOURCE 200809L
#include "monty.h"
global_data_t global_data = {NULL, NULL};
/**
 * main - main function
 * @ac: number of args
 * @av: args array
 * Return: int
 */
int main(int ac, char **av)
{
	stack_t *stack = NULL;
	int line_number = 1;
	char *code;
	size_t i = 0;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	global_data.fptr = fopen(av[1], "r");
	if (global_data.fptr == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while ((getline(&global_data.buffer, &i, global_data.fptr)) != -1)
	{
		code = strtok(global_data.buffer, "\n ");
		if (code != NULL && code[0] != '#')
		{
			handle_line(code, global_data.buffer, line_number, &stack);
		}
		line_number++;
	}
	fclose(global_data.fptr);
	free(global_data.buffer);
	free_dlistint(stack);
	return (0);
}

/**
 * get_function - gets the appropriate function as per opcode
 * @code: the opcode
 * Return: function pointer of the appropriate func
 */
void (*get_function(char *code)) (stack_t **, unsigned int) {
	int i = 0;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"add", add},
		{"swap", _swap},
		{"nop", nop},
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr}
	};
	while (i < 15)
	{
		if (strcmp(instructions[i].opcode, code) == 0)
		{
			return (instructions[i].f);
		}
		i++;
	}
	return (NULL);
}

/**
 * push - push node to a list
 * @stack: the current stack
 * @line_number: the line number the opcode occurs
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *arg;
	int v_arg;

	arg = strtok(NULL, "\n ");
	if (arg == NULL || is_number(arg) != 1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_dlistint(*stack);
		free(global_data.buffer);
		fclose(global_data.fptr);
		exit(EXIT_FAILURE);
	}
	else
	{
	v_arg = atoi(arg);
	add_dnodeint(stack, v_arg);
	}
}

/**
 * pall - prints all elements in the stack
 * @stack: the current stack
 * @line_number: the current line number
 * Return: void
 */
void pall(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *head;

	head = *stack;
	while (head != NULL)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}

/**
 * handle_line - handles a line
 * @code: opcode string
 * @buffer: string
 * @line_number: line in th code being run
 * @stack: reference to stack
 * Return: void
 */
void handle_line(char *code, char *buffer, int line_number, stack_t **stack)
{
	void (*instruction)(stack_t **, unsigned int);

	instruction = get_function(code);
	if (instruction != NULL)
	{
		instruction(stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n",
				line_number, code);
		free(buffer);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
}
