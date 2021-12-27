/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfavero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 15:27:58 by cfavero           #+#    #+#             */
/*   Updated: 2018/03/13 15:39:49 by cfavero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int					ft_numb_meno(t_flag *flag, char *nbr)
{
	int					count;
	int					i;

	i = 0;
	count = ft_strlen(nbr);
	if ((flag->hash == 1 && nbr != 0) || (flag->p == 1))
	{
		if (flag->val_conv == 'x')
			ft_putstr("0x");
		else
			ft_putstr("0X");
		count = 2 + count;
	}
	ft_putstr(nbr);
	if (count > flag->numb)
		i = count;
	else
		i = flag->numb;
	flag->numb = (flag->numb - count);
	while (flag->numb > 0)
	{
		ft_putchar(' ');
		flag->numb--;
	}
	return (i);
}

static void					ft_boh(t_flag *flag, char *nbr)
{
	if (flag->zero == 1)
	{
		if ((flag->val_conv == 'x' && flag->hash == 1 && nbr != 0) ||
				(flag->p == 1))
		{
			flag->p = 0;
			ft_putstr("0x");
		}
		else if (flag->hash == 1 && nbr != 0)
			ft_putstr("0X");
		ft_putchar('0');
		flag->hash = 0;
	}
	else
		ft_putchar(' ');
	flag->numb--;
}

static int					ft_numb(t_flag *flag, char *nbr)
{
	int				count;
	int				sign;
	int				i;

	sign = 0;
	i = 0;
	if (flag->hash == 1)
		i = 2;
	count = ft_strlen(nbr) + i;
	if (count > flag->numb)
		i = count;
	else
		i = flag->numb;
	flag->numb = (flag->numb - count);
	while (flag->numb > 0)
		ft_boh(flag, nbr);
	if ((flag->val_conv == 'x' && flag->hash == 1 && nbr != 0) ||
			(flag->p == 1))
		ft_putstr("0x");
	else if (flag->hash == 1 && flag->zero == 0 && nbr != 0)
		ft_putstr("0X");
	ft_putstr(nbr);
	return (i);
}

static unsigned long long	ft_flag_p(va_list *ap, t_flag *flag)
{
	unsigned long long	nb;

	nb = (unsigned long long)va_arg(*ap, void*);
	flag->val_size = 0;
	flag->hash = 1;
	flag->p = 1;
	flag->val_conv = 'x';
	return (nb);
}

int							ft_flag_x(va_list *ap, t_flag *flag)
{
	unsigned long long	nbr;
	char				*nb;
	int					i;

	if (flag->val_conv == 'x' || flag->val_conv == 'X')
		nbr = ft_length_u(flag, ap);
	else
		nbr = ft_flag_p(ap, flag);
	nb = ft_precision_x(flag, nbr);
	i = 0;
	if (flag->numb == 0)
	{
		if ((flag->hash == 1 && nbr != 0) || flag->p == 1)
			flag->val_conv == 'x' ? ft_putstr("0x") : ft_putstr("0X");
		(flag->hash == 1 && nbr != 0) ? i = 2 : 0;
		flag->p == 1 ? i = 2 : 0;
		ft_putstr(nb);
		i += ft_strlen(nb);
	}
	else
		flag->meno == 1 ? (i = ft_numb_meno(flag, nb)) \
			: (i = ft_numb(flag, nb));
	if (nb)
		free(nb);
	return (i);
}
