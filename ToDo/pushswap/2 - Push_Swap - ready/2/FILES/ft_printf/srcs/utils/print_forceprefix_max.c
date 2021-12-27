/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_forceprefix_max.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 12:12:51 by abungert          #+#    #+#             */
/*   Updated: 2016/01/26 16:58:07 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						nbr_length_max(intmax_t nbr, char *base)
{
	int					i;
	size_t				base_len;

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

int						nbr_strlength_max(t_tag *tag, intmax_t nbr, char *base)
{
	int					nbr_strlen;
	int					nbr_len;

	nbr_len = nbr_length_max(nbr, base);
	if (nbr == 0 && tag->has_precision && tag->precision == 0)
		nbr_strlen = 0;
	else if (tag->has_precision)
		nbr_strlen = ft_max(nbr_len, tag->precision);
	else
		nbr_strlen = nbr_len;
	return (nbr_strlen);
}

int						print_forceprefix_max(t_tag *tag, intmax_t nbr,
							char *prefix, char *base)
{
	int					nbr_len;
	int					prefix_cut;
	int					prefix_len;

	prefix_cut = (!ft_strcmp(prefix, " ") ? 0 : 1);
	nbr_len = nbr_strlength_max(tag, nbr, base);
	prefix_len = ft_strlen(prefix);
	if (tag->has_width && !tag->flag_minus && !tag->flag_zero)
	{
		prefix_len = 0;
		print_width_pad(nbr_len, tag->width - prefix_cut, ' ');
	}
	else if (tag->has_width)
		tag->width -= ft_strlen(prefix);
	if (nbr >= -9223372036854775807)
		ft_putstr(prefix);
	return (prefix_len + nbr_len);
}
