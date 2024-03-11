#include "monty.h"

/**
 * rotl - rotates the stack to the top
 * @head: pointer to the head of the stack
 * @counter: line_number
 * Return: no return
 */
void rotl(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *currentHead = *head, *newHead;

	/* Check if the stack is empty or has only one element, in which case rotation is not needed */
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}

	/* Set the new head and update pointers to perform the rotation */
	newHead = (*head)->next;
	newHead->prev = NULL;

	while (currentHead->next != NULL)
	{
		currentHead = currentHead->next;
	}

	currentHead->next = *head;
	(*head)->next = NULL;
	(*head)->prev = currentHead;

	(*head) = newHead;
}
