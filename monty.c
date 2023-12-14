#include "monty.h"

glob_t global = {NULL, NULL};
/**
 * main - entry point
 * @argc: number of arguments
 * @argv: arguments
 * Return: arguments number
 */
int main(int argc, char *argv[])
{
	if (argc == 2)
		handle_command(argv[1]);
	else
	{
		vprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}
