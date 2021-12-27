/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_randbool.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 12:18:24 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/01 16:38:02 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"
#include <stdlib.h>

t_bool			ft_randbool(double chance)
{
	double			r;

	r = rand();
	r /= RAND_MAX;
	if (r < chance)
		return (true);
	return (false);
}
