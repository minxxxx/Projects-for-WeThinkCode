/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_width_pad.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <dtedgui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 18:13:52 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/26 16:58:23 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_width_pad(int nbr_len, int width, char pad)
{
	while (nbr_len < width)
	{
		ft_putchar(pad);
		nbr_len++;
	}
}
