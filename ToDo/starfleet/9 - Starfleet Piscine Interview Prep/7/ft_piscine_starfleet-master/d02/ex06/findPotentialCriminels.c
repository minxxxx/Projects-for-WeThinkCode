#include "header.h"
#include <stdio.h>


int	getDescription(struct s_info *info)
{
	int description;

	description = info->gender    * 1000000 +
				  info->height    * 100000 +
				  info->hairColor * 10000 +
				  info->eyeColor  * 1000 +
				  info->glasses   * 100 +
				  info->tattoo    * 10 + 
				  info->piercing  * 1;
	return (description);
}	

void	countSort(struct s_criminal **criminals, int n, int exp)
{
	struct s_criminal	**sorted;
	int					*counts;
	int					digit;
	int					total;
	int					old_cnt;

	counts = (int*)calloc(10, sizeof(int));
	sorted = (struct s_criminal**)calloc(n, sizeof(struct s_criminal*));

	for (int i = 0; i < n; i++)
	{
		digit = (criminals[i]->description / exp) % 10;
		counts[digit]++;
	}

	total = 0;
	for (int j = 0; j < 10; j++)
	{
		old_cnt = counts[j];
		counts[j] = total;
		total += old_cnt;
	}

	for (int k = 0; k < n; k++)
	{
		digit = (criminals[k]->description / exp) % 10;
		sorted[counts[digit]] = criminals[k];
		counts[digit]++;
	}

	for (int l = 0; l < n; l++)
		criminals[l] = sorted[l];

	free(counts);
	free(sorted);
}

void	sortCriminals(struct s_criminal **criminals)
{
	int len;
	int exp;

	len = 0;
	while (criminals[len])
		len++;

	exp = 1;
	for (int i = 0; i < 7; i++)
	{
		countSort(criminals, len, exp);
		exp *= 10;
	}
}

int	leftboundBinarySearch(struct s_criminal **criminals, int d, int len)
{
	int l;
	int r;
	int m;

	l = 0;
	r = len - 1;
	while (l <= r)
	{
		m = (l + r) / 2;
		if (criminals[m]->description == d && (m == 0 || criminals[m - 1]->description != d))
			return (m);
		else if (d <= criminals[m]->description)
			r = m - 1;
		else
			l = m + 1;
	}
	return (-1);
}

int	rightboundBinarySearch(struct s_criminal **criminals, int d, int len)
{
	int l;
	int r;
	int m;

	l = 0;
	r = len - 1;
	while (l <= r)
	{
		m = (l + r) / 2;
		if (criminals[m]->description == d && (m == len - 1 || criminals[m + 1]->description != d))
			return (m);
		else if (d < criminals[m]->description)
			r = m - 1;
		else
			l = m + 1;
	}
	return (-1);
}

struct s_criminal **slice(struct s_criminal **criminals, int left, int right)
{
	int					len;
	struct s_criminal	**potentials;

	len = (left == -1 ? 0 : right - left + 1);
	potentials = (struct s_criminal**)calloc(len + 1, sizeof(struct s_criminal*));
	for (int i = 0; i < len; i++)
		potentials[i] = criminals[left + i];
	return (potentials);
}

struct s_criminal **findPotentialCriminals(struct s_criminal **criminals, struct s_info *info)
{
	int len;
	int description;
	int leftbound;
	int rightbound;

	len = 0;
	while (criminals[len])
		len++;
	description = getDescription(info);
	leftbound = leftboundBinarySearch(criminals, description, len);
	rightbound = rightboundBinarySearch(criminals, description, len);
	return (slice(criminals, leftbound, rightbound));
}
