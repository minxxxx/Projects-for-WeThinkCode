/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_playerbegin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 15:36:55 by thou              #+#    #+#             */
/*   Updated: 2017/12/17 12:03:35 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_puissance4.h"

int	ft_playerbegin(void)
{
	int	random;

	srand(time(NULL));
	random = (rand() % 2);
	if (random)
		return (0);
	else
		return (1);
}
