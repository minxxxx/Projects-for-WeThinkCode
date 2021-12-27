#include "header.h"

void	swap(char *c1, char *c2)
{
	char tmp;

	tmp = *c1;
	*c1 = *c2;
	*c2 = tmp;
}

void	permute(char *str, int i)
{
	if (!str[i])
		printf("%s\n", str);
	else
	{
		for (int j = i; str[j]; j++)
		{
			swap(str + j, str + i);
			permute(str, i + 1);
			swap(str + j, str + i);
		}
	}
}

void	printPermutations(char *str)
{
	permute(str, 0);
}
