#define _POSIX_C_SOURCE 200809L
#include "monty.h"

/**
 * main - main function
 * @ac: number of args
 * @av: args array
 * Return: int
 */
int main(int ac, char **av)
{
	stack_t *stack = NULL;
	char *buffer = NULL;
	size_t i = 0;
	FILE *fptr;
	char *code;
	int line_number = 1;
	void (*instruction) (stack_t **, unsigned int);
	
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fptr = fopen(av[1], "r");
	if (fptr == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	while ((getline(&buffer, &i, fptr)) != -1)
	{
		code = strtok(buffer, "\n ");

		if (code == NULL)
		{
			continue;
		}
		instruction = get_function(code);
		if (instruction != NULL)
		{
			instruction(&stack, line_number);
		}
		else
		{
			fprintf(stderr, "Error at line %d: Unknown opcode: %s\n", line_number, code);
			free(buffer);
			exit(EXIT_FAILURE);
		}
		line_number++;
	}
	fclose(fptr);
	free(buffer);
	free_dlistint(stack);
	return (0);
}

void (*get_function(char *code)) (stack_t **, unsigned int) {
    int i = 0;

    instruction_t instructions[] = {
	    {"push", push},
	    {"pall", pall},
    };
    while (i < 2)
    {
	   if(strcmp(instructions[i].opcode, code) == 0)
	   {
		return (instructions[i].f);
	   }
	   i++;
    }
    return (NULL);
}

void push(stack_t **stack, unsigned int line_number)
{
	char *arg;
	int v_arg;
	int i;
	
	arg = strtok(NULL, "\n ");
	i = 0;
	if(arg[i] == '-')
	{
		i++;
	}
	while (arg[i])
	{
		if(!isdigit(arg[i]))
		{
			printf("L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	v_arg = atoi(arg);
	add_dnodeint(stack, v_arg);
}

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *head;

	(void)line_number;
	head = *stack;
	while(head != NULL)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}
