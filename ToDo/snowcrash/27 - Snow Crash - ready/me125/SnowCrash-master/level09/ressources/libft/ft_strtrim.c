/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 14:41:06 by dgalide           #+#    #+#             */
/*   Updated: 2016/02/01 05:15:24 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strtrim(const char *s)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	if (!s)
		return (NULL);
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i])
		i++;
	j = i;
	i = (ft_strlen((char *)s) - 1);
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i])
		i--;
	i += 1;
	if (i < j)
	{
		str = ft_strnew(0);
		return (str);
	}
	else
	{
		str = ft_strsub(s, j, (i - j));
		return (str);
	}
}
