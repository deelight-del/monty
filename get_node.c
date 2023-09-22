#include "monty.h"

/**
 * get_node - gets a  node
 * @val: value to store in new_node
 * description: gets a node
 * Return: pointer to a node
*/

stack_t *get_node(int val)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		return (NULL);
	}
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->n = val;
	return (new_node);
}
