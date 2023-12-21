#include "monty.h"

/**
 * pint_chr - Print  Ascii values.
 * @data: Pointer of the stack.
 * @numl: interger represent the line number.
 */
void pint_chr(stack_t **data, unsigned int numl)
{
	int asci;

	if (data == NULL || *data == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", numl);
		free_nd();
		exit(EXIT_FAILURE);
	}
	asci = (*data)->n;
	if (asci < 0 || asci > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", numl);
		free_nd();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", asci);
}

/**
 * pints_str - funct Print string.
 * @data: Pointer of the stack.
 * @numl: interger represent the line number.
 */
void pints_str(stack_t **data, __attribute__((unused))unsigned int numl)
{
	int asci;
	stack_t *temp;

	if (data == NULL || *data == NULL)
	{
		printf("\n");
		return;
	}

	temp = *data;
	while (temp)
	{
		asci = temp->n;
		if (asci <= 0 || asci > 127)
			break;
		printf("%c", asci);
		temp = temp->next;
	}
	printf("\n");
}

/**
 * rotl_nds - funct rotates the first node of the stack.
 * @data: pointer of the stack.
 * @numl: interger represent the line number.
 */
void rotl_nds(stack_t **data, __attribute__((unused))unsigned int numl)
{
	stack_t *temp;

	if (data == NULL || data == NULL || (*data)->next == NULL)
		return;

	temp = *data;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *data;
	(*data)->prev = temp;
	*data = (*data)->next;
	(*data)->prev->next = NULL;
	(*data)->prev = NULL;
}


/**
 * rotr_nds - funct rotates the last node of the stack.
 * @data: pointer of the stack
 * @numl: interger represent the line number.
 */
void rotr_nds(stack_t **data, __attribute__((unused))unsigned int numl)
{
	stack_t *temp;

	if (data == NULL || *data == NULL || (*data)->next == NULL)
		return;

	temp = *data;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *data;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*data)->prev = temp;
	(*data) = temp;
}
