#include "monty.h"

/**
 * f_push - add node to the stack
 * @stackHead: pointer to the head of the stack
 * @lineNumber: line number
 * Return: no return
 */
void push(stack_t **stackHead, unsigned int lineNumber)
{
        int integerValue, index = 0, errorFlag = 0;

        if (mover.arg)
        {
                if (mover.arg[0] == '-')
                        index++;
                for (; mover.arg[index] != '\0'; index++)
                {
                        if (mover.arg[index] > 57 || mover.arg[index] < 48)
                                errorFlag = 1;
                }
                if (errorFlag == 1)
                {
                        fprintf(stderr, "L%d: usage: push integer\n", lineNumber);
                        fclose(mover.file);
                        free(mover.content);
                        freestack(*stackHead);
                        exit(EXIT_FAILURE);
                }
        }
        else
        {
                fprintf(stderr, "L%d: usage: push integer\n", lineNumber);
                fclose(mover.file);
                free(mover.content);
                freestack(*stackHead);
                exit(EXIT_FAILURE);
        }

        integerValue = atoi(mover.arg);
        if (mover.lifo == 0)
                addnode(stackHead, integerValue);
        else
                addqueue(stackHead, integerValue);
}
