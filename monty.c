#include "monty.h"

unsigned short stack_switch = 1;
/**
 * main - entry point of the program
 * @argc: arguments counts
 * @argv: arguments vector
 *
 * Return: 0
 */
int main(int argc, char **argv)
{
	FILE *fp;


	line_number = 1;
	get_functions();
	get_opcodes();

	if (argc > 2 || argc == 1)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	monty_loop(fp);

	return (0);
}


