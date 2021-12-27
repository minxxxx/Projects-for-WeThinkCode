/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thendric <thendric@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:37:19 by thendric          #+#    #+#             */
/*   Updated: 2016/11/06 23:37:10 by thendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_touppercase(void *str)
{
	char	*upper;

	upper = (char *)str;
	while (*upper)
	{
		if (*upper >= 'a' && *upper <= 'z')
			*upper -= 32;
		upper++;
	}
}
