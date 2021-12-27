/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thendric <thendric@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 18:55:48 by thendric          #+#    #+#             */
/*   Updated: 2016/11/13 13:24:43 by thendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puttab(char **tab)
{
	size_t	i;

	i = 0;
	if (tab)
	{
		while (i < ft_strlen(*tab))
		{
			ft_putstr(tab[i]);
			write(1, "\n", 1);
			i++;
		}
	}
}
