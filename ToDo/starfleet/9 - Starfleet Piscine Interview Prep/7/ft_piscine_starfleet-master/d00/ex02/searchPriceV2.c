# include "header.h"

int searchPrice(struct s_art **arts, int n, char *name)
{
	int from;
	int to;
	int cmp_val;
	int m;

	from = 0;
	to = n - 1;
	while (from <= to)
	{
		m = (from + to) / 2;
		cmp_val = strcmp(name, arts[m]->name);
		if (cmp_val == 0)
			return (arts[m]->price);
		else if (cmp_val < 0)
			to = m - 1;
		else
			from = m + 1;

	}
	return (-1);
}
