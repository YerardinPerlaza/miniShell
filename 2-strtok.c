#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(__attribute__((unused))int ac,__attribute__((unused))char **av)
{
	char *line;
        size_t l_len = 0;
	char *tok;
	char **array = NULL;
	int i, count_tok = 0;
	char separator[] = {" "};

	getline(&line, &l_len, stdin);

	for (i = 0; line[i] != '\0'; i++)
	{
		if (line[i] == separator[0] && line[i+1] != '\0')
			count_tok++;
	}

	array = malloc(sizeof(char *) * (count_tok + 1));

	tok = strtok(line, " ");
	array[0] = tok;
/*	printf("%s\n", array[0]);*/

	for (i = 1; tok != NULL; i++)
	{
		printf("%s", tok);
		tok = strtok(NULL, " ");
		array[i] = tok;

		if (array[i] == NULL)
			break;
		printf("\n");
	}
	return (0);
}
