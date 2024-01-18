#include "monty.h"
/**
 *add_func - function to add node 
 *@head: pointer ro the top of the stack
 *@value: newvalue
 *Return: void
 */
void add_func(stack_t **head, int value)
{
	stack_t *h, *new;

	h = *head;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (h)
		h->prev = new;
	new->n = value;
	new->next = *head;
	new->prev = NULL;
	*head = new;
}
/**
 *add_queue - function to execute
 *@head: pointer ro the top of stack
 *@value: newvalue
 *Return: void
 */
void add_queue(stack_t **head, int value)
{
	stack_t *h, *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit (EXIT_FAILURE);
	}
	new->n = value;
	new->next = NULL;
	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
	}
	else
	{
		h = *head;
		while (h->next != NULL)
			h = h->next;
		h->next = new;
		new->prev = h;
	}
}
