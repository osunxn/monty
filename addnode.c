#include "monty.h"

/**
 * addnode - add node to the head stack
 * @head: head of the stack
 * @n: new_value
 * Return: no return
 */
void addnode(stack_t **head, int n)
{
    stack_t *newNode, *currentHead;

    currentHead = *head;  /* Save the current head of the stack */

    newNode = malloc(sizeof(stack_t));
    if (newNode == NULL)
    {
        printf("Error\n");
        exit(0);
    }

    if (currentHead)
        currentHead->prev = newNode;  /* If the stack is not empty update */
									/* the previous pointer of the old head */

    newNode->n = n;
    newNode->next = *head;  /* Set the next pointer of the */
							/* new node to the old head */
    newNode->prev = NULL;   /* The new node is the new head */
							/* so its previous pointer is NULL */

    *head = newNode;  /* Update the head of the stack to be the new node */
}
