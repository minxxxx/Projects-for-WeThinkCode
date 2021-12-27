#include "header.h"
#include <stdio.h>

void printReverse(struct s_node *lst)
{
	if(lst->next)
	{
		printReverse(lst->next);
		printf(" %s", lst->word);
	}
	else
		printf("%s", lst->word);
}