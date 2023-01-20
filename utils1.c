#include "monty.h"

/**
 * get_node - creates a new node for the stack
 *
 * Return: the address of the node created
 */
stack_t *get_node(void)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	return (node);
}

/**
 * is_empty - checks if stack or queue is empty
 *
 * Return: 1 if empty, 0 otherwise
 */
int is_empty(void)
{
	if (top == NULL)
		return (1);
	else
		return (0);
}

/**
 * add_node - Adds a new node at the beginning of a stack_t list.
 * @head: A pointer to the head of the stack_t list.
 * @n: The integer for the new node to contain.
 *
 * Return: If the function fails - NULL. otherwise the address
 * of the new node
 */
stack_t *add_node(stack_t **head, int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->prev = NULL;
	new->next = *head;
	if (*head != NULL)
		(*head)->prev = new;
	*head = new;

	return (new);
}

/**
 * add_node_end - Adds a new node at the end of a stack_t list.
 * @head: A pointer to the head of the stack_t list.
 * @n: The integer for the new node to contain.
 *
 * Return: If the function fails - NULL. otherwise the address
 * of the new node
 */
stack_t *add_node_end(stack_t **head, int n)
{
	stack_t *new, *last;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}

	last = *head;
	while (last->next != NULL)
		last = last->next;
	last->next = new;
	new->prev = last;

	return (new);
}

/**
 * isint - checks if a string is an integer
 * @str: the string
 *
 * Return: 1 if it is an integer, 0 otherwise
 */
int isint(char *str)
{
	int n;

	if (strlen(str) == 1)
	{
		if (str[0] == '0')
			return (1);
	}

	n = atoi(str);
	if (n == 0)
		return (0);
	else
		return (1);
}
