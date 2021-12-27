/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 10:38:33 by wide-aze          #+#    #+#             */
/*   Updated: 2015/03/01 10:38:39 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

t_bool			is_power(int nb, int p)
{
	int				tmp;

	tmp = 1;
	while (tmp < nb)
		tmp *= p;
	if (nb == tmp)
		return (true);
	return (false);
}
