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
		printf("Error\n");
		exit(0);
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

	h = *head;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		printf("Error\n");
	new->n = value;
	new->next = NULL;
	if (h)
	{
		while (h->next)
			h = h->next;
	}
	if (!h)
	{
		*head = new;
		new->prev = NULL;
	}
	else
	{
		h->next = new;
		new->prev = h;
	}
}
