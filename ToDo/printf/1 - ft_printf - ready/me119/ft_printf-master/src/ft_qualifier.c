/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qualifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 12:04:02 by opodolia          #+#    #+#             */
/*   Updated: 2017/03/08 17:33:15 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_qualifier(char c, t_mods *mods)
{
	if (c == 'D' || c == 'C' || c == 'O' || c == 'U' || c == 'S')
	{
		mods->length = l;
		c += 32;
	}
	if (c == 'p')
	{
		mods->length = l;
		mods->flags.hash = yes;
	}
	mods->qualifier = c;
	return (1);
}
