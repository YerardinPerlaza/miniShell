#include <stdio.h>
#include <stdlib.h>
/**
 * main - program that prints "$ ", wait for the user to enter a command,
 * prints it on the next line.
 * return: 0
 */
int main ()
{
        char *line;
        size_t l_len = 0;
        int return_v;

	printf("$ ");
        return_v = getline(&line, &l_len, stdin);
        if (return_v == -1)
        {
                return (-1);
        }
        printf("%s", line);
        return (return_v);
}
