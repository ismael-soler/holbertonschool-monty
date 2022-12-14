#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>


/**
 * struct data_s - stuff I need idk
 * @flag: flag to determine if the program worked properly
 * @file: FILE
 * @array: array that containts the tokenized line
 */
typedef struct data_s
{
	int flag;
	FILE *file;
	char **array;
} data_t;

extern data_t *global_data;
/**
 * struct stack_s - doubly linked list representation of a stack or queue)
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

int check_argument(char *);
int open_file(char *);
int exec_file(FILE *);
void (*get_func(char *))(stack_t **, unsigned int);
char **buff_to_array(char *, char *);
int free_array(char **array);
void handle_error(int, FILE *, stack_t *);
void free_stack(stack_t *stack);
int string_to_int(char *);


void _push(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _sub(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
#endif
