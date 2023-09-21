#include "monty.h"
/**
 * get_name - gets the name of a file
 * @str: file path
 * description: gets the name of a file from a path
 * Return:file name or NULL
*/


char *get_name(char *str)
{
	int flag;
	char *ptr, *token, *token_prev, *delim;

	if (str == NULL)
		return (NULL);
	flag = 0;
	ptr = str;
	delim = "/\n";
	while (*ptr)
	{
		if (*ptr == '/')
		{
			flag = 1;
			break;
		}
		ptr++;
	}
	if (flag == 1)
	{
		token = strtok(str, delim);
		while (token)
		{
			token_prev = token;
			token = strtok(NULL, delim);
		}
		return (token_prev);
	}
	return (str);
}
