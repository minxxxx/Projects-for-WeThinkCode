/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprevot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 21:35:45 by mprevot           #+#    #+#             */
/*   Updated: 2018/02/16 21:35:47 by mprevot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int		ft_putchar2(int c)
{
	write(1, &c, 1);
	return (0);
}
