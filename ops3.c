#include "monty.h"

/**
 * nop - does nothing
 * @stack: pointer to the top of the stack
 * @line_number: line_number
 */
void nop(stack_t **stack, unsigned int line_number)
{
	UNUSED(stack);
	UNUSED(line_number);
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

	if (is_empty(stack))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		error_exit(stack);
	}

	n = (*stack)->n;

	if (n < 0 || n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		error_exit(stack);
	}

	putchar(n);
	putchar('\n');
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
	int chr;

	UNUSED(line_number);
	temp = *stack;

	while (temp)
	{
		chr = temp->n;
		if (chr == 0)
			break;
		else if (chr < 0 || chr > 127)
			break;

		printf("%c", chr);
		temp = temp->next;
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
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *first;
	stack_t *temp;

	UNUSED(line_number);
	if (!is_empty(stack) && stack_t_len(*stack) >= 2)
	{
		first = *stack;
		temp = *stack;

		while (temp->next != NULL)
			temp = temp->next;

		temp->next = first;
		first->prev = temp;
		*stack = (*stack)->next;
		first->next = NULL;
		(*stack)->prev = NULL;
	}
}

/**
 * rotr - rotates the stack
 * @stack: pointer to top of the stack
 * @line_number: line number
 *
 * Return: nothing
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *last;

	UNUSED(line_number);
	if (!is_empty(stack) && stack_t_len(*stack) >= 2)
	{
		last = *stack;
		while (last->next != NULL)
			last = last->next;

		last->prev->next = NULL;
		last->next = *stack;
		last->prev = NULL;
		(*stack)->prev = last;
		*stack = last;
	}
}
