#include "monty.h"

mover_t mover = {NULL, NULL, NULL, 0};

/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	char *data;
	FILE *file;
	size_t size = 0;
	ssize_t readline = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	mover.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (readline > 0)
	{
		data = NULL;
		readline = getline(&data, &size, file);
		mover.content = data;
		counter++;
		if (readline > 0)
		{
			execute(data, &stack, counter, file);
		}
		free(data);
	}
	freestack(stack);
	fclose(file);
return (0);
}
