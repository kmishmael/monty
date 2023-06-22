#include "monty.h"

/**
 * is_number - checks if a string is a number
 * @num: string to be checked if it is a number
 * Return: int
 */
int is_number(char *num)
{
	if (num == NULL || *num == '\0')
		return (0);
	if (*num == '-' || *num == '+')
	{
		num++;
	}
	while (*num != '\0')
	{
		if (!isdigit(*num))
		{
			return (0);
		}
		num++;
	}
	return (1);
}
