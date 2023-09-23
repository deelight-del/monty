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
	while (token != NULL && count <= 1)
	{
		tokens[count] = token;
		count++;
		token = strtok(NULL, delim);
	}
	tokens[count] = NULL;
	return (tokens);
}

/**
 * free_tokens - Function to free an array of tokens
 * @tokens: An array of given tokens to be freed.
 *
 * Return: Nothing.
 */

void free_tokens(char **tokens)
{
	int i = 0;

	if (tokens == NULL)
		return;

	for (i = 0; tokens[i] != NULL; i++)
	{
		free(tokens[i]);
	}
	free(tokens);
}
