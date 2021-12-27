#include <stdio.h>

double probaDistance(int dist, int *locations, int n)
{
	int i;
	double count = 0;
	double h_prob = 0;

	i = 0;

	while (i < n)
	{
		int j = 0;
		int hold = locations[i];
		count = 0;
		while (j < n)
		{
			if ((locations[j] - hold) > dist)
				count++;
			j++;
		}
		if (count > 0)
			h_prob += (count / (n - 1));
		i++;
	}
	h_prob = h_prob / n;
	return((h_prob * 2));
}
