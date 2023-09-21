#include "monty.h"
/**
 * read_file - reads a line from a file
 * @buff: buffer to store the line
 * @n: number of bytes read
 * @file_path: path of file to read
 * Return: number of bytes read or -1
*/


ssize_t read_file(char **buff, size_t *n, char *file_path)
{
	/*open file*/
	FILE *file_ptr;
	ssize_t bytes_r;

	file_ptr = fopen(file_path, "r");
	if (file_ptr == NULL)
	{
		/*you need to move the file pointer to print only file name and not*/
		fprintf(stderr, "Can't open %s\n", file_path);
		exit(EXIT_FAILURE);
	}
	else
	{
		bytes_r = getline(buff, n, file_ptr);
		return (bytes_r);
	}
}
