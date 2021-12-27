#include "header.h"
#include <string.h> //memcpy, strlen, ...

int searchPrice(struct s_art **arts, int n, char *name)
{
	if (n > 0)
	{
		int mid = n / 2;
		if(strcmp(name, arts[mid]->name) == 0)
			return arts[mid]->price;
		else if(strcmp(name, arts[mid]->name) < 0)
			return searchPrice(arts, mid, name);
		else
			return searchPrice(arts + mid, mid, name);
	}
	return -1;
}