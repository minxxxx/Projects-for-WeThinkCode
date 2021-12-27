/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 11:58:31 by opodolia          #+#    #+#             */
/*   Updated: 2017/03/14 18:24:07 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_set_cmods(t_mods *mods, char *str)
{
	if (!str[0] && mods->width > 0)
		mods->width--;
	mods->flags.plus = 0;
	mods->flags.space = 0;
	mods->flags.hash = 0;
	mods->precision = -1;
	mods->length = 0;
}

static char		*ft_get_char(va_list ap)
{
	char	c;
	char	*str;

	str = (char *)malloc(sizeof(char) * 2);
	c = va_arg(ap, int);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

int				ft_char(va_list ap, t_mods *mods)
{
	int		size;
	char	*str;
	char	*mas;

	str = ft_get_char(ap);
	ft_set_cmods(mods, str);
	size = ft_size(str, mods);
	mas = (char *)malloc(sizeof(char) * (size + 1));
	mods->flags.left ? ft_push_left(mods, &mas, size, str) :
		ft_push_right(mods, &mas, size, str);
	if (mods->flags.left && !str[0])
		ft_putchar('\0');
	ft_putstr(mas);
	if (!mods->flags.left && !str[0])
		ft_putchar('\0');
	if (!str[0])
		size++;
	free(str);
	free(mas);
	return (size);
}
