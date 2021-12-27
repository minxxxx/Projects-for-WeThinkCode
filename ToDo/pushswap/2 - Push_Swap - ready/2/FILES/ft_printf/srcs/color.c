/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 16:27:21 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/28 10:41:43 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		check_color(char *color, char *format)
{
	int			len;
	char		*color_asked;

	len = ft_strlen(color);
	color_asked = ft_strsub(format, 0, len);
	if (ft_strcmp(color, color_asked))
	{
		free(color_asked);
		return (0);
	}
	free(color_asked);
	if (format[len] == '}')
		return (len + 1);
	else
		return (0);
}

int				add_color(char **format)
{
	int			len;

	if ((len = check_color("black", *format)))
		ft_putstr("\033[30m");
	else if ((len = check_color("red", *format)))
		ft_putstr("\033[31m");
	else if ((len = check_color("green", *format)))
		ft_putstr("\033[32m");
	else if ((len = check_color("yellow", *format)))
		ft_putstr("\033[33m");
	else if ((len = check_color("blue", *format)))
		ft_putstr("\033[34m");
	else if ((len = check_color("magenta", *format)))
		ft_putstr("\033[35m");
	else if ((len = check_color("cyan", *format)))
		ft_putstr("\033[36m");
	else if ((len = check_color("eoc", *format)))
		ft_putstr("\033[0m");
	else
		return (len = 0);
	(*format) += len;
	return (1);
}
