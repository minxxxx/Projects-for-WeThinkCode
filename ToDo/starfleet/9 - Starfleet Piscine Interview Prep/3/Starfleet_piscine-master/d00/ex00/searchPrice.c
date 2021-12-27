#include "header.h"
#include "stdio.h"
#include "string.h"

int searchPrice(struct s_art **arts, char *name)
{
	int i;

	i = 0;
	if (!arts || !name)
		return -1;
	while (arts[i])
	{
		if (strcmp(name, arts[i]->name) == 0)
			return arts[i]->price;
		i++;
	}
	return -1;
}
