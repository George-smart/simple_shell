#include "main.h"

/**
 * main - Entry point of the program
 *
 * @argc: number of arguments passed in
 * @argv: list of arguments passed in
 * @env: list of environment variables
 *
 * Return: 0 on success
 */

int main(int argc, char *argv[], char *env[])
{
	char *line;
	char **args;
	int status;

	do {
		printf("$ ");
		if (argc >= 2)
			args = argv;
		else
		{
			line = read_line_02();
			args = split_line(line);
		}
		status = executor(args, env);

		free(line);
		free(args);
	} while (status);

	printf("%d %s %s\n", argc, argv[0], env[0]);
	return 0;
}
