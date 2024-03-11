#include "monty.h"

/**
 * swap - swaps the top two elements of the stack.
 * @head: pointer to the head of the stack
 * @counter: line_number
 * Return: no return
 */
void swap(stack_t **head, unsigned int counter)
{
	stack_t *currentNode;
	int stackLength = 0, tempValue;

	currentNode = *head;

	/* Calculate the length of the stack */
	while (currentNode)
	{
		currentNode = currentNode->next;
		stackLength++;
	}

	/* Check if the stack has less than 2 elements */
	if (stackLength < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		freestack(*head);
		exit(EXIT_FAILURE);
	}

	/* Swap the values of the top two elements */
	currentNode = *head;
	tempValue = currentNode->n;
	currentNode->n = currentNode->next->n;
	currentNode->next->n = tempValue;
}
