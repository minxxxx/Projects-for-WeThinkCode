#include "header.h"

char	*NthLastCity(struct s_city *city, int n)
{
	struct s_city *first;
	struct s_city *second;

	first = city;
	second = city;
	for (int i = 0; i < n + 1; i++)
	{
		if (first == NULL)
			return ("Out of Range");
		first = first->next;
	}
	while (first)
	{
		first = first->next;
		second = second->next;
	}
	if (second == NULL)
		return ("Out of Range");
	return (second->name);
}
