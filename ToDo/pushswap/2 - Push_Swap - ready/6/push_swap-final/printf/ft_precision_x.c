/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfavero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 17:14:45 by cfavero           #+#    #+#             */
/*   Updated: 2018/03/13 15:46:07 by cfavero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_change_nbr(char *nb, int p)
{
	int		i;
	char	*new;

	i = ft_strlen(nb);
	new = NULL;
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
	if (nb)
		free(nb);
	return (new);
}

static char	*ft_change_capital(char *nb)
{
	int i;

	i = 0;
	while (nb[i] != '\0')
	{
		if (nb[i] >= 'A' && nb[i] <= 'Z')
			nb[i] = nb[i] + 32;
		i++;
	}
	return (nb);
}

char		*ft_precision_x(t_flag *f, unsigned long long nb)
{
	char	*nbr;

	nbr = NULL;
	f->val_conv == 'x' || f->val_conv == 'X' ? (nbr = ft_uitoa_base(nb, 16)) \
			: (nbr = ft_uitoa_base(nb, 8));
	(f->val_conv == 'o' && f->prec == 1 && nb != 0 &&
	f->val_prec > (int)ft_strlen(nbr)) ? f->hash = 0 : 0;
	if (f->prec == 1)
	{
		if (f->val_prec == 0 && nb == 0)
			nbr = ft_strdup("");
		else if (f->val_prec <= (int)ft_strlen(nbr))
			f->prec = 0;
		else
			nbr = ft_change_nbr(nbr, f->val_prec);
		if (f->val_prec >= f->numb)
		{
			f->numb = f->val_prec;
			f->prec = 0;
			f->zero = 1;
		}
		f->val_prec < f->numb ? f->zero = 0 : 0;
	}
	f->val_conv == 'x' ? (nbr = ft_change_capital(nbr)) : 0;
	return (nbr);
}
