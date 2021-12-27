/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_bytes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 20:34:54 by fkoehler          #+#    #+#             */
/*   Updated: 2016/01/28 18:58:22 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_wchar_bytes(wchar_t c)
{
	unsigned int	n;

	n = (unsigned int)c;
	if (n < 128)
		return (1);
	else if (n < 2048)
		return (2);
	else if (n < 65536)
		return (3);
	else
		return (4);
}

int	count_wchar_string_bytes(wchar_t *s)
{
	int	i;
	int	nb_bytes;

	i = 0;
	nb_bytes = 0;
	while (s[i])
	{
		nb_bytes += count_wchar_bytes(s[i]);
		i++;
	}
	return (nb_bytes);
}
