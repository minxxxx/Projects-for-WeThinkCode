#include "header.h"

int modified_binary_search(int *rocks, int l, int r, int val)
{
	int m;

	while (l <= r)
	{
		m = (l + r) / 2;
		if (rocks[m] == val && (m == 0 || rocks[m - 1] != val))
			return (m);
		else if (val <= rocks[m])
			r = m - 1;
		else
			l = m + 1;
	}
	return (-1);
}

int	find_pivot(int *rocks, int l, int r)
{
	int ret;
	int m;
	
	if (l >= r)
		return (-1);
	if (rocks[l] > rocks[l + 1])
		return (l);
	m = (l + r) / 2;
	if (rocks[m] > rocks[m + 1])
		return (m);
	if (rocks[l] >= rocks[m])
	{
		ret = find_pivot(rocks, l, m);
		if (ret > 0)
			return (ret);
	}
	if (rocks[m + 1] >= rocks[r])
	{
		ret = find_pivot(rocks, m + 1, r);
			if (ret > 0)
				return (ret);
	}
	return (-1);
}

int	searchShifted(int *rocks, int length, int value)
{
	int pivot;
	int	match1;
	int match2;

	pivot = find_pivot(rocks, 0, length - 1);
	pivot = (pivot == -1 ? length : pivot);
	match1 = modified_binary_search(rocks, 0, pivot, value);
	match2 = modified_binary_search(rocks, pivot + 1, length - 1, value);
	return (match1 == -1 ? match2 : match1);
}
