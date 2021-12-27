#include "header.h"
#include <string.h> //memcpy, strlen, ...


int  searchPrice(struct s_art **arts, char *name)
{
	while(*arts)
	{
		if (!strcmp((*arts)->name, name))
			return (*arts)->price;
		arts++;
	}
	return -1;
}