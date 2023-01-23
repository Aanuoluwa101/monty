#include "monty.h"

/**
 * stack_t_len - Counts the number of elements in a linked stack_t list.
 * @h: The head of the stack_t list.
 *
 * Return: The number of elements in the stack_t list.
 */
size_t stack_t_len(stack_t *h)
{
	size_t n_nodes;
	stack_t *temp;

	n_nodes = 0;
	temp = h;

	while (temp)
	{
		n_nodes++;
		temp = temp->next;
	}

	return (n_nodes);
}

/**
 * is_opcode - checks if an opcode is a valid one
 * @opcode: the opcode to be checked
 *
 * Return: the position at which the opcode was found
 * in the list of opcodes, or -1 if it is not a valid opcode
 */
int is_opcode(char *opcode)
{
	int n;

	n = 0;
	while (opcodes[n])
	{
		if (strcmp(opcode, opcodes[n]) == 0)
			return (n);
		n++;
	}
	return (-1);
}

/**
 * handler - runs an opcode
 * @stack: a pointer to the head of the stack
 * @line_number: the line with the opcode
 *
 * Return: nothing
 */
void handler(stack_t **stack, unsigned int line_number)
{
	int n;

	n = is_opcode(code->opcode);
	f_list[n](stack, line_number);
}

/**
 * parse - parses the instruction on a line
 * @line: the line to be parsed
 * @instruction: an array of string pointers to
 * contain the opcode and its argument
 *
 * Return: nothing
 */
void parse(char *line, char **instruction)
{
	char *token;
	int n;

	n = 0;
	token = strtok(line, " \n");
	instruction[n] = token;
	while (n <= 1)
	{
		n++;
		token = strtok(NULL, " \n");
		instruction[n] = token;
	}
}

/**
 * get_functions - populates the array of function pointers
 *
 * Return: nothing
 */
void get_functions(void)
{
	f_list[0] = pall;
	f_list[1] = pint;
	f_list[2] = pop;
	f_list[3] = swap;
	f_list[4] = add;
	f_list[5] = sub;
	f_list[6] = _div;
	f_list[7] = mul;
	f_list[8] = mod;
	f_list[9] = pchar;
	f_list[10] = pstr;
	f_list[11] = rotl;
	f_list[12] = rotr;
	f_list[13] = _stack;
	f_list[14] = _queue;
	f_list[15] = nop;
}

