/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 16:05:59 by dtedgui           #+#    #+#             */
/*   Updated: 2016/04/26 16:06:02 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_del_char(char *origin, char c)
{
	char	*new;
	int		i;

	i = 0;
	new = ft_strnew(ft_strlen(origin) - ft_count_char(origin, c));
	while (*origin)
	{
		while (*origin == c)
			origin++;
		new[i] = *origin;
		i++;
		origin++;
	}
	return (new);
}
