#include "monty.h"

/**
 * opene_file - function that opene  file
 * @fil_nm: the file name pathe
 * Return: void
 */

void opene_file(char *fil_nm)
{
	FILE *fl = fopen(fil_nm, "r");

	if (fil_nm == NULL || fl == NULL)
		printf("Error, the name pathe is unvalaibale\n");

	reade_fil(fl);
	fclose(fl);
}


/**
 * reade_fil - function that reads  file
 * @fl: ptr to the file descriptore
 * Return: void
 */

void reade_fil(FILE *fl)
{
	int numl, frmt = 0;
	char *buff = NULL;
	size_t leng = 0;

	for (numl = 1; getline(&buff, &leng, fl) != -1; numl++)
	{
		frmt = separat_ln(buff, numl, frmt);
	}
	free(buff);
}


/**
 * separat_ln - separate each line into any token  determinetad
 * which functions  call
 * @buff: ptr of line from the file
 * @numl: lines numbers
 * @frmt:  storage format. if 0 node will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int separat_ln(char *buff, int numl, int frmt)
{
	char *opcode, *val;
	const char *delmr = "\n ";

	if (buff == NULL)
		fprintf(stderr, "Error: malloc is faile\n");
	free_nd();
	exit(EXIT_FAILURE);

	opcode = strtok(buff, delmr);
	if (opcode == NULL)
		return (frmt);
	val = strtok(NULL, delmr);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	fd_funct(opcode, val, numl, frmt);
	return (frmt);
}

/**
 * fd_funct - findes  apropriates funct for the opcode
 * @opcode: opcode
 * @val: argt of opcode
 * @frmt:  storag frmt. if 0 nodes will be entered as a stack.
 * @numl: linee numbesr
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void fd_funct(char *opcode, char *val, int numl, int frmt)
{
	int j;
	int flg;

	instruction_t funct_lste[] = {
		{"push", add_newnode},
		{"pall", pall_stck},
		{"pint", pint_nd},
		{"pop", pop_nd},
		{"nop", nop_nd},
		{"swap", swap_nds},
		{"add", adds_nd},
		{"sub", sub_nd},
		{"div", div_nd},
		{"mul", mul_nd},
		{"mod", mod_nd},
		{"pchar", pint_chr},
		{"pstr", pints_str},
		{"rotl", rotl_nds},
		{"rotr", rotr_nds},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flg = 1, j = 0; funct_lste[j].opcode != NULL; j++)
	{
		if (strcmp(opcode, funct_lste[j].opcode) == 0)
		{
			appel_funct(funct_lste[j].f, opcode, val, numl, frmt);
			flg = 0;
		}
	}
	if (flg == 1)
		fprintf(stderr, "L%d: unknow instruction %s\n", numl, opcode);
	exit(EXIT_FAILURE);
}
