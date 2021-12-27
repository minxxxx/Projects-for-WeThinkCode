#include <string.h>
#include <math.h>
#include <stdio.h>

#define d 256

int howManyJesus(char *bible, char *jesus)
{
	int M = strlen(jesus);
	int N = strlen(bible);
	int count = 0;

	int i, j;
	int p = 0;
	int t = 0;
	int h = 1;
	int q = 31;

	i = 0;
	while (i < (M - 1))
	{
		h = (h * d) % q;
		i++;
	}
	i = 0;
	while (i < M)
	{
		p = (d * p + jesus[i]) % q;
		t = (d * t + bible[i]) % q;
		i++;
	}
	i = 0;
	while (i <= N - M)
	{
		if (p == t)
		{
			j = 0;
			while (j < M)
			{
				if (bible[i + j] != jesus[j])
					break;
				j++;
			}
			if (j == M)
			{
				count++;
			}
		}
		if (i < (N - M))
		{
			t = (d * (t - bible[i] * h) + bible[i + M]) % q;
			if (t < 0)
				t = (t + q);
		}
		i++;
	}
	return count;
}
