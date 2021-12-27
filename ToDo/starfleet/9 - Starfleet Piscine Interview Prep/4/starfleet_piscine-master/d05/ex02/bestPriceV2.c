#include <stdlib.h>
#include "header.h"

double	get_max(int pizzaSize, double *cache, double *prices)
{
	double best = prices[pizzaSize];
	if (cache[pizzaSize])
		return (cache[pizzaSize]);
	for (int i = 1; i <= pizzaSize / 2; i++)
	{
		if ((get_max(pizzaSize - i, cache, prices)
			+ get_max(i, cache, prices)) > best)
			best = cache[pizzaSize - i] + cache[i];
	}
	cache[pizzaSize] = best;
	return (best);
}

double	optimizedBestPrice(int pizzaSize, double *prices)
{
	double *cache = calloc(pizzaSize, sizeof(double));
	return (get_max(pizzaSize, cache, prices));
}
