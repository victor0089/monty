#include "monty.h"

/**
 * mul_op - opcode mul multiplies the second top element  of the stack.
 * @stack: Pointerto thestack.
 * @line_number: Linenumber oftheinstruction.
 * Return: void.
 */
void mul_op(stack_t **stack, unsigned int line_number)
{
int product;
if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
exit(EXIT_FAILURE);
}
product = (*stack)->next->n * (*stack)->n;
pop(stack, line_number);
(*stack)->n = product;
}
