/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 14:56:45 by glarivie          #+#    #+#             */
/*   Updated: 2015/12/29 14:59:06 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puttab(char **tab)
{
	int		col;

	col = -1;
	if (tab)
	{
		while (tab[++col] != NULL)
			ft_putendl(tab[col]);
		ft_putchar('\n');
	}
}
