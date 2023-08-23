#include "monty.h"

/**
 * pop - function thatremove thetop elementof thestack.
 * @stack: Pointerto thestack.
 * @line_number: Lin numberof theinstruction.
 * Return: void.
 */
void pop(stack_t **stack, unsigned int line_number)
{
stack_t *node;
if (*stack == NULL)
{
fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
exit(EXIT_FAILURE);
}
node = *stack;
*stack = (*stack)->next;
free(node);
}
