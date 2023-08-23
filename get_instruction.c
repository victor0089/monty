#include "monty.h"

/**
 * get_instruction - functionthatcall rightfunction
 * corresponding toanopcode.
 * @opcode: stringcommand.
 * Return: Apointerto theinstruction_t structorNULL.
 */
instruction_t *get_instruction(char *opcode)
{
static instruction_t instructions[] = {
{"push", push},
{"pall", pall},
{"pint", pint},
{"pop", pop},
{"swap", swap},
{"add", add},
{"nop", nop},
{"sub", sub},
{"div", div_op},
{"mul", mul_op},
{"mod", mod_op},
{"pchar", pchar_op},
{"pstr", pstr_op},
{NULL, NULL}};
int i;
for (i = 0; instructions[i].opcode != NULL; i++)
{
if (strcmp(opcode, instructions[i].opcode) == 0)
return (&instructions[i]);
}
return (NULL);
}