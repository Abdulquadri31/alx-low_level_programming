#include "lists.h"
#include <stdlib.h>

/**
 * free_listint_safe - frees a listint_t list safely (handles loops)
 * @h: double pointer to the head of the list
 *
 * Return: the size of the list that was free'd
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *current, *next;
	size_t count = 0;

	if (h == NULL || *h == NULL)
		return (0);

	current = *h;

	while (current)
	{
		count++;
		next = current->next;

		free(current);

		if (current <= next)
		break;

		current = next;
	}

	*h = NULL;
	return (count);
}

