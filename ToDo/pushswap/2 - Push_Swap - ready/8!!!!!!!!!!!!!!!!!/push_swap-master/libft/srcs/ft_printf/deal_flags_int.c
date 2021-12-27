/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_flags_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 20:14:48 by ljoly             #+#    #+#             */
/*   Updated: 2017/03/13 20:14:50 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_int_print_sign(ssize_t i, t_info *info)
{
	size_t		len;

	if (i < 0)
		ft_putchar('-');
	else if (PLUS)
		ft_putchar('+');
	else if (SPACE)
		ft_putchar(' ');
	len = 0;
	(i < 0 || PLUS || SPACE) ? ++len : len;
	return (len);
}

size_t			ft_int_print_right(t_info *info)
{
	size_t		len;

	len = 0;
	if (RIGHT_B > 0)
	{
		ft_print_blanks(RIGHT_B);
		len += RIGHT_B;
	}
	return (len);
}

size_t			ft_int_print_left(ssize_t i, t_info *info)
{
	size_t		len;

	len = 0;
	if (LEFT_B > 0)
	{
		ft_print_blanks(LEFT_B);
		len += LEFT_B;
	}
	len += ft_int_print_sign(i, info);
	if (LEFT_Z > 0)
	{
		len += LEFT_Z;
		ft_print_zeros(LEFT_Z);
	}
	return (len);
}

void			ft_int_flags_right(int size, t_info *info)
{
	if (WIDTH > 0 && FILL_L >= 0)
		FILL_R = WIDTH - size - FILL_L;
	else
		FILL_R = 0;
	RIGHT_B = FILL_R;
}

void			ft_int_flags_left(ssize_t i, int size, int precision,
		t_info *info)
{
	if (MINUS)
	{
		if (PLUS || SPACE || i < 0)
			FILL_L++;
	}
	else
	{
		if (PLUS || SPACE || i < 0)
		{
			FILL_L++;
			if (ZERO)
				LEFT_Z = WIDTH - size - 1;
			else if (WIDTH)
				LEFT_B = WIDTH - precision - size - 1;
		}
		else
		{
			if (ZERO && WIDTH && !IS_PRECISION)
				LEFT_Z = WIDTH - size;
			else if (WIDTH)
				LEFT_B = WIDTH - precision - size;
		}
	}
	FILL_L += LEFT_Z + LEFT_B;
}
