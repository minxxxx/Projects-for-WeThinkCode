/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 13:28:19 by dkotenko          #+#    #+#             */
/*   Updated: 2018/01/19 13:28:20 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_n_maska(int *n_acc, int n, int ret, unsigned int numb)
{
	if (n == 2)
		ret = maska1(numb, ret);
	else if (n == 3)
		ret = maska2(numb, ret);
	else if (n == 4)
		ret = maska3(numb, ret);
	if (*n_acc != -1)
		*n_acc -= n;
	return (ret);
}

int		unicode_elem(unsigned int inpt, int ret, int *n_acc)
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
	if (i < 8 && ((*n_acc == -1) || ((*n_acc - 1) >= 0)))
	{
		write(1, &numb, 1);
		ret++;
		if (*n_acc != -1)
			*n_acc -= 1;
	}
	else if (i > 7 && i < 12 && ((*n_acc == -1) || ((*n_acc - 2) >= 0)))
		ret = ft_n_maska(n_acc, 2, ret, numb);
	else if (i > 11 && i < 17 && ((*n_acc == -1) || ((*n_acc - 3) >= 0)))
		ret = ft_n_maska(n_acc, 3, ret, numb);
	else if (((*n_acc == -1) || (*n_acc - 4) >= 0))
		ret = ft_n_maska(n_acc, 4, ret, numb);
	return (ret);
}

int		ft_null(void)
{
	write(1, "(null)", 6);
	return (6);
}

int		ret_unicode(va_list ap, int acc, int width, char flg)
{
	unsigned int	*inpt;
	int				ret;
	int				i;
	int				numb;

	numb = acc;
	ret = 0;
	i = 0;
	inpt = va_arg(ap, unsigned int *);
	if (inpt == NULL)
		return (ft_null());
	if (width > 0 && !(flg & 1))
		ret += width_unicode(inpt, width, acc, flg);
	while (inpt[i] != 0 && ((numb == -1) || (numb > 0)))
	{
		ret = unicode_elem(inpt[i], ret, &numb);
		i++;
	}
	if (width > 0 && (flg & 1))
		ret += width_unicode(inpt, width, acc, flg);
	return (ret);
}
