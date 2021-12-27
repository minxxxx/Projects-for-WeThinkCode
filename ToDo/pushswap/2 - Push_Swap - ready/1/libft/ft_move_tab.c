#include <stdlib.h>

void	ft_move_tab(int **tab, int size, int move)
{
	int	*moved;
	int	i;

	if (size == 0)
		return ;
	if (!(moved = malloc(sizeof(int) * size)))
		return ;
	if (move > 0 && (i = 1) == 1)
		moved[0] = (*tab)[size - move];
	else
		i = 0;
	while (i < size)
	{
		if (i - move > size - 1)
			moved[i] = (*tab)[0];
		else
			moved[i] = (*tab)[i - move];
		++i;
	}
	free(*tab);
	*tab = moved;
}
