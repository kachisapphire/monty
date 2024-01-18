#include "monty.h"
/**
 *add_node - adds the top two elements
 *@head: ...
 *@count: ..
 *Return: void
 */
void add_node(stack_t **head, unsigned int count)
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
		fprintf(stderr, "L%u: can't add, stack too short\n", count);
		fclose(parse.file);
		free(parse.index);
		free_list(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	tmp = h->n + h->next->n;
	h->next->n = tmp;
	*head = h->next;
	free(h);
}
/**
 *nop_node: function does nothing
 *@head: ..
 *@count: ..
 *Return: void
 */
void nop_node(stack_t **head, unsigned int count)
{
	(void) count;
	(void) head;
}
