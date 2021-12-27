/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 22:37:51 by juspende          #+#    #+#             */
/*   Updated: 2017/12/05 17:47:46 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

char			*ft_getnbr_base_ui(uintmax_t nbr, char *base)
{
	char			*str;
	uintmax_t		i;
	int				x;
	uintmax_t		nb;

	i = 0;
	x = 0;
	if ((str = ft_strnew(96)) == NULL)
		return (NULL);
	nb = nbr;
	while (base[i] != '\0')
		i = i + 1;
	while (nb >= i)
	{
		str[x++] = base[(nb % i)];
		nb = nb / i;
	}
	str[x++] = base[(nb % i)];
	return (ft_strrev(str));
}
