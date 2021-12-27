#include "header.h"

int	searchPrice(struct s_art **arts, char *name)
{
	int i;

	i = 0;
	while (arts[i])
	{	
		if (strcmp(name, arts[i]->name) == 0)
			return (arts[i]->price);
		i++;
	}
	return (-1);
}
