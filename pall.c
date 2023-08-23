#include "monty.h"

/**
 * pall - function that printall theelements inthestack.
 * @stack: Pointerto thestack.
 * @line_number: Linenumberof theinstruction.
 * Return: void.
 */
void pall(stack_t **stack, unsigned int line_number)
{
stack_t *node = *stack;
(void)line_number;
while (node != NULL)
{
printf("%d\n", node->n);
node = node->next;
}
}
