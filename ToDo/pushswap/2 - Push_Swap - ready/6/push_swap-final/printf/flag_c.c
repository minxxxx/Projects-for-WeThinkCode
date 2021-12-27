/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfavero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 16:13:45 by cfavero           #+#    #+#             */
/*   Updated: 2018/03/14 16:00:19 by cfavero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	ft_boh1(t_flag *flag, int i)
{
	ft_putchar(' ');
	flag->numb--;
	i++;
	return (i);
}

static int	ft_boh2(t_flag *flag, int i)
{
	ft_putchar('0');
	flag->numb--;
	i++;
	return (i);
}

static int	ft_big_c(va_list *ap, t_flag *flag)
{
	int		i;
	wchar_t	k;
	char	*c;

	k = va_arg(*ap, wchar_t);
	c = ft_unicode(k);
	i = 1;
	if (k == 0)
		ft_putchar(k);
	else if (flag->numb != 0)
	{
		while (flag->meno == 0 && flag->numb > 1 && flag->zero == 0)
			i = ft_boh1(flag, i);
		while (flag->numb > 1 && flag->zero == 1)
			i = ft_boh2(flag, i);
		ft_putstr(c);
		while (flag->numb > 1 && flag->zero == 0)
			i = ft_boh1(flag, i);
	}
	else if (k != 0)
		ft_putstr(c);
	k != 0 ? (i += ft_strlen(c) - 1) : 0;
	if (c)
		free(c);
	return (i);
}

int			ft_flag_c(va_list *ap, t_flag *flag)
{
	int		i;
	char	c;

	i = 1;
	if (flag->val_size == 5 || flag->val_conv == 'C')
		i = ft_big_c(ap, flag);
	else
	{
		(flag->val_conv != 'c') ? (c = flag->val_conv) \
			: (c = (unsigned char)va_arg(*ap, int));
		if (flag->numb != 0)
		{
			while (flag->meno == 0 && flag->numb > 1 && flag->zero == 0)
				i = ft_boh1(flag, i);
			while (flag->numb > 1 && flag->zero == 1 && flag->meno == 0)
				i = ft_boh2(flag, i);
			ft_putchar(c);
			while (flag->numb > 1 && (flag->zero == 0 || flag->meno == 1))
				i = ft_boh1(flag, i);
		}
		else
			ft_putchar(c);
	}
	return (i);
}
