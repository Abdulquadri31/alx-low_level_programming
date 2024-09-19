#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Deletes the node at a given index of a dlistint_t list.
 * @head: Double pointer to the head of the doubly linked list.
 * @index: Index of the node to be deleted. Index starts at 0.
 *
 * Return: 1 if succeeded, -1 if it failed.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *temp = *head;
	unsigned int i;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = temp->next;
		if (temp->next != NULL)
			temp->next->prev = NULL;
		free(temp);
		return (1);
	}

	for (i = 0; temp != NULL && i < index; i++)
		temp = temp->next;

	if (temp == NULL)
		return (-1);

	if (temp->next != NULL)
		temp->next->prev = temp->prev;
	if (temp->prev != NULL)
		temp->prev->next = temp->next;

	free(temp);
	return (1);
}
