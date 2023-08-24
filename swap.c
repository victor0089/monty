#include "monty.h"

/**
 * swap - function thatswaps thetoptwo elements inthestack.
 * @stack: Pointertothe stack.
 * @line_number: Line numberof theinstruction.
 * Return: void.
 */
void swap(stack_t **stack, unsigned int line_number)
{
int n;
if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
exit(EXIT_FAILURE);
}
n = (*stack)->n;
(*stack)->n = (*stack)->next->n;
(*stack)->next->n = n;
}
