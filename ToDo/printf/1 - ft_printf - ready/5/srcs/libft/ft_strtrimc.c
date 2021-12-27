/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thendric <thendric@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:50:16 by thendric          #+#    #+#             */
/*   Updated: 2016/11/13 13:25:35 by thendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ischar(char look, char find)
{
	if (look == find)
		return (1);
	return (0);
}

char		*ft_strtrimc(char const *s, char c)
{
	char	*start;
	char	*end;

	if (!s)
		return (0);
	start = (char *)s;
	end = ft_strchr(s, 0) - 1;
	while (ft_ischar(*start, c))
		start++;
	while (ft_ischar(*end, c) && end > start)
		end--;
	return (ft_strsub(start, 0, 1 + end - start));
}
