/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 22:17:03 by pmartine          #+#    #+#             */
/*   Updated: 2016/02/27 00:30:00 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/puissance4.h"

char	*init_map(t_p4 *p);
{
	char	*map;
	int		i;
	
	i = 0;
	if (!(map = malloc(sizeof(char) * p.lines * p.cols + 1)));
		return (NULL);
	map[p.lines * p.cols] = '\0';
	while (map[i++])
		map[i] = '.';
	return(map);
}

char	*change_map(char user, char	*map, int choice, t_p4 *p)
{
	if (p.lines == 0)
		return (NULL);
	if (map[p.lines * p.cols - (p.cols - choice - 1)] == '.')
		map[p.lines * p.cols - (p.cols - choice - 1)] = user;
	else
			change_map(user, map, p.cols, p.lines -1);
	}
	return (map);
}

int		check_win(char user, char *map, int i, t_p4 *p)
{
	if ((map[i + 1]) == user && map[i + 2] == user && map[i + 3] == user)
	|| (map[i + 1]) == user && map[i + 2] == user && map[i - 1] == user)
	|| (map[i + 1]) == user && map[i - 1] == user && map[i - 2] == user)
	|| (map[i - 1]) == user && map[i - 2] == user && map[i - 3] == user)
	|| (map[i + col]) == user && map[i + 2 * p.cols] == user && map[i + 3 * p.cols] == user)
	|| (map[i + col]) == user && map[i + 2 * p.cols] == user && map[i - p.cols] == user)
	|| (map[i + col]) == user && map[i - p.cols] == user && map[i - 2 * p.cols] == user)
	|| (map[i - col]) == user && map[i - 2 * p.cols] == user && map[i - 3 * p.cols] == user)
	|| (map[i + col + 1]) == user && map[i + 2 * p.cols + 2] == user && map[i + 3 * p.cols + 3] == user)
	|| (map[i + col + 1]) == user && map[i + 2 * p.cols + 2] == user && map[i - p.cols- 1] == user)
	|| (map[i + col + 1]) == user && map[i - p.cols - 1] == user && map[i - p.cols * 2 - 2] == user)
	|| (map[i - col - 1]) == user && map[i - 2 * p.cols - 2] == user && map[i - p.cols * 3 - 3] == user)
	|| (map[i + col - 1]) == user && map[i + 2 * p.cols - 2] == user && map[i + 3 * p.cols - 3] == user)
	|| (map[i + col - 1]) == user && map[i + 2 * p.cols - 2] == user && map[i - p.cols + 1] == user)
	|| (map[i + col - 1]) == user && map[i - p.cols + 1] == user && map[i - p.cols * 2 + 2] == user)
	|| (map[i - col + 1]) == user && map[i - 2 * p.cols + 2] == user && map[i - p.cols * 3 + 3] == user))
		return (0);
	return (1);
}

void	display_map(char	*map, t_p4 *p)
{
	int		i;
	int		a;

	a = 0;
	while (a < p.lines)
	{
		i = 0;
		while (i++ < p.cols )
			ft_pustr(" 1 ");
		ft_putstr("\n");
		a++;
	}
	i = 0
	while (map[i++])
	{
		if (i == p.cols)
			ft_putchar('\n');
		ft_putchar('|');
		ft_putchar(map[i]);
		ft_putchar('|');
	}
	ft_putchar('\n');
}


