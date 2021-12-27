#include <stdlib.h>
#include "header.h"

void find_nth(struct s_city *city, int goal, char **str)
{
	static int n;
	if(!city)
		n = 0;
	else
	{
		find_nth(city->next, goal, str);
		if (n == goal)
			*str = city->name;
		n++;
	}
}

char *NthLastCity(struct s_city *city, int n)
{
	char *name = NULL;

	find_nth(city, n, &name);
	return (name);
}
