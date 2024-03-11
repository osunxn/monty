#include "monty.h"
/**
 * push - add node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void push(stack_t **head, unsigned int counter)
{
	int n, j = 0, flag = 0;

	if (mover.arg)
	{
		if (mover.arg[0] == '-')
			j++;
		for (; mover.arg[j] != '\0'; j++)
		{
			if (mover.arg[j] > 57 || mover.arg[j] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(mover.file);
			free(mover.content);
			freestack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(mover.file);
		free(mover.content);
		freestack(*head);
		exit(EXIT_FAILURE); }
	n = atoi(mover.arg);
	if (mover.lifo == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}
