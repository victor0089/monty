#include "monty.h"
bus_t bus = {NULL, NULL, NULL, 0};
/**
 * main - Entry pointof theprogram.
 * @argc: Number ofarguments.
 * @argv: Array ofarguments.
 * Return: 0 if successful, 1 otherwise.
 */
int main(int argc, char *argv[])
{
FILE *file;
char *line = NULL, *new_line = NULL, *token;
size_t len = 0;
ssize_t read;
unsigned int line_number = 0;
stack_t *stack = NULL;
instruction_t *instruction;
if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
return (EXIT_FAILURE);
}
file = fopen(argv[1], "r");
if (file == NULL)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
return (EXIT_FAILURE);
}
while ((read = getline(&line, &len, file)) != -1)
{
new_line = line;
while (*new_line && *new_line == ' ')
new_line++;
if (strcmp(new_line, "$\n") == 0 || is_comment(new_line) == 1)
continue;
token = strtok(new_line, " \t$\n;+");
instruction = get_instruction(token);
line_number++;
if (instruction == NULL)
{
fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
free_and_close(line, file);
exit(EXIT_FAILURE);
}
instruction->f(&stack, line_number);
}
free_and_close(line, file);
return (EXIT_SUCCESS);
}
/**
 * free_and_close - functionthat freeline andcloses thefile.
 * @line: Pointer tothe line.
 * @file: Pointer tothe file.
 * Return: void.
 */
void free_and_close(char *line, FILE *file)
{
free(line);
fclose(file);
}
/**
 * is_comment - function thatcheck ifthe lineiscomment.
 * @line: Pointerto theline.
 * Return: 1 or 0.
 */
int is_comment(char *line)
{
int i;
for (i = 0; line[i] != '\0'; i++)
{
if (line[i] == '#')
return (1);
if (line[i] != ' ' && line[i] != '\t')
return (0);
}
return (1);
}
