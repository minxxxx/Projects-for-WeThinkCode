#include "header.h"

void printReverse(struct s_node *lst)
{
	static int i = 0;
	if (lst == NULL)
		return;
	i++;
	printReverse(lst->next);
	i--;
	printf("%s", lst->word);
	if (i)
		printf(" ");
	else
		printf("\n");
}
