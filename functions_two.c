#include "monty.h"

/**
 * _swap - top two elements of stack are swapped
 * @stack: stack
 * @line_number: line number
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	int temp = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		cleanStack(stack);
		exit(EXIT_FAILURE);
	}
	temp = current->n;
	current->n = current->next->n;
	current->next->n = temp;
}
/**
 * _pop - top element of the stack is removed
 * @stack: tack list
 * @line_number: line number
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL;

	if (*stack == NULL || stack == NULL)
	{
		vprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", line_number);
		cleanStack(stack);
		exit(EXIT_FAILURE);
	}

	current = *stack;

	*stack = current->next;
	if (current->next != NULL)
		current->next->prev = current->prev;
	free(current);
}
/**
 * _add - function add two integer
 * @stack: stack list
 * @line_number: line number
 */
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL;
	int sum = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		cleanStack(stack);
		exit(EXIT_FAILURE);
	}
	current = *stack;
	sum = current->n + current->next->n;
	current->next->n = sum;
	_pop(stack, line_number);
}
/**
 * _nop - function void
 * @stack: stack list
 * @line_number: line number
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
