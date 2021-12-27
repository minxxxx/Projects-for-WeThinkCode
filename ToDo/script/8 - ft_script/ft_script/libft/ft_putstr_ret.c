/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_ret.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 08:21:24 by wide-aze          #+#    #+#             */
/*   Updated: 2015/11/06 22:54:31 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_putstr_ret(const char *msg, int toreturn)
{
	if (msg)
		ft_putstr(msg);
	return (toreturn);
}
