#include "monty.h"

/**
 * divst - divides the second element by the top element of the stack.
 * @head: pointer to the head of the stack
 * @counter: line_number
 * Return: no return
 */
void divstack(stack_t **head, unsigned int counter)
{
	stack_t *currentNode;
	int stackLength, result;

	currentNode = *head;

	/* Calculate the length of the stack */
	for (stackLength = 0; currentNode != NULL; stackLength++)
		currentNode = currentNode->next;

	/* Check if the stack has less than 2 elements */
	if (stackLength < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
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

	/* Calculate the result and update the stack */
	result = currentNode->next->n / currentNode->n;
	currentNode->next->n = result;
	*head = currentNode->next;
	free(currentNode);
}
