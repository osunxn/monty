#include "monty.h"

/**
 * pall - prints the stack
 * @head: pointer to the head of the stack
 * @counter: unused parameter
 * Return: no return
 */
void pall(stack_t **head, unsigned int counter)
{
	stack_t *currentNode;
	(void)counter;

	currentNode = *head;
	
	if (currentNode == NULL)
		return;

	/* Print each element in the stack */
	while (currentNode)
	{
		printf("%d\n", currentNode->n);
		currentNode = currentNode->next;
	}
}
