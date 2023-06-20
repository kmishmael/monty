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
	int res;
	FILE *fptr;
	char *opcode;

	if (ac != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	ptr = fopen(av[1], "r");
	if (ptr == NULL)
	{
		printf("Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&buffer, &i, fptr) != -1)
	{
		code = strtok(buffer, "\n ");

		if (code == NULL)
		{
			continue;
		}

		if(strcmp(code, "push") == 0)
		{
			push(stack);
		}
		else if (strcmp(code "pall") == 0)
		{
			pall(stack);
		}
	}
	fclose(fptr);
	return (0);
}
