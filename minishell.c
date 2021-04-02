#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

int main(/*int argc, char *argv[], char *envp[]*/)
{
	pid_t child;
	char *tok, *line = NULL;
	char **command = NULL;
	size_t i, l_len = 0;
	int status, count_tok;
	char separator[] = {" "};

	while (1)
	{
		printf("#cisfun$ ");
		if (getline(&line, &l_len, stdin) == -1)
			break;

		for (i = 0; line[i] != '\0'; i++)
		{
			if (line[i] == separator[0])
				count_tok++;
		}
		command = malloc(sizeof(char *) * (count_tok + 1));
		tok = strtok(line, " \t\n\r");

		for (i = 0; i < 20 && tok != NULL; i++) /*change variable to compare i*/
		{
			command[i] = tok;
			tok = strtok(NULL, " \t\n\r");
		}
		command[i] = NULL;

		child = fork();
		if (child == 0)
		{
			if (execve(command[0], command, NULL)) /*envp*/
				{
					perror("execve");
					exit(EXIT_FAILURE);
				}
		}
		if (child > 0) /* Successful forks return positive process id's the parent*/
			wait(&status);
	}
	printf("\n");
	free(line);
	exit(status);
}
