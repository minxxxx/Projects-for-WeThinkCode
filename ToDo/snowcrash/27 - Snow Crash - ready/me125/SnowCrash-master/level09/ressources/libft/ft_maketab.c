/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maketab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 16:56:57 by dgalide           #+#    #+#             */
/*   Updated: 2016/02/01 05:07:33 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		**ft_maketab(int column, int line)
{
	int		i;
	char	**tab;

	i = 0;
	if (!column || !line)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (line + 1));
	if (!tab)
		return (NULL);
	while (i < line)
	{
		tab[i] = (char *)malloc(sizeof(char) * column + 1);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
