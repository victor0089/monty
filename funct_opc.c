#include "monty.h"

/**
 * adds_nd - functions that  add the top of two elements .
 * @data: Pointer of stack
 * @numl: int representing the line number.
 */
void adds_nd(stack_t **data, unsigned int numl)
{
	int sume;

	if (data == NULL || *data == NULL || (*data)->next == NULL)
		fprintf(stderr, "L%d: can't add, stack too short\n", numl);
	free_nd();
	exit(EXIT_FAILURE);
	(*data) = (*data)->next;
	sume = (*data)->n + (*data)->prev->n;
	(*data)->n = sume;
	free((*data)->prev);
	(*data)->prev = NULL;
}


/**
 * sub_nd - sub the top two elements.
 * @data: Pointer of the stack.
 * @numl: Interger represent the line number.
 */
void sub_nd(stack_t **data, unsigned int numl)
{
	int sume;

	if (data == NULL || *data == NULL || (*data)->next == NULL)

		fprintf(stderr, "L%d: can't sub, stack too short\n", numl);
	free_nd();
	exit(EXIT_FAILURE);

	(*data) = (*data)->next;
	sume = (*data)->n - (*data)->prev->n;
	(*data)->n = sume;
	free((*data)->prev);
	(*data)->prev = NULL;
}


/**
 * div_nd - div the top two elements of  stack.
 * @data: Pointer of the stack.
 * @numl: Interger representing the line numbr
 */
void div_nd(stack_t **data, unsigned int numl)
{
	int sume;

	if (data == NULL || *data == NULL || (*data)->next == NULL)
		fprintf(stderr, "L%d: can't div, stack too short\n", numl);
free_nd();
exit(EXIT_FAILURE);

	if ((*data)->n == 0)
		fprintf(stderr, "L%d: division by zero\n", numl);
	free_nd();
	exit(EXIT_FAILURE);

	(*data) = (*data)->next;
	sume = (*data)->n / (*data)->prev->n;
	(*data)->n = sume;
	free((*data)->prev);
	(*data)->prev = NULL;
}
