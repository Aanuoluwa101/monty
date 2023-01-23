#ifndef MONTY_H
#define MONTY_H

#define UNUSED(x) (void)(x)
#define _GNU_SOURCE
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

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
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* variables declarations */

extern unsigned short stack_switch;
stack_t *top;
stack_t *front;
stack_t *rear;
instruction_t *code;
void (*f_list[16])(stack_t **stack, unsigned int line_number);
char *opcodes[17];
unsigned int line_number;


/* function declarations */

stack_t *get_node(void);
int is_empty(stack_t **stack);
stack_t *add_node(stack_t **head, int n);
stack_t *add_node_end(stack_t **head, int n);
size_t stack_t_len(stack_t *h);
void free_stack_t(stack_t *head);
int isdigit(int ch);
void error_exit(stack_t **stack);
int isint(char *str);
void push(char *arg);
void pall(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void _stack(stack_t **stack, unsigned int line_number);
void _queue(stack_t **stack, unsigned int line_number);
void get_functions(void);
int is_opcode(char *opcode);
void handler(stack_t **stack, unsigned int line_number);
void parse(char *line, char **instruction);
void monty_loop(FILE *fp);
void run_code(char **instruction);
void get_opcodes(void);

#endif /* MONTY_H */
