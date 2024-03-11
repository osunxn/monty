#include "monty.h"

/**
 * add - adds the top two elements of the stack.
 * @head: pointer to the head of the stack
 * @counter: line_number
 * Return: no return
 */
void add(stack_t **head, unsigned int counter)
{
	stack_t *currentNode;
	int stackLength = 0, sum;

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
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(mover.file);
		free(mover.content);
		freestack(*head);
		exit(EXIT_FAILURE);
	}

	/* Calculate the sum of the top two elements */
	currentNode = *head;
	sum = currentNode->n + currentNode->next->n;
	currentNode->next->n = sum;
	*head = currentNode->next;
	free(currentNode);
}


/**
  *nop- nothing
  *@head: stack head
  *@counter: line_number
  *Return: no return
 */
void nop(stack_t **head, unsigned int counter)
{
        (void) counter;
        (void) head;
}


/**
 * sub - subtraction of the top two elements of the stack.
 * @head: pointer to the head of the stack
 * @counter: line_number
 * Return: no return
 */
void sub(stack_t **head, unsigned int counter)
{
        stack_t *currentNode;
        int difference, stackLength;

        currentNode = *head;

        /* Calculate the length of the stack */
        for (stackLength = 0; currentNode != NULL; stackLength++)
                currentNode = currentNode->next;

        /* Check if the stack has less than 2 elements */
        if (stackLength < 2)
        {
                fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
                fclose(mover.file);
                free(mover.content);
                freestack(*head);
                exit(EXIT_FAILURE);
        }

        /* Calculate the difference of the top two elements */
        currentNode = *head;
        difference = currentNode->next->n - currentNode->n;
        currentNode->next->n = difference;
        *head = currentNode->next;
        free(currentNode);
}
