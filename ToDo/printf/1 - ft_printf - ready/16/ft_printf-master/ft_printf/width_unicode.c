/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_unicode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 12:36:39 by dkotenko          #+#    #+#             */
/*   Updated: 2018/01/21 12:36:41 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_bytes(int n, int *numb)
{
	if (*numb != -1)
		*numb -= n;
	return (n);
}

int		u_byte(unsigned int u_str, int *numb)
{
	int		bytes;
	int		i;

	i = 0;
	bytes = 0;
	while (u_str)
	{
		u_str = u_str / 2;
		i++;
	}
	if (i < 8 && ((*numb == -1) || ((*numb - 1) >= 0)))
		bytes = ft_bytes(1, numb);
	else if (i > 7 && i < 12 && ((*numb == -1) || ((*numb - 2) >= 0)))
		bytes = ft_bytes(2, numb);
	else if (i > 11 && i < 17 && ((*numb == -1) || ((*numb - 3) >= 0)))
		bytes = ft_bytes(3, numb);
	else if (((*numb == -1) || (*numb - 4) >= 0))
		bytes = ft_bytes(4, numb);
	return (bytes);
}

int		width_part(int width, unsigned int *u_str, int numb, char flg)
{
	int		rtrn;

	rtrn = 0;
	if (numb != 0)
	{
		while (*u_str != 0 && width > 0)
		{
			width -= u_byte(*u_str, &numb);
			u_str++;
		}
	}
	if (width > 0)
		rtrn = width;
	while (width > 0)
	{
		if (!((flg >> 4) & 1))
			write(1, " ", 1);
		else
			write(1, "0", 1);
		width--;
	}
	return (rtrn);
}

int		width_unicode(unsigned int *inpt, int width, int acc, char flg)
{
	unsigned int	*u_str;
	unsigned int	*p_u_free;
	int				len;
	int				numb;

	numb = acc;
	len = 0;
	while (inpt[len])
		len++;
	if (!(u_str = (unsigned int*)malloc(sizeof(unsigned int) * (len + 1))))
		return (0);
	p_u_free = u_str;
	len = -1;
	while (inpt[++len])
		u_str[len] = inpt[len];
	u_str[len] = 0;
	free(p_u_free);
	return (width_part(width, u_str, numb, flg));
}
