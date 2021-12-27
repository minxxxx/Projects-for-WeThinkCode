/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <exam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 10:32:46 by exam              #+#    #+#             */
/*   Updated: 2018/05/10 15:39:57 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		power(int power)
{
	int			i;

	i = 1;
	if (power == 0)
		return (1);
	while (power--)
		i *= 2;
	return (i);
}

static int		ft_occ(char *s, char c)
{
	int			x;

	x = 0;
	while (s[x])
	{
		if (s[x] == c)
			return (x);
		x++;
	}
	if (s[x] == c)
		return (x);
	return (-1);
}

void			ft_color_choices(int opt, int zone)
{
	if (opt & D)
	{
		if (zone == 1)
			write(1, "\x1B[31m", 5);
		else if (zone == 2)
			write(1, "\x1B[32m", 5);
		else if (zone == 3)
			write(1, "\x1B[33m", 5);
	}
}

char			*options(char *s, int *oct)
{
	int			x;
	int			ret;

	x = 1;
	ret = 0;
	if (s[0] != '-' || (s[0] == '-' && ft_isdigit(s[x])) || !s[x])
		return (s);
	s[0] = ' ';
	while (s[x])
	{
		ret = ft_occ("bcdpuv", s[x]);
		if (ret == -1)
			return (NULL);
		s[x] = ' ';
		ret = power(ret);
		*oct |= ret;
		x++;
	}
	return (s);
}

char			**option_check(char **av, int ac, int *opt)
{
	int			sv;
	int			i;

	i = 1;
	sv = 0;
	while (i < ac)
	{
		if (av[i][0] == '-' && !(av[i] = options(av[i], &sv)))
		{
			ft_color_choices(sv, 3);
			write(2, "Error\n", 6);
			write(2, "Usage: exe [bcdpv] [list of numbers]\n", 38);
			return (NULL);
		}
		if (ac == 1 || (ft_check_av(ac, av) == 0))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		i++;
	}
	*opt = sv;
	return (av);
}
