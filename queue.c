#include "monty.h"
/**
 * queue - prints thetop
 * @stack: stackhead
 * @line: line_number
 * Return: no return
*/
void f_queue(stack_t **stack, unsigned int line)
{
(void)stack;
(void)line;
bus.lifi = 1;
}
/**
* addqueue - add nodeto the tailstack
* @n: new_value
* @stack: head ofthestack
* Return: no return
*/
void addqueue(stack_t **stack, int n)
{
stack_t *new_node, *xx;
xx = *stack;
new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
printf("Error\n");
}
new_node->n = n;
new_node->next = NULL;
if (xx)
{
while (xx->next)
xx = xx->next;
}
if (!xx)
{
*stack = new_node;
new_node->prev = NULL;
}
else
{
xx->next = new_node;
new_node->prev = xx;
}
}
