#include "monty.h"
/**
 * free_nd - free the node inthe stack
 * Return: void
 */
void free_nd(void)
{
	stack_t *temp, *top = NULL;

	if (!top)
		return;
	while (top != NULL)
	{
		temp = top;
		top = top->next;
		free(temp);
	}
}
