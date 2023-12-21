#include "monty.h"

/**
 * adds_queues - add  anode to queue
 *@data: pointer of the queue.
 * @numl: number of line
 * Return: void
 */
void adds_queues(stack_t **data, __attribute__((unused)) unsigned int numl)
{
	stack_t *temp, *top = NULL;

	if (!data || *data == NULL)
		exit(EXIT_FAILURE);

	if (!top)
	{
		top = *data;
		return;
	}
	temp = top;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *data;
	(*data)->prev = temp;
}


