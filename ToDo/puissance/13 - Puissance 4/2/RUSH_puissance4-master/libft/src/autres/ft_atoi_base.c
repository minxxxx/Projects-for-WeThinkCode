/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 12:29:05 by thou              #+#    #+#             */
/*   Updated: 2017/03/16 18:16:38 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ctoi(char c)
{
	if (c >= '0' && c <= '9')
		return ((c - '0'));
	if (c >= 'a' && c <= 'f')
		return ((c - 'a' + 10));
	if (c == 'A' || c == 'F')
		return ((c - 'A' + 10));
	return (-1);
}

int			ft_atoi_base(const char *str, int base)
{
	char	*c;
	int		i;
	int		k;

	c = (char*)str;
	i = 0;
	k = 1;
	while (*c == ' ' || *c == '\n' || *c == '\t'
			|| *c == '\f' || *c == '\v' || *c == '\r')
		c++;
	if (*c == '-')
		k = -1;
	if (*c == '+' || *c == '-')
		c++;
	while (*c && ft_ctoi(*c) >= 0)
	{
		i = i * base + ft_ctoi(*c);
		c++;
	}
	i = i * k;
	return (i);
}
