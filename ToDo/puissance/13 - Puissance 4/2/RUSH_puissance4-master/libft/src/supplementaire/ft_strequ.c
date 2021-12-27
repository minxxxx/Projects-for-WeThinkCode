/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 10:44:32 by thou              #+#    #+#             */
/*   Updated: 2016/11/17 11:02:18 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	char	*a;
	char	*b;
	int		i;

	a = (char*)s1;
	b = (char*)s2;
	if (!a && !b)
		return (0);
	else if (!a || !b)
		return (1);
	i = 0;
	while (a[i])
		ft_tolower(a[i++]);
	i = 0;
	while (b[i])
		ft_tolower(b[i++]);
	return (ft_strcmp(a, b) == 0 ? 1 : 0);
}
