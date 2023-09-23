#include "monty.h"

/**
 * get_tokens - gets tokens from a file
 * @line: string of command
 * description: splits a string into tokens
 * Return: array of tokens or NULL
*/


char **get_tokens(char *line)
{
	char *token, *delim;
	int count;
	char **tokens;

	count = 0;
	delim = " \t\n";

	if (line == NULL)
		return (NULL);

	tokens = malloc(sizeof(char *) * 3);
	if (tokens == NULL)
		return (NULL);
	token = strtok(line, delim);
	if (token == NULL)
	{
		free(tokens);
		return (NULL);
	}
	while (token != NULL && count <= 2)
	{
		tokens[count] = token;
		count++;
		token = strtok(NULL, delim);
	}
	tokens[count] = NULL;
	return (tokens);
}
