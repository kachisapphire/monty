#include "monty.h"
/**
 *pall_node - function to print all the values on the stack
 *@head: top of the stack
 *@number: unused
 *Return: void
 */
void pall_node(stack_t **head, unsigned int count)
{
	stack_t *h;
	(void)count;

	h = *head;
	if (h == NULL)
		return;
	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
/**
 *push_node - function to add integer
 *@head: top of the stack
 *@count:iterates through thenloop
 *Return: void
 */
void push_node(stack_t **head, unsigned int count)
{
	int i, j = 0, f = 0;

	if (parse.args)
	{
		if (parse.args[0] == '-')
			j++;
		for (; parse.args[j] != '\0'; j++)
		{
			if (parse.args[j] > 57 || parse.args[j] < 48)
				f = 1;
		}
		if (f == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", count);
			fclose(parse.file);
			free(parse.index);
			free_list(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", count);
		fclose(parse.file);
		free(parse.index);
		free_list(*head);
		exit(EXIT_FAILURE);
	}
	i = atoi(parse.args);
	if (parse.flag == 0)
		add_func(head, i);
	else
		add_queue(head, i);
}
/**
 *pint_node - function to execute
 *@head: ...
 *@count: ..
 *Return: void
 */
void pint_node(stack_t **head, unsigned int count)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", count);
		fclose(parse.file);
		free(parse.index);
		free_list(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
/**
 *
 *
 *
 *
 */
void pop_node(stack_t **head, unsigned int count)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", count);
		fclose(parse.file);
		free(parse.index);
		free_list(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}
/**
 *swap_node - function to execute
 *@head: pointer ro top of stack
 *@count: ...
 *Return: void
 */
void swap_node(stack_t **head, unsigned int count)
{
	stack_t *h;
	int stack_len = 0, tmp;

	h = *head;
	while (h)
	{
		h = h->next;
		stack_len++;
	}
	if (stack_len < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", count);
		fclose(parse.file);
		free(parse.index);
		free_list(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	tmp = h->n;
	h->n = h->next->n;
	h->next->n = tmp;
}
