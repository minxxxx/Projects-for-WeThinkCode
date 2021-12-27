/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printtab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 10:26:43 by juspende          #+#    #+#             */
/*   Updated: 2017/12/06 10:32:03 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int		ft_printtab(char **tab)
{
	int		i;

	i = -1;
	if (!tab || !tab[0])
		return (0);
	while (tab[++i])
	{
		write(1, tab[i], ft_strlen(tab[i]));
		write(1, "\n", 1);
	}
	return (0);
}
