/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des_s_boxes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:31:21 by jcamhi            #+#    #+#             */
/*   Updated: 2018/11/12 17:31:21 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

static const int	*get_s_box(size_t i)
{
	if (i == 0)
		return (g_des_one);
	else if (i == 1)
		return (g_des_two);
	else if (i == 2)
		return (g_des_three);
	else if (i == 3)
		return (g_des_four);
	else if (i == 4)
		return (g_des_five);
	else if (i == 5)
		return (g_des_six);
	else if (i == 6)
		return (g_des_seven);
	else if (i == 7)
		return (g_des_eight);
	else
		return (NULL);
}

uint8_t				compute_s_box(uint8_t in, size_t i)
{
	const int	*s_box;
	uint8_t		row;
	uint8_t		col;
	uint8_t		out;

	s_box = get_s_box(i);
	row = ((in & 0x20) >> 4) | (in & 1);
	col = (in & 0x1E) >> 1;
	out = s_box[row * 16 + col];
	return (out);
}
