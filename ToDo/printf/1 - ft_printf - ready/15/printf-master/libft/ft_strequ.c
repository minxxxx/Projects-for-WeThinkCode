/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuhn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 18:03:49 by fkuhn             #+#    #+#             */
/*   Updated: 2018/11/29 20:58:41 by fkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	int	comp;

	if (!s1 || !s2)
		return (0);
	comp = ft_strcmp(s1, s2);
	return (comp == 0);
}