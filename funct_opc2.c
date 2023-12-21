#include "monty.h"

/**
 * mul_nd - mult the top two elements of stack.
 * @data: Pointer of the stack.
 * @numl: Interger represent the line number  opcode.
 */
void mul_nd(stack_t **data, unsigned int numl)
{
	int sume;

	if (data == NULL || *data == NULL || (*data)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", numl);
		free_nd();
		exit(EXIT_FAILURE);
	}
	(*data) = (*data)->next;
	sume = (*data)->n * (*data)->prev->n;
	(*data)->n = sume;
	free((*data)->prev);
	(*data)->prev = NULL;
}


/**
 * mod_nd - mod the top two elements of the stack.
 * @data: Pointer of the stack.
 * @numl: Interger represent the line numbr.
 */
void mod_nd(stack_t **data, unsigned int numl)
{
	int sume;

	if (data == NULL || *data == NULL || (*data)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", numl);
		free_nd();
		exit(EXIT_FAILURE);
	}
	if ((*data)->n == 0)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", numl);
		free_nd();
		exit(EXIT_FAILURE);
	}
	(*data) = (*data)->next;
	sume = (*data)->n % (*data)->prev->n;
	(*data)->n = sume;
	free((*data)->prev);
	(*data)->prev = NULL;
}
