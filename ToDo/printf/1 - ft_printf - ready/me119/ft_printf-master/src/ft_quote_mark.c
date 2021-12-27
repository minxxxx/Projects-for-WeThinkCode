/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quote_mark.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 16:01:24 by opodolia          #+#    #+#             */
/*   Updated: 2017/03/14 16:00:41 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_quote_mark(char *str)
{
	char	*s;
	int		i;
	int		len;
	int		new_len;
	int		count;

	count = 0;
	len = ft_strlen(str);
	count = (len % 3 == 0) ? len / 3 - 1 : len / 3;
	new_len = len + count;
	s = ft_strnew(new_len);
	while (new_len >= 0)
	{
		i = 3;
		while (new_len >= 0 && i--)
			s[--new_len] = str[--len];
		s[--new_len] = '\'';
	}
	free(str);
	return (s);
}
