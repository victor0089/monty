#include "monty.h"

/**
 * pstr_op - The opcode pstr prints the string starting at the top of the stack
 * @stack: Pointerto thestack.
 * @line_number: Linenumber oftheinstruction.
 * Return: void.
 */
void pstr_op(stack_t **stack, unsigned int line_number)
{
stack_t *tmp = *stack;
while (tmp != NULL && tmp->n != 0)
{
line_number = tmp->n;
if (line_number > 127)
break;
printf("%c", line_number);
tmp = tmp->next;
}
printf("\n");
}
