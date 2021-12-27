/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 14:22:08 by ljoly             #+#    #+#             */
/*   Updated: 2017/07/06 16:20:14 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				ft_end(int status)
{
	if (status == 0 || status == 10)
	{
		if (status == 0)
			ft_putendl("OK");
		return (0);
	}
	if (status == 1)
		ft_putendl_fd("Error", 2);
	else if (status == 2)
	{
		ft_putendl("KO");
		return (0);
	}
	else if (status == 3)
		ft_putendl_fd("Error (read)", 2);
	else if (status == 4)
		ft_putendl_fd("Error (malloc)", 2);
	return (-1);
}
