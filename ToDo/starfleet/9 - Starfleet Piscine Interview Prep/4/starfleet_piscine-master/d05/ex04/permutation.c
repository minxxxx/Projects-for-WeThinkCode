#include <stdio.h>
#include "header.h"

void	swap(char *str, int i, int j)
{
	char tmp = str[i];
	str[i] = str[j];
	str[j] = tmp;
}

void	permute(char *str, int start)
{
	if (!str[start])
		printf("%s\n", str);
	for (int i = start; str[i]; i++)
	{
		swap(str, start, i);
		permute(str, start + 1);
		swap(str, start, i);
	}
}

void	printPermutations(char *str)
{
	permute(str, 0);
}
