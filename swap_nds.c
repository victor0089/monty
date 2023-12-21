#include "monty.h"
/**
 * swap_nds - swap top of two element in the stack
 * @data: pointer to a pointer of the stack
 * @numl: int of line of num
 * Return: void
 */
void swap_nds(stack_t **data, unsigned int numl)
{
	stack_t *temp;
	int m;

	if (data == NULL || *data == NULL || (*data)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", numl);
			free_nd();
			exit(EXIT_FAILURE);
	}
	temp = *data;
	m = temp->n;
	temp->n = temp->next->n;
	temp->next->n = m;
}
