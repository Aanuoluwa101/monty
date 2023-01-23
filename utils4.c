#include "monty.h"

/**
 * isdigit - checks if a character is a digit
 * @ch: the character
 *
 * Return: 1 if ch is a digit, 0 otherwise
 */
int isdigit(int ch)
{
	if (ch < 48 || ch > 57)
		return (0);
	return (1);
}
