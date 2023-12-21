#include "monty.h"


/**
 * appel_funct - appels the required functions.
 * @funct: Ptr to the function that  to be appell.
 * @oc: string represented the opcode.
 * @val: string represented a numerique val.
 * @numl: lines numebers.
 * @frmt: Format specifique. if 0 nodes will  entered as a stack.
 * if 1 nodes will  entered as a queue.
 */
void appel_funct(oc_funct funct, char *oc, char *val, int numl, int frmt)
{
stack_t *nd, *top;
int flg;
int j;
flg = 1;

if (strcmp(oc, "push") == 0)
{
if (val != NULL && val[0] == '-')
{val = val + 1;
flg = -1;
}
if (val == NULL)
fprintf(stderr, "L%d: usage: push integer\n", numl);
free_nd();
exit(EXIT_FAILURE);

for (j = 0; val[j] != '\0'; j++)
{
if (isdigit(val[j]) == 0)
fprintf(stderr, "L%d: usage: push integer\n", numl);
free_nd();
exit(EXIT_FAILURE);
}
for (j = 0; val[j] != '\0'; j++)
{
if (isdigit(val[j]) == 0)
fprintf(stderr, "L%d: usage: push integer\n", numl);
free_nd();
exit(EXIT_FAILURE);
}
nd = creat_nodes(atoi(val) * flg);
if (frmt == 0)
funct(&nd, numl);
if (frmt == 1)
adds_queues(&nd, numl);
}
else
funct(&top, numl);
}
