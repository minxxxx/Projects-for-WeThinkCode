/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_strlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 12:09:32 by abungert          #+#    #+#             */
/*   Updated: 2016/01/26 16:56:09 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	nbr_length(uintmax_t nbr, char *base)
{
	unsigned int	i;
	size_t			base_len;

	base_len = ft_strlen(base);
	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr /= base_len;
		i++;
	}
	return (i);
}

unsigned int	nbr_strlength(t_tag *tag, uintmax_t nbr, char *base)
{
	unsigned int	nbr_strlen;
	unsigned int	nbr_len;

	nbr_len = nbr_length(nbr, base);
	if (nbr == 0 && tag->has_precision && tag->precision == 0)
		nbr_strlen = 1;
	else if (tag->has_precision)
		nbr_strlen = ft_max(nbr_len, tag->precision);
	else
		nbr_strlen = nbr_len;
	return (nbr_strlen);
}
