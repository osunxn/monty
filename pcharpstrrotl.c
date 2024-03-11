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
		fclose(mover.file);
		free(mover.content);
		freestack(*head);
		exit(EXIT_FAILURE);
	}

	/* Check if the value is out of range */
	if (currentNode->n > 127 || currentNode->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
		fclose(mover.file);
		free(mover.content);
		freestack(*head);
		exit(EXIT_FAILURE);
	}

	/* Print the character at the top of the stack */
	printf("%c\n", currentNode->n);
}


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


/**
 * rotl - rotates the stack to the top
 * @head: pointer to the head of the stack
 * @counter: line_number
 * Return: no return
 */
void rotl(stack_t **head, __attribute__((unused)) unsigned int counter)
{
        stack_t *currentHead = *head, *newHead;

        /* Check if the stack is empty or has only one element, in which case rotation is not needed */
        if (*head == NULL || (*head)->next == NULL)
        {
                return;
        }

        /* Set the new head and update pointers to perform the rotation */
        newHead = (*head)->next;
        newHead->prev = NULL;

        while (currentHead->next != NULL)
        {
                currentHead = currentHead->next;
        }

        currentHead->next = *head;
        (*head)->next = NULL;
        (*head)->prev = currentHead;

        (*head) = newHead;
}
