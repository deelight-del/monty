#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE
/*Include files*/
#include <stddef.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


extern stack_t *head;

/*Function prototypes*/
void read_file(char *buff, int n, char *file_path);
char *get_name(char *str);
char **tokenizer(char *line_string);
void (*get_op_func(char *str))(stack_t **stack, unsigned int line_number);
void free_array(char **array, int n);
void pint(stack_t **stack, unsigned int line_number);
char **get_tokens(char *line);
void print_arr(char **arr);
int takes_arg(char **opc);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void free_tokens(char **tokens);
stack_t *get_node(int val);
void pop(stack_t **stack, unsigned int line_number);
void exec_cmd_args(char **tokens, int line_number);
void exec_cmd_noarg(char **tokens, int line_number);
void free_stack(void);
int is_digit(char *str);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);

#endif
