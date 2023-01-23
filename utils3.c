#include "monty.h"

/**
 * monty_loop - loop of the main program
 * @fp: a pointer to the file containing the monty ByteCodes
 *
 * Return: nothing
 */
void monty_loop(FILE *fp)
{
	int read;
	size_t len;
	char *line;
	char **instruction;

	len = 0;
	line = NULL;
	while ((read = getline(&line, &len, fp)) != -1)
	{
		code = malloc(sizeof(instruction_t));
		instruction = malloc(3 * sizeof(char *));

		if (code == NULL || instruction == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			free(line);
			free(code);
			fclose(fp);
			error_exit(&top);
		}

		parse(line, instruction);
		code->opcode = instruction[0];
		code->f = handler;
		run_code(instruction);
		line_number++;

		free(line);
		free(code);

		line = NULL;
		len = 0;
	}
}

/**
 * run_code - checks and runs the opcodes
 * @instruction: an array of strings containing
 * the opcode and its arguments
 *
 * Return: nothing
 */
void run_code(char **instruction)
{
	if (code->opcode == NULL || code->opcode[0] == '#')
	{
		code->opcode = "nop";
		(code->f)(&top, line_number);
	}
	else if (strcmp(code->opcode, "push") == 0)
	{
		push(instruction[1]);
	}
	else if (is_opcode(code->opcode) != -1)
	{
		(code->f)(&top, line_number);
	}
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, code->opcode);
		error_exit(&top);
	}
}

/**
 * get_opcodes - populates the opcodes list
 *
 * Return: nothing
 */
void get_opcodes(void)
{
	opcodes[0] = "pall";
	opcodes[1] = "pint";
	opcodes[2] = "pop";
	opcodes[3] = "swap";
	opcodes[4] = "add";
	opcodes[5] = "sub";
	opcodes[6] = "div";
	opcodes[7] = "mul";
	opcodes[8] = "mod";
	opcodes[9] = "pchar";
	opcodes[10] = "pstr";
	opcodes[11] = "rotl";
	opcodes[12] = "rotr";
	opcodes[13] = "stack";
	opcodes[14] = "queue";
	opcodes[15] = "nop";
	opcodes[16] = NULL;
}

/**
 * free_stack_t - Frees a linked stack_t list.
 * @head: The top of the stack_t list.
 */
void free_stack_t(stack_t *head)
{
	stack_t *temp;


	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

/**
 * error_exit - frees the stack and exits due to error
 * @stack: pointer to the head of the stack
 *
 */
void error_exit(stack_t **stack)
{
	if (*stack)
		free_stack_t(*stack);
	exit(EXIT_FAILURE);
}
