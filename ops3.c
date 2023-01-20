#include "monty.h"

/**
 * nop - does nothing
 */
void nop(void)
{
	;
}

/**
 * pchar -  prints the char at the top of the stack, followed by a new line.
 * @stack: pointer to top of the stack
 * @line_number: line number
 *
 * Return: nothing
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int n;

	if (is_empty())
	{
		printf("L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	n = (*stack)->n;

	if (n < 0 || n > 127)
	{
		printf("L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", n);
}

/**
 * pstr -  prints the string starting at the top
 * of the stack, followed by a new line.
 * @stack: pointer to top of the stack
 * @line_number: line number
 *
 * Return: nothing
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	UNUSED(line_number);
	if (is_empty())
	{
		printf("\n");
		return;
	}

	temp = *stack;
	while (temp)
	{
		if (temp->n == 0)
			break;
		else if (temp->n < 0 || temp->n > 127)
			break;

		printf("%c", temp->n);
	}

	printf("\n");
}

/**
 * rotl -  rotates the stack to the top.
 * @stack: pointer to top of the stack
 * @line_number: line number
 *
 * Return: nothing
 */
void rotl(stack_t **stack,unsigned int line_number)
{
	int n;
	stack_t *node;

	if (is_empty())
		return;

	n = (*stack)->n;
	node = add_node_end(stack, n);

	if (node == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	pop(stack, line_number);
}

/**
 * rotr - rotates the stack
 * @stack: pointer to top of the stack
 * @line_number: line number
 *
 * Return: nothing
 */
void rotr(stack_t **stack,unsigned int line_number)
{
	UNUSED(stack);
	UNUSED(line_number);
	;
}
