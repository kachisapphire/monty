#include "monty.h"
parse_t parse = {NULL, NULL, NULL, 0};
/**
 *main - functionto execute
 *@argc: argument count
 *@argv: argument vector
 *Return: 0 on syccess
 */
int main(int argc,char *argv[])
{
	char *index;
	FILE *file;
	unsigned int count = 0;
	size_t size = 0;
	ssize_t line = 1;
	stack_t *top = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	parse.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (line > 0)
	{
		index = NULL;
		line = getline(&index, &size, file);
		parse.index = index;
		count++;
		if (line > 0)
			find(index, &top, count, file);
		free(index);
	}
	free_list(top);
	fclose(file);
	return (0);
}
