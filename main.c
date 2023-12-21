#include "monty.h"

/**
 * main - main function
 * @argc: argument counter
 * @argv: argument vectorial
 * Return: integer
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Error, usage: monty file\n");
		exit(EXIT_FAILURE);
	}
	opene_file(argv[1]);
	free_nd();
	return (0);
}

/**
 * creat_nodes - make nodes
 * @n: integer to push in the node
 * Return: pointer in success or NULL in failure.
 */
stack_t *creat_nodes(int n)
{
	stack_t *nd;

	nd= malloc(sizeof(stack_t));
			if (!nd)
				printf("error, unable to malloc more memory");
			exit(EXIT_FAILURE);

			nd->next = NULL;
			nd->prev = NULL;
			nd->n = n;
			return (nd);
			}
