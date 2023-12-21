#include "monty.h"

/**
 * pint_nd - print the value at the top of stack
 * @data: poiter of the stack
 * @numl: int number of line
 * Return: void
 */
void pint_nd(stack_t **data, unsigned int numl)
{
	if (!data || *data == NULL) 
	{
		printf(" Error, L%u: can't pint, stack empty\n", numl);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*data)->n);
}
