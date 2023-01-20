#include "monty.h"

/**
 * stack - sets the format of the data to a stack (LIFO)
 * @stack: pointer to top of the stack
 * @line_number: line number
 *
 * Return: nothing
 */
void _stack(stack_t **stack, unsigned int line_number)
{
	UNUSED(stack);
	UNUSED(line_number);

	stack_switch = 1;
}

/**
 * queue - sets the format of the data to a queue (FIFO)
 * @stack: pointer to top of the stack
 * @line_number: line number
 *
 * Return: nothing
 */
void _queue(stack_t **stack, unsigned int line_number)
{
	UNUSED(stack);
	UNUSED(line_number);

	stack_switch = 0;
}
