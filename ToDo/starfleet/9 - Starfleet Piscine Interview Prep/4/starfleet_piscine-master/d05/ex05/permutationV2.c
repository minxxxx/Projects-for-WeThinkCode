#include <stdio.h>
#include <string.h>
#include "header.h"

void	swap(char *str, int i, int j)
{
	char tmp = str[i];
	str[i] = str[j];
	str[j] = tmp;
}

void	permute(char *str, int start, struct s_dict *dict)
{
	if (!str[start] && dictSearch(dict, str) == -1)
	{
		dictInsert(dict, str, 1);
		printf("%s\n", str);
	}
	for (int i = start; str[i]; i++)
	{
		swap(str, start, i);
		permute(str, start + 1, dict);
		swap(str, start, i);
	}
}

void	printUniquePermutations(char *str)
{
	struct s_dict *dict = dictInit(strlen(str));
	permute(str, 0, dict);
}
