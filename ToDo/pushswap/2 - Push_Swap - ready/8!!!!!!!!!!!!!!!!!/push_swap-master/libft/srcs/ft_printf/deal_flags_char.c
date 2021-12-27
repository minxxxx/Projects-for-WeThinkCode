/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_flags_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 20:14:19 by ljoly             #+#    #+#             */
/*   Updated: 2017/03/13 20:14:22 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_char_print_right(t_info *info)
{
	size_t	len;

	len = 0;
	if (RIGHT_B)
	{
		ft_print_blanks(RIGHT_B);
		len += RIGHT_B;
	}
	return (len);
}

size_t		ft_char_print_left(t_info *info)
{
	size_t	len;

	len = 0;
	if (LEFT_B > 0)
	{
		ft_print_blanks(LEFT_B);
		len += LEFT_B;
	}
	if (LEFT_Z > 0)
	{
		ft_print_zeros(LEFT_Z);
		len += LEFT_Z;
	}
	return (len);
}

void		ft_char_flags_right(int size, t_info *info)
{
	if (!MINUS)
		FILL_R = 0;
	else if (WIDTH > size)
		RIGHT_B = WIDTH - size;
}

void		ft_char_flags_left(int size, t_info *info)
{
	if (MINUS)
		FILL_L = 0;
	else
	{
		if (ZERO && WIDTH > size)
			LEFT_Z = WIDTH - size;
		else if (WIDTH > size)
			LEFT_B = WIDTH - size;
	}
}
