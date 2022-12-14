#include "main.h"

#define LINE_BUFSIZE 1024
/**
 * read_line_01 - reads a line of string from the terminal
 * or a file
 *
 * Return: a pointer to the line of string
 *
 */
char *read_line_01(void)
{
	int c, pos = 0, bufsize = LINE_BUFSIZE;
	char *buffer = malloc(bufsize * sizeof(char));

	if (!buffer)
	{
		fprintf(stderr, "buffer: allocation error\n");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		c = getchar();

		if (c != EOF && c != '\n')
			buffer[pos] = c;
		else
		{
			buffer[pos] = '\0';
			return (buffer);
		}

		pos++;

		if (pos >= bufsize)
		{
			bufsize += LINE_BUFSIZE;
			buffer = realloc(buffer, bufsize);
			if (!buffer)
			{
				fprintf(stderr, "buffer: reallocation error\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}
