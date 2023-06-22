#include "monty.h"

/**
 * free_things - frees global variables
 * @void: void
 * Return: void
 */
void free_things(void)
{
	free(buffer);
	fclose(fptr);
}
