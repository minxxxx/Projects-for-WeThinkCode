#include "header.h"

int		DaCsearch(int *ages, int l, int r)
{
	int m;

	if (l == r)
		return (ages[l]);
	m = (l + r) / 2;
	return (fmin(DaCsearch(ages, l, m), DaCsearch(ages, m + 1, r)));
}

void	printYoungest(int *ages, int length)
{
	printf("Youngest : %d\n", DaCsearch(ages, 0, length - 1));
}
