/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfavero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 17:14:45 by cfavero           #+#    #+#             */
/*   Updated: 2018/03/09 16:00:33 by cfavero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_change_meno(char *new, int p, int i, char *nb)
{
	p++;
	new = ft_strnew(p);
	while (i > 0)
	{
		i--;
		p--;
		new[p] = nb[i];
	}
	while (p >= 0)
	{
		new[p] = '0';
		p--;
	}
	new[0] = '-';
	return (new);
}

static char	*ft_change_nbr(char *nb, int p)
{
	int		i;
	char	*new;

	i = ft_strlen(nb);
	new = NULL;
	if (nb[0] == '-')
		new = ft_change_meno(new, p, i, nb);
	else
	{
		new = ft_strnew(p);
		while (i >= 0)
		{
			new[p] = nb[i];
			i--;
			p--;
		}
		while (p >= 0)
		{
			new[p] = '0';
			p--;
		}
	}
	if (nb)
		free(nb);
	return (new);
}

char		*ft_precision_d(t_flag *flag, long long nb)
{
	char	*nbr;

	nbr = NULL;
	if (flag->val_conv == 'u' || flag->val_conv == 'U')
		nbr = ft_uitoa_base(nb, 10);
	else
		nbr = ft_itoa_base(nb, 10);
	if (flag->prec == 1)
	{
		if (flag->val_prec == 0 && nb == 0)
			nbr = ft_strdup("");
		else if (flag->val_prec < (int)ft_strlen(nbr))
			flag->prec = 0;
		else
			nbr = ft_change_nbr(nbr, flag->val_prec);
		if (flag->val_prec >= flag->numb)
		{
			flag->numb = flag->val_prec;
			flag->prec = 0;
			flag->zero = 1;
		}
		else
			flag->zero = 0;
	}
	return (nbr);
}
