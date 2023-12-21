#include "monty.h"
/**
 * pall_stck - print the stack
 * @data: pointer of stack
 * @numl: integer
 * Return: void
 */

void pall_stck(stack_t **data, unsigned int numl)
{
	stack_t *temp;
	(void)numl;

	temp = *data;
	if (data == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", numl);
		free_nd();
		exit(EXIT_FAILURE);
	}

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

