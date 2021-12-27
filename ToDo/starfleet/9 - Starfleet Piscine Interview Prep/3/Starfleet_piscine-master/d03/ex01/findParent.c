#include "header.h"
#include <stdio.h>
#include <strings.h>

void util(struct s_node *root, int i)
{
	int c;
	if (i == 0) //if root
		printf("%s\n", root->name);
	i++;
	c = 0;
	while(root->children[c])
	{
		int b = 0;
		while (b < i)
		{
			b++;
			printf("\t");
		}
		printf("%s\n", root->children[c]->name);
		util(root->children[c], i);
		c++;
	}
}

struct s_node *findParent(struct s_node *root, char *firstSpecies, char *secondSpecies)
{
	struct s_node *temp;
	struct s_node *res;
	int count;
	int i;

	if ((strcmp(root->name, firstSpecies) == 0) || (strcmp(root->name, secondSpecies) == 0))
		return root;
	count = 0;
	temp = NULL;
	i = 0;
	while (root->children[i])
	{
		res = findParent(root->children[i], firstSpecies, secondSpecies);
		if (res)
		{
			count++;
			temp = res;
		}
		i++;
	}
	if (count == 2)
		return root;
	return temp;
}
