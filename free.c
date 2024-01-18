#include "monty.h"
/**
 *
 *
 *
 */
void free_list(stack_t *head)
{
	stack_t *h;

	h = head;
	while (h)
	{
		h = head->next;
		free(head);
		head = h;
	}
}
