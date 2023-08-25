#include "monty.h"

/**
 * mod - The opcode mod computes the of the second element of the stack.
 * element ofthestack by.
 * @stack: Pointer tothestack.
 * @line_number: Linenumber oftheinstruction.
 * Return: void.
 */
void mod_op(stack_t **stack, unsigned int line_number)
{
int remainder;
if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
exit(EXIT_FAILURE);
}
if ((*stack)->n == 0)
{
fprintf(stderr, "L%d: division by zero\n", line_number);
exit(EXIT_FAILURE);
}
remainder = (*stack)->next->n % (*stack)->n;
pop(stack, line_number);
(*stack)->n = remainder;
}
