#include "header.h"

void	insertionSort(struct s_player **players)
{
	int				i;
	int				j;
	struct s_player	*current;

	i = 1;
	while (players[i])
	{
		current = players[i];
		j = i;
		while (j > 0 && players[j - 1]->score > current->score)
		{
			players[j] = players[j - 1];
			j--;
		}
		players[j] = current;
		i++;
	}
}
