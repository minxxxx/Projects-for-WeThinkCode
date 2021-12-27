#include "header.h"

void	swap(char *c1, char *c2)
{
	char tmp = *c1;

	*c1 = *c2;
	*c2 = tmp;
}

void	permute(char *str, int i)
{
	struct s_dict *d = dictInit(26);
	char buf[2];

	if (!str[i])
		printf("%s\n", str);
	else {
		for (int j = i; str[j]; j++) {
			strncpy(buf, str + j, 1);
			if (dictSearch(d, buf) > 0)
				continue ;
			swap(str + j, str + i);
			permute(str, i + 1);
			swap(str + j, str + i);
			dictInsert(d, buf, 1);
		}
	}
}

void	printUniquePermutations(char *str)
{
	permute(str, 0);
}
