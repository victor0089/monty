#include "monty.h"
/**
*rotl- rotates the stacktothe top
*@stack: stackhead
*@line_number: line_number
*Return: no return
 */
void rotl(stack_t **stack,  __attribute__((unused)) unsigned int line_number)
{
stack_t *tmp = *stack, *xx;
if (*stack == NULL || (*stack)->next == NULL)
{
return;
}
xx = (*stack)->next;
xx->prev = NULL;
while (tmp->next != NULL)
{
tmp = tmp->next;
}
tmp->next = *stack;
(*stack)->next = NULL;
(*stack)->prev = tmp;
(*stack) = xx;
}
