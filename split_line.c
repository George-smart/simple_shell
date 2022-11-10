#include "main.h"

#define TOK_BUFSIZE 64
#define TOK_DELIM " \t\r\n\a"

/**
 * split_line - splits a line of string into an array of words or tokens
 * @line: the string to be splited
 * Return: a pointer to the created tokens
 */
char **split_line(char *line)
{
	int bufsize = TOK_BUFSIZE, pos = 0;
	char *token, **tokens = malloc(bufsize * sizeof(char));

	if (!tokens)
	{
		fprintf(stderr, "tokens allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, TOK_DELIM);
	while (token != NULL)
	{
		tokens[pos] = token;
		pos++;

		if (pos >= bufsize)
		{
			bufsize += TOK_BUFSIZE;
			tokens = realloc(tokens, bufsize * sizeof(char));
			if (!tokens)
			{
				fprintf(stderr, "tokens: reallocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, TOK_DELIM);
	}
	tokens[pos] = NULL;
	return tokens;
}
