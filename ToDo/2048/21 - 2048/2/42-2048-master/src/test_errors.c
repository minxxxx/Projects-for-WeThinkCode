/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 18:20:59 by jfrancho          #+#    #+#             */
/*   Updated: 2016/01/31 19:54:24 by jfrancho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game_2048.h"

int			test_errors(void)
{
	int		win_val;

	win_val = WIN_VALUE;
	if (win_val < 16)
	{
		ft_putendl("Votre objectif est trop petit.");
		ft_putendl("Choisissez une puissance de 2 supérieure ou égale à 16.");
		return (0);
	}
	else if (win_val > 32768)
	{
		ft_putendl("Votre objectif est trop grand.");
		ft_putendl("Prenez une puissance de 2 inférieure ou égale à 32768.");
		return (0);
	}
	while (win_val % 2 == 0 && win_val > 2)
		win_val /= 2;
	if (win_val == 2)
		return (1);
	ft_putendl("Votre objectif n'est pas une puissance de 2.");
	return (0);
}
