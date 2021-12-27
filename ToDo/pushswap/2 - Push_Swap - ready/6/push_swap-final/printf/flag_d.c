/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfavero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 15:12:47 by cfavero           #+#    #+#             */
/*   Updated: 2018/03/13 17:42:50 by cfavero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_numb_zero(t_flag *flag, long long nb, char *nbr)
{
	int i;

	i = 0;
	if (flag->plus == 1)
	{
		if (nb >= 0)
		{
			ft_putchar('+');
			i++;
		}
		ft_putstr(nbr);
	}
	else if (flag->space == 1)
	{
		if (nb >= 0)
		{
			ft_putchar(' ');
			i++;
		}
		ft_putstr(nbr);
	}
	else
		ft_putstr(nbr);
	i += ft_strlen(nbr);
	return (i);
}

static int		ft_numb_meno(t_flag *flag, long long nb, char *nbr)
{
	int count;
	int i;

	i = 0;
	(flag->plus == 1 && nb >= 0) ? ft_putchar('+') : 0;
	(flag->plus == 1 && nb >= 0) ? i++ : 0;
	(flag->plus == 1 && nb >= 0) ? flag->numb-- : 0;
	if (flag->space == 1 && nb >= 0 && flag->plus == 0)
	{
		ft_putchar(' ');
		flag->numb--;
		i++;
	}
	count = ft_strlen(nbr);
	(count > flag->numb) ? (i += count) \
		: (i += flag->numb);
	ft_putstr(nbr);
	flag->numb = (flag->numb - count);
	while (flag->numb > 0)
	{
		ft_putchar(' ');
		flag->numb--;
	}
	return (i);
}

static int		ft_zero(t_flag *flag, long long nb, int sign, char *nbr)
{
	if ((flag->plus == 1 && sign == 0) && nb >= 0)
	{
		ft_putchar('+');
		sign++;
		flag->numb--;
	}
	else if ((sign == 0 && flag->plus == 1) || (nbr[0] == '-' && sign == 0))
	{
		ft_putchar('-');
		sign++;
	}
	else if (sign == 0 && flag->space == 1)
	{
		ft_putchar(' ');
		sign++;
		flag->numb--;
	}
	if (flag->numb > 0)
		ft_putchar('0');
	return (sign);
}

static int		ft_numb(t_flag *f, char *nbr, long long nb)
{
	int count;
	int sign;
	int i;

	sign = 0;
	count = ft_strlen(nbr);
	(count > f->numb) ? i = count \
		: (i = f->numb);
	f->numb = (f->numb - count);
	(f->numb < 1 && f->plus == 1 && nb > 0) ? ft_putchar('+') : 0;
	(f->numb < 1 && f->plus == 1 && nb > 0) ? i++ : 0;
	while (f->numb > 0)
	{
		(f->zero == 1) ? sign = ft_zero(f, nb, sign, nbr) : 0;
		if (f->zero != 1)
		{
			((f->numb == 1 && f->plus == 1) && nb > 0) ? ft_putchar('+') : 0;
			((f->numb == 1 && f->plus == 1) && nb > 0) ? f->numb-- : 0;
			f->numb > 0 ? ft_putchar(' ') : 0;
		}
		f->numb--;
	}
	(nbr[0] == '-' && sign != 0) ? ft_putstr(nbr + 1) : ft_putstr(nbr);
	return (i);
}

int				ft_flag_d(va_list *ap, t_flag *flag)
{
	long long	nbr;
	char		*nb;
	int			i;

	nbr = ft_length_d(flag, ap);
	nb = ft_precision_d(flag, nbr);
	if (flag->numb == 0)
		i = ft_numb_zero(flag, nbr, nb);
	else
	{
		if (flag->meno == 1)
			i = ft_numb_meno(flag, nbr, nb);
		else
			i = ft_numb(flag, nb, nbr);
	}
	if (nb)
		free(nb);
	return (i);
}
