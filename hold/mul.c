#include "monty.h"

/**
 * mul - multiplies the top two elements of the stack.
 * @head: pointer to the head of the stack
 * @counter: line number
 * Return: no return
*/
void mul(stack_t **head, unsigned int counter)
{
	stack_t *currentNode;
	int stackLength = 0, result;

	currentNode = *head;

	/* Calculate the length of the stack */
	while (currentNode)
	{
		currentNode = currentNode->next;
		stackLength++;
	}

	/* Check if the stack has at least two elements */
	if (stackLength < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		freestack(*head);
		exit(EXIT_FAILURE);
	}

	currentNode = *head;
	result = currentNode->next->n * currentNode->n;

	/* Update the second node's value and adjust the stack */
	currentNode->next->n = result;
	*head = currentNode->next;
	free(currentNode);
}
