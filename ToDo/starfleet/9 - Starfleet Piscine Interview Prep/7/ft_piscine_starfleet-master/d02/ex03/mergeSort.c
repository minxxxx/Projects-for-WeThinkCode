#include "header.h"

struct s_player **sub_arr(struct s_player **players, int from, int size)
{
	struct s_player **sub_arr;
	int 			i;

	sub_arr = (struct s_player**)malloc(sizeof(struct s_player*) * size);
	i = 0;
	while (i < size)
	{
		sub_arr[i] = players[from + i];
		i++;
	}
	return (sub_arr);
}

void	merge(struct s_player **players, int l, int m, int r)
{
	int l_size, r_size;
	int i, j, k;
	struct s_player **l_arr, **r_arr;

	l_size = m - l + 1;
	r_size = r - m;
	l_arr = sub_arr(players, l, l_size);
	r_arr = sub_arr(players, m + 1, r_size);

	i = 0;
	j = 0;
	k = l;
	while (i < l_size && j < r_size)
	{
		if (l_arr[i]->score <= r_arr[j]->score)
		{
			players[k] = l_arr[i];
			i++;
		}
		else
		{
			players[k] = r_arr[j];
			j++;
		}
		k++;
	}
	while (i < l_size)
	{
		players[k] = l_arr[i];
		i++;
		k++;
	}
	while (j < r_size)
	{
		players[k] = r_arr[j];
		j++;
		k++;
	}

	free(l_arr);
	free(r_arr);
}

void	recurse(struct s_player **players, int l, int r)
{
	int m;

	if (l >= r)
		return;
	m = (l + r)	 / 2;
	recurse(players, l, m);
	recurse(players, m + 1, r);
	merge(players, l, m, r);
}
	
struct s_player **mergeSort(struct s_player **players)
{
	int	len;

	len = 0;
	while (players[len])
		len++;
	recurse(players, 0, len - 1);
	return (players);
}
