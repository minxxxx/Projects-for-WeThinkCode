/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thendric <thendric@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 13:29:01 by thendric          #+#    #+#             */
/*   Updated: 2016/11/13 13:25:10 by thendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t len)
{
	char	*str;

	str = ft_strnew(len);
	if (str)
	{
		ft_memcpy(str, s1, len);
		str[len] = 0;
	}
	return (str);
}
