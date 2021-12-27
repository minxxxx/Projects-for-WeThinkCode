/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 07:42:13 by pbondoer          #+#    #+#             */
/*   Updated: 2016/12/24 08:08:02 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int			die(char *reason)
{
	ft_putendl(reason);
	return (1);
}

int			main(int ac, char **av)
{
	int c;
	int i;
	int last;

	if (ac < 2)
		return (die("error: no arguments, please specify an integer list"));
	i = 1;
	last = INT_MIN;
	while (i < ac)
	{
		if (!ft_isnumber(av[i]))
			return (die("error: invalid arguments"));
		c = ft_atoi(av[i]);
		if (c < last)
			return (die("KO"));
		last = c;
		i++;
	}
	ft_putendl("OK");
	return (0);
}
