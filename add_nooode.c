#include "monty.h"

/**
 * add_node - functionthat addanew nodeatthe
 * beginning of adoubly linkedlist.
 * @stack: Pointerto apointer tothe stack.
 * @n: value toadd tothe stack.
 * Return: Theaddressof thenew nodeor NULL.
 */
stack_t *add_node(stack_t **stack, int n)
{
stack_t *noood;
noood = malloc(sizeof(stack_t));
if (noood == NULL)
return (NULL);
noood->n = n;
noood->prev = NULL;
noood->next = *stack;
if (*stack != NULL)
(*stack)->prev = noood;
*stack = noood;
return (noood);
}
