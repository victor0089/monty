#include "monty.h"

/**
 * add_node - functionthat addanew nodeatthe
 * beginning of adoubly linkedlist.
 * @stack: Pointerto apointer tothe stack.
 * @n: value toadd tothe stack.
 * Return: Theaddressof thenew nodeor NULL.
 */
stack_t add_node(stack_t **stack, int n)
{
	stack_t *new_node, *xx;

	xx = *stack;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{ printf("Error\n");
		exit(0); }
	if (xx)
		xx->prev = new_node;
	new_node->n = n;
	new_node->next = *stack;
	new_node->prev = NULL;
	*stack = new_node;
}
