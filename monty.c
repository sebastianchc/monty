#include "monty.h"

char *buffer = NULL;

int main(int argc, char **argv)
{
	unsigned int line = 1;
	FILE *file;
	char *e1 = "USAGE: monty file", *e2 = "Error: Can't open file";
	size_t size = 1024;

	if (argc != 2)
	{
		dprintf(2, "%s\n", e1), exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		dprintf(2, "%s %s\n", e2, argv[1]), exit(EXIT_FAILURE);
	}
	while (getline(&buffer, &size, file) != -1)
	{
		get_code(line);
		line++;
	}
	return (0);
}

void get_code(unsigned int line)
{
	instruction_t inst[] = {
		{"push", _push},
		{"pall", _pall},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *token = NULL;
	stack_t *new = malloc(sizeof(stack_t));

	token = strtok(buffer, " \n");
	while (inst[i].opcode && buffer)
	{
		while (token)
		{
			if (!strcmp(token, inst[i].opcode))
			{
				inst[i].f(&new, line);
			}
			token = strtok(NULL, " \n");
		}
		i++;
	}
}
