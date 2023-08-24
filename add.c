#include "monty.h"

/**
 * add - functionthat sumsthe toptwo elementsin thestack.
 * @stack: Pointerto thestack.
 * @line_number: Linenumberof theinstuction.
 * Return: void.
 */
void add(stack_t **stack, unsigned int line_number)
{
int summ;
if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%d: can't add,stack tooshort\n", line_number);
exit(EXIT_FAILURE);
}
summ = (*stack)->n + (*stack)->next->n;
pop(stack, line_number);
(*stack)->n = summ;
}
