#include "monty.h"


/**
 * _push - pushes an integerer into the stack.
 * @stack: stack
 * @line_number: line_number of the file that's running
 */

void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = NULL;
	int push_arg_value = 0;

	global_data->flag = 0;
	if (global_data->array[1] == NULL)
		global_data->flag = 1;
	if (global_data->array[1])
		push_arg_value = string_to_int(global_data->array[1]);
	if (global_data->flag == 1)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		handle_error(1, global_data->file, *stack);
	}
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		handle_error(2, global_data->file, *stack);
	}

	new_node->prev = NULL;
	new_node->n = push_arg_value;
	if (*stack)
	{
		(*stack)->prev = new_node;
		new_node->next = *stack;
	}
	else
		new_node->next = NULL;
	*stack = new_node;
}

/**
 * _pall - pushes an integerer into the stack
 * @stack: stack
 * @line_number: line_number of the file that's running
 */

void _pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	stack_t *stack_aux = *stack;

	if (stack_aux == NULL)
		return;
	for (; stack_aux; stack_aux = stack_aux->next)
		printf("%d\n", stack_aux->n);
}


/**
 * _nop - does nothing
 * @stack: stack
 * @line_number: line_number of the file that's running
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}


/**
 * _pint - prints the value at the top of the stack
 * @stack: stack
 * @line_number: line number of the running string
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	stack_t *stack_aux = *stack;

	if (stack_aux == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		handle_error(1, global_data->file, *stack);
	}
	printf("%i\n", stack_aux->n);
}
