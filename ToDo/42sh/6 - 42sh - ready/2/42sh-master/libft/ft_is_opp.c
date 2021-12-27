/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_opp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadenho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 02:10:34 by jbadenho          #+#    #+#             */
/*   Updated: 2017/11/24 02:10:38 by jbadenho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_opp(char *s)
{
	int		len;

	len = ft_strlen(s);
	if (len != 1)
		return (0);
	if (*s == '+')
		return (1);
	else if (*s == '-')
		return (1);
	else if (*s == '/')
		return (1);
	else if (*s == '%')
		return (1);
	else if (*s == '*')
		return (1);
	else
		return (0);
}
