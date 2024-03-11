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
		fclose(mover.file);
		free(mover.content);
		freestack(*head);
		exit(EXIT_FAILURE);
	}

	currentNode = *head;

	/* Check for division by zero */
	if (currentNode->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(mover.file);
		free(mover.content);
		freestack(*head);
		exit(EXIT_FAILURE);
	}

	/* Calculate the result and update the stack */
	result = currentNode->next->n / currentNode->n;
	currentNode->next->n = result;
	*head = currentNode->next;
	free(currentNode);
}

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
                fclose(mover.file);
                free(mover.content);
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
                fclose(mover.file);
                free(mover.content);
                freestack(*head);
                exit(EXIT_FAILURE);
        }

        currentNode = *head;

        /* Check for division by zero */
        if (currentNode->n == 0)
        {
                fprintf(stderr, "L%d: division by zero\n", counter);
                fclose(mover.file);
                free(mover.content);
                freestack(*head);
                exit(EXIT_FAILURE);
        }

        /* Calculate the remainder of the division */
        remainder = currentNode->next->n % currentNode->n;
        currentNode->next->n = remainder;
        *head = currentNode->next;
        free(currentNode);
}
