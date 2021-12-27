#include "header.h"

double	recurse(int n, double *prices, double *cache)
{
	double best = prices[n];

	if (cache[n] >= 0)
		return (cache[n]);
	for (int i = 1; i <= n / 2; i++)
		if (recurse(i, prices, cache) + recurse(n - i, prices, cache) > best)
			best = cache[i] + cache[n - i];
	cache[n] = best;
	return (best);
}

double	optimizedBestPrice(int pizzaSize, double *prices)
{
	double *cache;

	cache = (double*)malloc(sizeof(double) * (pizzaSize + 1));
	memset(cache, -1, sizeof(double) * (pizzaSize + 1));
	cache[0] = prices[0];
	cache[1] = prices[1];
	return (recurse(pizzaSize, prices, cache));
}
