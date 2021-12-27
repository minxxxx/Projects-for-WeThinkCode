/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_forceprefix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 11:58:54 by abungert          #+#    #+#             */
/*   Updated: 2016/01/26 16:57:09 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					print_forceprefix(t_tag *tag, uintmax_t nbr,
						char *prefix, char *base)
{
	unsigned int	nbr_strlen;
	unsigned int	prefix_cut;
	int				prefix_len;
	unsigned int	nbr_len;

	prefix_cut = (!ft_strcmp(prefix, " ") ? 0 : 1);
	nbr_strlen = nbr_strlength(tag, nbr, base);
	nbr_len = nbr_length(nbr, base);
	prefix_len = ft_strlen(prefix);
	if (tag->has_width && !tag->flag_minus && !tag->flag_zero)
	{
		print_width_pad(nbr_strlen, tag->width - prefix_cut, ' ');
		tag->width -= ft_strlen(prefix);
	}
	else if (tag->has_width)
		tag->width -= ft_strlen(prefix);
	ft_putstr(prefix);
	return (prefix_len + nbr_strlen);
}
