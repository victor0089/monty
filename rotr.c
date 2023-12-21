#include "monty.h"
/**
*rotr- rotates the stack to the bottom
*@stack: stack head
*@line_number: line_number
*Return: no return
*/
void rotr(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
stack_t *copy;
copy = *stack;
if (*stack == NULL || (*stack)->next == NULL)
{
return;
}
while (copy->next)
{
copy = copy->next;
}
copy->next = *stack;
copy->prev->next = NULL;
copy->prev = NULL;
(*stack)->prev = copy;
(*stack) = copy;
}
