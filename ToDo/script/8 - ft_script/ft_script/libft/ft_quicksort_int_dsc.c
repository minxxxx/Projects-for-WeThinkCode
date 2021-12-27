/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort_int_dsc.c                             :+:      :+:    :+:   */
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

static int	part_it(int *tab, int start, int end)
{
	int		pivot;
	int		i;
	int		j;
	int		temp;

	pivot = tab[start];
	i = start - 1;
	j = end + 1;
	while (1)
	{
		while (tab[--j] < pivot)
			;
		while (tab[++i] > pivot)
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

void		ft_quicksort_int_dsc(int *tab, int start, int end)
{
	int		pivot;

	if (start < end)
	{
		pivot = part_it(tab, start, end);
		ft_quicksort_int_dsc(tab, start, pivot);
		ft_quicksort_int_dsc(tab, pivot + 1, end);
	}
}
