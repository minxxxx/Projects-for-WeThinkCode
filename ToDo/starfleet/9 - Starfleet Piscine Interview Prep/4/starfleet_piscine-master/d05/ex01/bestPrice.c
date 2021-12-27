#include "header.h"

void	printRec(int pizzaSize, double sum, double *prices, double *best)
{
	if (pizzaSize == 0)
	{
		if (sum > *best)
			*best = sum;
		return ;
	}
	for (int i = 1; i <= pizzaSize; i++)
	{
		printRec(pizzaSize - i, sum + prices[i], prices, best);
	}
}

double	bestPrice(int pizzaSize, double *prices)
{
	double best = 0;
	printRec(pizzaSize, 0, prices, &best);
	return (best);
}
