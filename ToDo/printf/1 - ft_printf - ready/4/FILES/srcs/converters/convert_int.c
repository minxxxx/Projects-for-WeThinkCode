/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 14:31:37 by abungert          #+#    #+#             */
/*   Updated: 2016/02/01 16:42:17 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			ft_getsize(intmax_t nbr)
{
	if (nbr < 10 && nbr > -10)
	{
		if (nbr < 10 && nbr >= 0)
			return (1);
		return (2);
	}
	return (ft_getsize(nbr / 10) + 1);
}

int					handle_prefix(intmax_t nbr, char *prefix, t_tag *tag)
{
	if (nbr < 0)
	{
		nbr = -nbr;
		prefix = "-";
	}
	else if (tag->flag_plus)
		prefix = "+";
	else if (tag->flag_space)
		prefix = " ";
	else
		prefix = "";
	if (nbr >= -2147483647)
		return (print_forceprefix(tag, nbr, prefix, "0123456789"));
	else
		return (print_forceprefix_max(tag, nbr, prefix, "0123456789"));
}

int					print_int(t_tag *tag, intmax_t nbr)
{
	char			*prefix;
	unsigned int	nbr_strlen;
	unsigned int	nbr_len;
	int				cut;

	prefix = NULL;
	cut = 0;
	nbr_len = nbr_length(nbr, "0123456789");
	nbr_strlen = nbr_strlength(tag, nbr, "0123456789");
	if ((nbr < 0 || tag->flag_plus || tag->flag_space) && (cut += 1))
		nbr_strlen = handle_prefix(nbr, prefix, tag);
	else if (tag->has_width && !tag->flag_minus && !tag->flag_zero)
		print_width_pad(nbr_strlen, tag->width, ' ');
	nbr = (nbr < 0 ? -nbr : nbr);
	if (tag->has_width && tag->flag_zero)
		print_width_pad(nbr_strlen - cut, tag->width, '0');
	else if (tag->has_precision)
		print_width_pad(ft_getsize(nbr), tag->precision, '0');
	ft_putnbr_max(nbr);
	if (tag->has_width && tag->flag_minus)
		print_width_pad(nbr_strlen - cut, tag->width, ' ');
	if (tag->has_width)
		return (ft_max(tag->width + cut, nbr_strlen));
	return (nbr_strlen);
}

int					convert_int(t_tag *tag, va_list *args)
{
	intmax_t		output_arg;

	output_arg = va_arg(*args, intmax_t);
	output_arg = get_signed_length(output_arg, tag);
	if (output_arg == 0 && tag->has_precision &&
		(tag->precision == 1 || tag->precision == 0))
	{
		if (!tag->has_width)
			return (tag->precision = 0);
		else
		{
			print_width_pad(0, tag->width, ' ');
			return (tag->width);
		}
	}
	return (print_int(tag, output_arg));
}
