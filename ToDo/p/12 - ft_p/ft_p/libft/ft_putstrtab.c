/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrtab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 17:21:20 by wide-aze          #+#    #+#             */
/*   Updated: 2015/02/21 17:31:29 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putstrtab(char **tab, char *delimiter, char *ender)
{
	int		i;

	i = -1;
	while (tab[++i])
	{
		ft_putstr(tab[i]);
		if (tab[i + 1])
			ft_putstr(delimiter);
	}
	ft_putstr(ender);
}
