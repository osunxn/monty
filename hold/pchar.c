#include "monty.h"

/**
 * pchar - prints the char at the top of the stack,
 * followed by a new line
 * @head: pointer to the head of the stack
 * @counter: line_number
 * Return: no return
 */
void pchar(stack_t **head, unsigned int counter)
{
	stack_t *currentNode;

	currentNode = *head;

	/* Check if the stack is empty */
	if (!currentNode)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		freestack(*head);
		exit(EXIT_FAILURE);
	}

	/* Check if the value is out of range */
	if (currentNode->n > 127 || currentNode->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
		fclose(bus.file);
		free(bus.content);
		freestack(*head);
		exit(EXIT_FAILURE);
	}

	/* Print the character at the top of the stack */
	printf("%c\n", currentNode->n);
}
