#include "monty.h"

int value;
/**
 * new_Node - new node created
 * @n: value
 * Return: new node
 */
stack_t *new_Node(int n)
{
	stack_t *new = NULL;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->next = NULL;
	new->prev = NULL;

	return (new);
}
/**
 * _push - push item
 * @stack: is a parameter
 * @line_number: is value
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL;
	(void)line_number;

	new = new_Node(value);

	new->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
}
/**
 * _pall - elements stack printed
 * @stack: parameter
 * @n: value
 * Return: nothing
 */
void _pall(stack_t **stack, unsigned int n)
{
	stack_t *current = NULL;
	(void)n;

	current = *stack;

	while (current != NULL)
	{
		dprintf(STDOUT_FILENO, "%d\n", current->n);
		current = current->next;
	}
}
/**
 * free_dlistint - list is freed
 * @stack: node head
 * Return: nothing
 */
void free_dlistint(stack_t *stack)
{
	stack_t *current = NULL;

	current = stack;

	if (current != NULL)
	{
		free_dlistint(current->next);
		free(current);
	}
}
/**
 * _pint - prints value at stack top
 * @stack: Stack list
 * @line_number: line number
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !stack)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_number);
		cleanStack(stack);
		exit(EXIT_FAILURE);
	}
	else
		dprintf(STDOUT_FILENO, "%d\n", (*stack)->n);
}
