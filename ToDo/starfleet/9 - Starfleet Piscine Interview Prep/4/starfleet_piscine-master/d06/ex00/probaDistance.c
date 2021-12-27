#include "header.h"

double probaDistance(int dist, int *locations, int n)
{
	double count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (locations[j] - locations[i] > dist)
				count++;
		}
	}
	return count / (n * (n-1) / 2);
}