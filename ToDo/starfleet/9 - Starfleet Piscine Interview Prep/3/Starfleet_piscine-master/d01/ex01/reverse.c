#include "header.h"
#include <stdio.h>

void util_rev(struct s_node *lst)
{
	if (lst->next)
	{
		util_rev(lst->next);
		printf("%c", ' ');
	}
	printf("%s", lst->word);
}

void printReverse(struct s_node *lst)
{
	util_rev(lst);
	printf("\n");
}
