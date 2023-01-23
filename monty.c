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
		fprintf(stderr, "USAGE: monty file\n");
		error_exit(&top);
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		error_exit(&top);
	}
	monty_loop(fp);
	fclose(fp);

	return (0);
}


