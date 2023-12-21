#include "monty.h"
/**
 * pop_nd - remov the nd of the stack
 * @data: pt of the stack
 * @numl: int of line numbr
 * Return: void
 */
void pop_nd(stack_t **data, unsigned int numl)
{
	stack_t *temp;

	if (data == NULL || *data == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", numl);
		exit(EXIT_FAILURE);

		temp = (*data);
		(*data) = temp->next;
		if (*data)
			(*data)->prev = NULL;
		free(temp);
	}
}
