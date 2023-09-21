#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

void print_array(char **array)
{
	int i;

	if (array == NULL)
	{
		printf("NULL\n");
		return;
	}
	for (i = 0; array[i] != NULL; i++)
		printf("%s\n", array[i]);
	free_array(array, -1);
}


int main(void)
{
	char **array;

	char *three_words = "For God So";
	char *two_words = "For God";
	char *one_word = "For";
	char *no_word = "";
	char *blank = "          ";
	char *lots_of_words = " There are some       ton ..of words here \n";

	printf("Three words:\n");
	array = tokenizer(three_words);
	print_array(array);
	printf("Two words:\n");
	array = tokenizer(two_words);
	print_array(array);
	printf("one word:\n");
	array = tokenizer(one_word);
	print_array(array);
	printf("No words: \n");
	array = tokenizer(no_word);
	print_array(array);
	printf("Blank words:\n");
	array = tokenizer(blank);
	print_array(array);
	printf("Lots of words:\n");
	array = tokenizer(lots_of_words);
	print_array(array);
	return (1);
}
