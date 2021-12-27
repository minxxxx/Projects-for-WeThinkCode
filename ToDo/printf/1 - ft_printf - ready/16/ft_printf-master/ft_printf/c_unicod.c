/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_unicod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 17:12:00 by dkotenko          #+#    #+#             */
/*   Updated: 2018/01/24 17:12:03 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		bytes_c(int i)
{
	if (i < 8)
		i = 1;
	else if (i > 7 && i < 12)
		i = 2;
	else if (i > 11 && i < 17)
		i = 3;
	else
		i = 4;
	return (i);
}

int		width_unicode_c(unsigned int numb, int width, char flg)
{
	int		rtrn;
	int		i;

	rtrn = 0;
	i = 0;
	while (numb)
	{
		numb = numb / 2;
		i++;
	}
	i = bytes_c(i);
	while ((width - i) > 0)
	{
		if (!((flg >> 4) & 1))
			write(1, " ", 1);
		else
			write(1, "0", 1);
		width--;
		rtrn++;
	}
	return (rtrn);
}

int		unicode_elem_c(unsigned int inpt, int ret)
{
	unsigned int	numb;
	int				i;

	numb = inpt;
	i = 0;
	while (inpt)
	{
		inpt = inpt / 2;
		i++;
	}
	if (i < 8)
	{
		write(1, &numb, 1);
		ret++;
	}
	else if (i > 7 && i < 12)
		ret = maska1(numb, ret);
	else if (i > 11 && i < 17)
		ret = maska2(numb, ret);
	else
		ret = maska3(numb, ret);
	return (ret);
}

int		c_unicod(va_list ap, int width, char flg)
{
	unsigned int	inpt;
	int				ret;

	ret = 0;
	inpt = va_arg(ap, unsigned int);
	if (MB_CUR_MAX == 1 && inpt < 255)
	{
		write(1, &inpt, 1);
		return (1);
	}
	else if (MB_CUR_MAX == 1)
		return (-1);
	if (width > 0 && !(flg & 1))
		ret += width_unicode_c(inpt, width, flg);
	ret = unicode_elem_c(inpt, ret);
	if (width > 0 && (flg & 1))
		ret += width_unicode_c(inpt, width, flg);
	return (ret);
}
