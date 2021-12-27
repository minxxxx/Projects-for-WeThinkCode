/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:56:31 by opodolia          #+#    #+#             */
/*   Updated: 2016/12/04 19:16:45 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *ret;

	ret = 0;
	if (*s == (char)c)
		ret = (char *)s;
	while (*s++)
		if (*s == (char)c)
			ret = (char *)s;
	return (ret);
}
