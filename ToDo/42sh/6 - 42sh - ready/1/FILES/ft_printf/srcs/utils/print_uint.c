/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 12:06:29 by dtedgui           #+#    #+#             */
/*   Updated: 2016/02/01 16:43:41 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_uint(t_tag *tag, uintmax_t nbr, char *base, char *prefix)
{
	unsigned int	nbr_strlen;
	unsigned int	nbr_len;
	int				total;

	total = ((prefix != NULL && nbr != 0 && tag->flag_sharp)
		? ft_strlen(prefix) : 0);
	nbr_len = nbr_length(nbr, base);
	nbr_strlen = nbr_strlength(tag, nbr, base);
	nbr_strlen = (tag->specifier == 'p' ? nbr_strlen += 2 : nbr_strlen);
	if (tag->has_width && !tag->flag_minus && !tag->flag_zero)
		print_width_pad(nbr_strlen, (tag->flag_sharp ?
			tag->width - total : tag->width), ' ');
	if ((tag->flag_sharp || tag->specifier == 'p') && prefix && nbr)
		ft_putstr(prefix);
	if (tag->has_width && tag->flag_zero)
		print_width_pad(nbr_len, tag->width - total, '0');
	else if (tag->has_precision)
		print_width_pad(nbr_len, nbr_strlen, '0');
	ft_putnbr_base_max(nbr, base);
	if (tag->has_width && tag->flag_minus)
		print_width_pad(nbr_strlen, tag->width - total, ' ');
	if (tag->has_width)
		return (ft_max(tag->width, nbr_strlen));
	else
		return (nbr_strlen + total);
}
