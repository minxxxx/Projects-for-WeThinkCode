/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_null.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 16:12:46 by dtedgui           #+#    #+#             */
/*   Updated: 2016/04/26 16:12:49 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_remove_null(char **arr, int origin_size)
{
	int		i;
	int		j;
	int		tmp;

	i = 0;
	if (ft_tablen(arr) != origin_size)
	{
		while (i < origin_size + 1)
		{
			if (arr[i] == NULL)
			{
				tmp = i;
				j = i + 1;
				while (j < origin_size + 1)
				{
					arr[i] = arr[j];
					i++;
					j++;
				}
				i = tmp;
			}
			i++;
		}
	}
}
