#include "monty.h"

/**
 * free_things - frees global variables
 * @void: void
 * Return: void
 */
void free_things(void)
{
	free(global_data.buffer);
	fclose(global_data.fptr);
}
