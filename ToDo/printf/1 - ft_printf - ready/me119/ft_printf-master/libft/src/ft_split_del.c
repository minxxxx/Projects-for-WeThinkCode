/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 15:19:02 by opodolia          #+#    #+#             */
/*   Updated: 2017/03/20 15:19:03 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_split_del(char ***split)
{
	int		i;
	char	**str;

	i = 0;
	str = *split;
	while (*str)
	{
		ft_strdel(str);
		str = &(*split)[++i];
	}
	ft_memdel((void **)split);
	return (0);
}
