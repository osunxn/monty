#include "monty.h"

/**
 * pstr - prints the string starting at the top of the stack,
 * followed by a new line
 * @head: pointer to the head of the stack
 * @counter: line_number
 * Return: no return
 */
void pstr(stack_t **head, unsigned int counter)
{
	stack_t *currentNode;
	(void)counter;

	currentNode = *head;

	/* Traverse the stack and print characters until a non-printable */
/* character or the end of the stack is encountered */
	while (currentNode)
	{
		if (currentNode->n > 127 || currentNode->n <= 0)
		{
			break;
		}
		printf("%c", currentNode->n);
		currentNode = currentNode->next;
	}
	printf("\n");
}
