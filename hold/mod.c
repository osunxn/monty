#include "monty.h"

/**
 * mod - computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @head: pointer to the head of the stack
 * @counter: line_number
 * Return: no return
 */
void mod(stack_t **head, unsigned int counter)
{
	stack_t *currentNode;
	int remainder, stackLength;

	currentNode = *head;

	/* Calculate the length of the stack */
	for (stackLength = 0; currentNode != NULL; stackLength++)
		currentNode = currentNode->next;

	/* Check if the stack has less than 2 elements */
	if (stackLength < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		freestack(*head);
		exit(EXIT_FAILURE);
	}

	currentNode = *head;

	/* Check for division by zero */
	if (currentNode->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		freestack(*head);
		exit(EXIT_FAILURE);
	}

	/* Calculate the remainder of the division */
	remainder = currentNode->next->n % currentNode->n;
	currentNode->next->n = remainder;
	*head = currentNode->next;
	free(currentNode);
}
