#include "monty.h"

/**
 * add - adds the top two elements of the stack.
 * @stack: pointer to top of the stack
 * @line_number: line number
 *
 * Return: nothing
 */
void add(stack_t **stack, unsigned int line_number)
{
	int result;

	if (stack_t_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		error_exit(stack);
	}

	result = (*stack)->n + (*stack)->next->n;
	(*stack)->next->n = result;
	pop(stack, line_number);
}


/**
 * sub -  subtracts the top element of the stack
 * from the second top element of the stack.
 * @stack: pointer to top of the stack
 * @line_number: line number
 *
 * Return: nothing
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int result;

	if (stack_t_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		error_exit(stack);
	}

	result =  (*stack)->next->n - (*stack)->n;
	(*stack)->next->n = result;
	pop(stack, line_number);
}

/**
 * _div- divides the second top element of the
 * stack by the top element of the stack.
 * @stack: pointer to top of the stack
 * @line_number: line number
 *
 * Return: nothing
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int result;

	if (stack_t_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		error_exit(stack);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		error_exit(stack);
	}

	result = (*stack)->n / (*stack)->next->n;
	(*stack)->next->n = result;
	pop(stack, line_number);
}

/**
 * mul - multiplies the second top element of the
 * stack with the top element of the stack.
 * @stack: pointer to top of the stack
 * @line_number: line number
 *
 * Return: nothing
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int result;

	if (stack_t_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		error_exit(stack);
	}

	result = (*stack)->n * (*stack)->next->n;
	(*stack)->next->n = result;
	pop(stack, line_number);
}

/**
 * mod - computes the rest of the division of the second
 * top element of the stack by the top element of the stack.
 * @stack: pointer to top of the stack
 * @line_number: line number
 *
 * Return: nothing
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int result;

	if (stack_t_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		error_exit(stack);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		error_exit(stack);
	}

	result = (*stack)->n % (*stack)->next->n;
	(*stack)->next->n = result;
	pop(stack, line_number);
}
