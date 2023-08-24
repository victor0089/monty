#include "monty.h"

/**
 * div_ The opcode div divides the second top element of the stack by  of the stack.
 * @stack: Pointerto thestack.
 * @line_number: Linenumber oftheinstruction.
 * Return: void.
 */
void div_op(stack_t **stack, unsigned int line_number)
{
int quotnt;
if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
exit(EXIT_FAILURE);
}
if ((*stack)->n == 0)
{
fprintf(stderr, "L%d: divisionbyzero\n", line_number);
exit(EXIT_FAILURE);
}
quotnt = (*stack)->next->n / (*stack)->n;
pop(stack, line_number);
(*stack)->n = quotnt;
}
