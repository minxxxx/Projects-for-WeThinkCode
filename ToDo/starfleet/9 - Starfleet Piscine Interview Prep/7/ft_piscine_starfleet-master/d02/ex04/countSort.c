#include "header.h"

void	countSort(unsigned char *utensils, int n)
{
	int	*counts;
	unsigned char *sorted;
	int total;
	int old_cnt;

	counts = (int*)malloc(sizeof(int) * UTENSIL_CNT + 1);
	sorted = (unsigned char*)malloc(sizeof(unsigned char) * n);
	memset(counts, 0, sizeof(int) * (UTENSIL_CNT + 1));

	for (int i = 0; i < n; i++)
		counts[utensils[i]]++;
	total = 0;
	for (int j = 1; j < UTENSIL_CNT + 1; j++)
	{
		old_cnt = counts[j];
		counts[j] = total;
		total += old_cnt;
	}

	for (int k = 0; k < n; k++)
	{
		sorted[counts[utensils[k]]] = utensils[k];
		counts[utensils[k]]++;
	}

	for (int l = 0; l < n; l++)
		utensils[l] = sorted[l];
	free(sorted);
	free(counts);
}
