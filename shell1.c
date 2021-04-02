#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>


int main()
{
	pid_t child;
	char *line;
	size_t l_len = 0;
	char *tok;
        char **array = NULL;
	int i, return_v, status;
	/*char *var_2[] = {"/bin/ls", "-l", NULL};*/

	while (1)
	{
		printf("$ ");
		return_v = getline(&line, &l_len, stdin);
		if (return_v == -1)
			return (-1);

		array = malloc(sizeof(char *) * 5);
		tok = strtok(line, " ");
		array[0] = tok;

		for (i = 1; tok != NULL; i++)
		{
			tok = strtok(NULL, " ");
			array[i] = tok;
			if (array[i] == NULL)
				break;
		}

		child = fork();
		if(child == 0)
		{
			if (execve(array[0], array, NULL))
			{
				perror("Error");
				exit(0);
			}
		}
		wait(&status);
	}
	return (0);
}
