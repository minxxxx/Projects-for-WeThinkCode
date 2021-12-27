/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 11:32:23 by geargenc          #+#    #+#             */
/*   Updated: 2017/12/17 22:58:20 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_puissance4.h"

int			ft_gettabsize(void)
{
	int		i;

	i = 0;
	while (g_playertab[i].level >= 0)
		i++;
	return (i);
}

int			ft_getplayer(void)
{
	char	*line;
	int		ans;
	int		tabsize;

	if ((tabsize = ft_gettabsize()) < 1)
		return (-1);
	ans = -1;
	while (ans < 0 || ans >= tabsize)
	{
		ft_putstr("Select IA level\n0 is human player\n1 to ");
		ft_putnbr(tabsize - 1);
		ft_putstr(" to select an IA\n");
		if (get_next_line(0, &line) < 0)
			return (-1);
		ans = ft_atoi(line);
		free(line);
	}
	return (ans);
}

void		ft_addtab(int *tab, int value)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	tab[i] = value;
	tab[i + 1] = 0;
}

int			ft_tabsize(int *tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int			ft_playcol(t_grid *grid, int col)
{
	int		j;

	j = -1;
	while (j + 1 < grid->height && grid->grid[j + 1][col] == VOIDCASE)
		j++;
	return (j);
}
