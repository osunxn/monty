#include "monty.h"

/**
 * pint - prints the top element of the stack
 * @head: pointer to the head of the stack
 * @counter: line number
 * Return: no return
 */
void pint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(mover.file);
		free(mover.content);
		freestack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}


/**
 * pop - removes the top element of the stack
 * @head: pointer to the head of the stack
 * @counter: line_number
 * Return: no return
 */
void pop(stack_t **head, unsigned int counter)
{
        stack_t *topNode;

        /* Check if the stack is empty */
        if (*head == NULL)
        {
                fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
                fclose(mover.file);
                free(mover.content);
                freestack(*head);
                exit(EXIT_FAILURE);
        }

        /* Save the top node */
        topNode = *head;

        /* Update the head of the stack to the next node */
        *head = topNode->next;

        /* Free the memory of the top node */
        free(topNode);

        /* Debugging output */
        printf("Popped value: %d\n", topNode->n);
}


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
                fclose(mover.file);
                free(mover.content);
                freestack(*head);
                exit(EXIT_FAILURE);
        }

        /* Swap the values of the top two elements */
        currentNode = *head;
        tempValue = currentNode->n;
        currentNode->n = currentNode->next->n;
        currentNode->next->n = tempValue;
}
