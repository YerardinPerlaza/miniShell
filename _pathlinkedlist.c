#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

struct node {
	int data:
	struct node *link;
};

int main()
{
	char *path;
	char *tok;
	int i;

	path = getenv("PATH");
	tok = strtok(path, "/");
	struct node *head = malloc(sizeof(struct node));
	head->data = path;
	head->link = NULL;
	for (i = 1; tok != NULL; i++)
	{
		struct node *current = malloc(sizeof(struct node));
		current->data = tok;
		head->link = current;
		tok = strtok(NULL, "/");
	}
	tok = NULL;
	return (tok);
}
