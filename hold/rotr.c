#include "monty.h"

/**
 * rotr - rotates the stack to the bottom
 * @head: pointer to the head of the stack
 * @counter: line_number
 * Return: no return
 */
void rotr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *currentNode = *head, *lastNode;

	/* Check if the stack is empty or has only one */
	/* element, in which case rotation is not needed */
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}

	/* Traverse to the last node of the stack */
	while (currentNode->next)
	{
		currentNode = currentNode->next;
	}

	/* Set the last node as the new head after rotation */
	lastNode = currentNode;
	lastNode->next = *head;
	lastNode->prev->next = NULL;
	lastNode->prev = NULL;
	(*head)->prev = lastNode;
	(*head) = lastNode;
}
