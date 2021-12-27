#include <stdlib.h>

void	ft_free_tab(void **tab, int size)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (i < size)
		free(tab[i++]);
}
