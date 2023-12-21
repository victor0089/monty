#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <fcntl.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **data, unsigned int numl);
} instruction_t;

typedef void (*oc_funct)(stack_t **, unsigned int);
extern stack_t *top;

stack_t  *creat_nodes(int n);
void free_nd(void);
void adds_queues(stack_t **data, unsigned int numl);
void add_newnode(stack_t **NEW_nd, __attribute__((unused)) unsigned int numl);
void pall_stck(stack_t **data, unsigned int numl);
void nop_nd(stack_t **data, unsigned int numl);
void swap_nds(stack_t **data, unsigned int numl);
void pint_nd(stack_t **data, unsigned int numl);
void pop_nd(stack_t **data, unsigned int numl);
void appel_funct(oc_funct funct, char *oc, char *val, int numl, int frmt);
void opene_file(char *fil_nm);
void reade_fil(FILE *fl);
int separat_ln(char *buff, int numl, int frmt);
void fd_funct(char *opcode, char *val, int numl, int frmt);
void rotr_nds(stack_t **data, __attribute__((unused))unsigned int numl);
void rotl_nds(stack_t **data, __attribute__((unused))unsigned int numl);
void pints_str(stack_t **data, __attribute__((unused))unsigned int numl);
void pint_chr(stack_t **data, unsigned int num);
void mod_nd(stack_t **data, unsigned int numl);
void mul_nd(stack_t **data, unsigned int numl);
void div_nd(stack_t **data, unsigned int numl);
void sub_nd(stack_t **data, unsigned int numl);
void adds_nd(stack_t **data, unsigned int numl);

#endif
