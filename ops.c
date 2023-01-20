#include "monty.h"

/**
 * push - pushes an element to the stack
 * @arg: a string of the integer to be pushed
 *
 * Return: nothing
 */
void push(char *arg)
{
	stack_t *node;

	if (!(isint(arg)) || arg == NULL)
	{
		printf("L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (stack_switch == 1)
		node = add_node(&top, atoi(arg));
	else
		node = add_node_end(&top, atoi(arg));

	if (node == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (stack_switch == 1)
		front = top;
	else
		rear = node;

	node = NULL;
}

/**
 * pall - prints all the values on the stack,
 * starting from the top of the stack.
 * @stack: pointer to top of the stack
 * @line_number: line number
 *
 * Return: nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	UNUSED(line_number);
	if (is_empty())
		return;

	temp = *stack;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pint - prints the value at the top of the stack, followed by a new line.
 * @stack: pointer to top of the stack
 * @line_number: line number
 *
 * Return: nothing
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (is_empty())
	{
		printf("L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of the stack.
 * @stack: pointer to top of the stack
 * @line_number: line number
 *
 * Return: nothing
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (is_empty())
	{
		printf("L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	(*stack)->prev = NULL;
	*stack = (*stack)->next;
	free(temp);
	front = top;

	if (is_empty())
		rear = *stack;
}

/**
 * swap - swaps the top two elements of the stack.
 * @stack: pointer to top of the stack
 * @line_number: line number
 *
 * Return: nothing
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int first;
	int second;

	if (stack_t_len(*stack) < 2)
	{
		printf("L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	first = (*stack)->n;
	second = (*stack)->next->n;

	(*stack)->next->n = first;
	(*stack)->n = second;
}
