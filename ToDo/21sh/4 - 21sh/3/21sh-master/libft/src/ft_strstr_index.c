/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 11:46:49 by fkoehler          #+#    #+#             */
/*   Updated: 2016/09/13 18:09:30 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strstr_index(const char *big, const char *little)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (big[i])
	{
		while (little[j] && (big[i] == little[j]))
		{
			i++;
			j++;
		}
		if (!little[j])
			return (i - j);
		i = (i - j + 1);
		j = 0;
	}
	return (-1);
}
