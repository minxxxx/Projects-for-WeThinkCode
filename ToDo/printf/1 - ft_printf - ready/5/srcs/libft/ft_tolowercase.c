/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thendric <thendric@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:37:27 by thendric          #+#    #+#             */
/*   Updated: 2016/11/06 23:36:59 by thendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_tolowercase(void *str)
{
	char	*lower;

	lower = (char *)str;
	while (*lower)
	{
		if (*lower >= 'A' && *lower <= 'Z')
			*lower += 32;
		lower++;
	}
}
