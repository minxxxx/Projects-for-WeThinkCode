/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 15:24:10 by opodolia          #+#    #+#             */
/*   Updated: 2016/12/07 17:34:27 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_quicksort(int *arr, int first, int last)
{
	int	f;
	int	l;

	if (arr && first < last)
	{
		f = first;
		l = last;
		while (f < l)
		{
			while (arr[f] <= arr[first] && f < last)
				f++;
			while (arr[l] > arr[first])
				l--;
			if (f < l)
				ft_swap(&arr[f], &arr[l]);
		}
		ft_swap(&arr[first], &arr[l]);
		ft_quicksort(arr, first, l - 1);
		ft_quicksort(arr, l + 1, last);
	}
}
