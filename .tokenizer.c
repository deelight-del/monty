#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "monty.h"

/**
 * tokenizer - Function to tokenize a string int array of string
 * @line_string: The string to tokenize.
 *
 * Return: An array of strings or NULL
 */

char **tokenizer(char *line_string)
{
	int i = 1;
	char *token, **array, *copy_line;

	if (line_string == NULL)
		return (NULL);
	array = malloc(sizeof(char *) * 4);
	if (array == NULL)
		return (NULL);
	copy_line = strdup(line_string);
	if (copy_line == NULL)
		return (NULL);
	token = strtok(copy_line, " ");
	if (token == NULL)
	{
		free(array);
		free(copy_line);	/*FREE THE LINE STRING LATER ON and array, LIKELY*/
		return (NULL);
	}
	array[0] = strdup(token);  /*check for null -- done below*/
	while (token != NULL)
	{
		if (i > 2 || array[i - 1] == NULL)  /*Checks for NULL of an array*/
		{
			free_array(array, i);
			free(copy_line);
			return (NULL);
		}
		token = strtok(NULL, " ");
		if (token != NULL)
		{
			array[i] = strdup(token); /*chack for null*/
			i++;
		}
	}
	array[i] = NULL; /*Terminating array with NULL*/
	free(copy_line);
	return (array); /*free array outside of their use*/
}

/**
 * free_array - Function to free the respective array created from tokenization
 * @array: Array to be tokenized
 * @n: used to see if free_array is within function 'tokenizer' or not.
 * description: frees allocated space
 * Return: Nothing
*/

void free_array(char **array, int n)  /*USAGE: (array, -1)*/
{
	int i;

	if (n > 2)
		array[n] = NULL;
	if (array == NULL)
		return;

	for (i = 0; array[i] != NULL; i++)
	{
		free(array[i]);
	}
	free(array);
}
