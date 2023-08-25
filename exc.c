#include "monty.h"
/**
* execute - executestheopcode
* @stack: head linked list - stack
* @counter: line_counter
* @file: poiner to monty file
* @line_number: line content
* Return: no return
*/
int execute(char *line_number, stack_t **stack, unsigned int counter, FILE *file)
{
instruction_t opst[] = {
{"push", push}, {"pall", pall}, {"pint", pint},
{"pop", pop},
{"swap", swap},
{"add", add},
{"nop", nop},
{"sub", sub},
{"div", div},
{"mul", mul_op},
{"mod", mod_op},
{"pchar", pchar_op},
{"pstr", pstr_op},
{"rotl", rotl},
{"rotr", rotr},
{"queue", queue},
{"stack", stack},
{NULL, NULL}
};
unsigned int i = 0;
char *op;
op = strtok(line_number, " \n\t");
if (op && op[0] == '#')
return (0);
bus.arg = strtok(NULL, " \n\t");
while (opst[i].opcode && op)
{
if (strcmp(op, opst[i].opcode) == 0)
{	opst[i].f(stack, counter);
return (0);
}
i++;
}
if (op && opst[i].opcode == NULL)
{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
fclose(file);
free(line_number);
free_stack(*stack);
exit(EXIT_FAILURE); }
return (1);
}
