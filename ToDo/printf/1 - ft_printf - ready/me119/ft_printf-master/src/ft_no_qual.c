/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_no_qual.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 12:00:32 by opodolia          #+#    #+#             */
/*   Updated: 2017/03/06 12:00:33 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** If there's no specifier and no characters to print, nothing is printed.
** If there are characters to print, the first printable character is
** printed with the specified width. '0' and '-' flags work.
*/

static void	ft_set_nomods(t_mods *mods)
{
	mods->flags.plus = 0;
	mods->flags.space = 0;
	mods->flags.hash = 0;
	mods->length = 0;
	mods->precision = -1;
}

int			ft_no_qual(t_mods *mods)
{
	int		size;
	char	*mas;
	char	tmp[2];

	ft_set_nomods(mods);
	tmp[0] = mods->qualifier;
	tmp[1] = '\0';
	size = ft_size(tmp, mods);
	mas = (char *)malloc(sizeof(char) * (size + 1));
	mods->flags.left ? ft_push_left(mods, &mas, size, tmp) :
		ft_push_right(mods, &mas, size, tmp);
	ft_putstr(mas);
	free(mas);
	return (size);
}
