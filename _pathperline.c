#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
	char *path;
	char *tok;
	int i;

	path = getenv("PATH");
	tok = strtok(path, "/");
	for (i = 0; tok != NULL; i++)
	{
		printf("/%s\n", tok);
		tok = strtok(NULL, "/");
	}
	tok = NULL;
	return (0);
}
