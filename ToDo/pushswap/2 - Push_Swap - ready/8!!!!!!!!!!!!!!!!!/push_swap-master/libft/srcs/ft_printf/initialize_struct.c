/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 20:16:17 by ljoly             #+#    #+#             */
/*   Updated: 2017/03/13 20:16:20 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_initialize_struct(t_info *info)
{
	SPEC = 0;
	ft_bzero(FLAGS, 7);
	WIDTH = 0;
	IS_PRECISION = 0;
	PRECISION = 0;
	MOD = NO_MOD;
	LEFT_Z = 0;
	LEFT_B = 0;
	RIGHT_B = 0;
	FILL_L = 0;
	FILL_R = 0;
	HEX_UPPER = 0;
}
