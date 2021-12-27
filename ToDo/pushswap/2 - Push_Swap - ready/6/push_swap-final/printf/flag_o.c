/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfavero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 14:15:24 by cfavero           #+#    #+#             */
/*   Updated: 2018/03/13 14:23:03 by cfavero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_numb_meno(t_flag *flag, char *nbr)
{
	int count;
	int i;

	i = 0;
	count = ft_strlen(nbr);
	if (flag->hash == 1)
	{
		ft_putstr("0");
		count = 1 + count;
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

static int		ft_numb(t_flag *flag, char *nbr)
{
	int count;
	int sign;
	int i;

	sign = 0;
	count = ft_strlen(nbr);
	if (flag->hash == 1)
		count++;
	if (count > flag->numb)
		i = count;
	else
		i = flag->numb;
	flag->numb = (flag->numb - count);
	while (flag->numb > 0)
	{
		if (flag->zero == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		flag->numb--;
	}
	if (flag->hash == 1)
		ft_putchar('0');
	ft_putstr(nbr);
	return (i);
}

static int		ft_boh(int i, char *nb)
{
	if (nb)
		free(nb);
	return (i);
}

int				ft_flag_o(va_list *ap, t_flag *flag)
{
	unsigned long long	nbr;
	char				*nb;
	int					i;

	nbr = ft_length_u(flag, ap);
	nb = ft_precision_x(flag, nbr);
	i = 0;
	if (flag->numb == 0)
	{
		if ((flag->hash == 1 && nbr != 0) || (flag->hash == 1 && *nb == '\0'))
		{
			ft_putstr("0");
			i++;
		}
		ft_putstr(nb);
		i += ft_strlen(nb);
	}
	else
	{
		if (flag->meno == 1)
			i = ft_numb_meno(flag, nb);
		else
			i = ft_numb(flag, nb);
	}
	return (ft_boh(i, nb));
}
