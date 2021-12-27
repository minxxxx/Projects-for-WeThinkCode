#include "header.h"

void	swap_players(struct s_player **players, int i, int j)
{
	struct s_player *tmp;

	tmp = players[i];
	players[i] = players[j];
	players[j] = tmp;
}

int		partition(struct s_player **players, int low, int hi)
{
	int wall;

	wall = low;
	for (int i = low; i < hi; i++)
	{
		if (players[i]->score <= players[hi]->score)
		{
			swap_players(players, i, wall);
			wall++;
		}
	}
	swap_players(players, hi, wall);
	return (wall);
}

void	recurse(struct s_player **players, int low, int hi)
{
	int	pi;

	while (low < hi)
	{
		pi = partition(players, low, hi);
		if (pi - low < hi - pi)
		{	
			recurse(players, low, pi - 1);
			low = pi + 1;
		}
		else
		{
			recurse(players, pi + 1, hi);
			hi = pi - 1;
		}
	}
}

void	quickSort(struct s_player **players)
{
	int len;

	len = 0;
	while (players[len])
		len++;
	recurse(players, 0, len - 1);
}
