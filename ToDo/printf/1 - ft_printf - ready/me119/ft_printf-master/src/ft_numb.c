/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 12:00:55 by opodolia          #+#    #+#             */
/*   Updated: 2017/03/14 17:34:01 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_numb(va_list ap, t_mods *mods)
{
	int		size;
	int		ret;
	char	c;
	char	*str;
	char	*mas;

	c = mods->qualifier;
	if (c == 'u' || c == 'x' || c == 'o' || c == 'X' || c == 'p'
			|| c == 'b')
		str = ft_convert_ulen(ap, mods, c);
	else
		str = ft_convert_len(ap, mods, c);
	size = ft_size(str, mods);
	mas = (char *)malloc(sizeof(char) * (size + 1));
	mods->flags.left ? ft_push_left(mods, &mas, size, str) :
		ft_push_right(mods, &mas, size, str);
	ft_putstr(mas);
	ret = ft_strlen(mas);
	free(str);
	free(mas);
	return (ret);
}
