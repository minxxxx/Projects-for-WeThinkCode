/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 10:31:56 by wide-aze          #+#    #+#             */
/*   Updated: 2015/05/03 13:35:27 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	http://fr.wikipedia.org/wiki/Tri_rapide
*/

#include <libft.h>

static char	part_it(char **tab, int start, int end)
{
	char	*pivot;
	int		i;
	int		j;
	char	*temp;

	pivot = tab[start];
	i = start - 1;
	j = end + 1;
	while (1)
	{
		while (ft_strcmp(tab[--j], pivot) > 0)
			;
		while (ft_strcmp(tab[++i], pivot) < 0)
			;
		if (i < j)
		{
			temp = tab[i];
			tab[i] = tab[j];
			tab[j] = temp;
		}
		else
			return (j);
	}
}

void		ft_quicksort_str(char **tab, int start, int end)
{
	int		pivot;

	if (start < end)
	{
		pivot = part_it(tab, start, end);
		ft_quicksort_str(tab, start, pivot);
		ft_quicksort_str(tab, pivot + 1, end);
	}
}
