#include "monty.h"
bus_t bus = {NULL, NULL, NULL, 0};
/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	char *line_number;
	FILE *file;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	bus.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
	line_number = NULL;
	read_line = getline(&line_number, &size, file);
	bus.line_number = line_number;
	counter++;
	if (read_line > 0)
	{
	get_instruction(line_number, &stack, counter, file);
	}
	free(line_number);
	}
	free_stack(stack);
	fclose(file);
return (0);
}
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
