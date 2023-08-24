#include "monty.h"
/**
* free_stack - frees adoublylinked list
* @stack: head ofthestack
*/
void free_stack(stack_t *stack)
{
stack_t *xx;
xx = stack;
while (stack)
{
xxx = stack->next;
free(stack);
stack = xx;
}
}
