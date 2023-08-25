#include "monty.h"

/**
 * add - functionthat sumsthe toptwo elementsin thestack.
 * @stack: Pointerto thestack.
 * @line_number: Linenumberof theinstuction.
 * Return: void.
 */
void add(stack_t **stack, unsigned int line_number)
{
stack_t *h;
int len = 0, xx;
h = *stack;
while (h)
{
h = h->next;
len++;
}
if (len < 2)
{
fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
free(bus.line_number);
free_stack(*stack);
exit(EXIT_FAILURE);
}
h = *stack;
xx = h->n + h->next->n;
h->next->n = xx;
*stack = h->next;
free(h);
}
