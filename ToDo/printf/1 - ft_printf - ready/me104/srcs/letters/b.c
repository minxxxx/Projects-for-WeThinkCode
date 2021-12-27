/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:18:40 by juspende          #+#    #+#             */
/*   Updated: 2017/12/06 10:25:22 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

static void	put_color(char *str)
{
	write(1, str, ft_strlen(str));
}

static int	parse_color(int color)
{
	if (color == 0)
		put_color(DEFAULT);
	else if (color == 1)
		put_color(BLACK);
	else if (color == 2)
		put_color(RED);
	else if (color == 3)
		put_color(GREEN);
	else if (color == 4)
		put_color(YELLOW);
	else if (color == 5)
		put_color(BLUE);
	else if (color == 6)
		put_color(MAGENTA);
	else if (color == 7)
		put_color(CYAN);
	else if (color == 8)
		put_color(WHITE);
	else if (color == 9)
		put_color(PERSONNALIZED);
	return (0);
}

int			b(va_list argp, const char *arg, int *index, t_flag *flag)
{
	int		tmp;

	(void)argp;
	(void)index;
	(void)flag;
	if (BONUS)
	{
		empty_buffer(flag);
		tmp = ft_atoi(&arg[1]);
		*index += int_len(tmp);
		if ((tmp > 10 || tmp < 0) && ft_putsterr(COLOR_ERROR))
			return (ft_putsterr(COLOR_ERROR2));
		else
			flag->color = tmp;
		parse_color(tmp);
		return (ERROR);
	}
	if (flag->larg)
		*index = *index + int_len(flag->larg) - 1;
	flag->larg = -1;
	larg_flag_before(flag);
	ft_putchar(arg[0], flag);
	larg_flag_after(flag);
	return (ERROR);
}
