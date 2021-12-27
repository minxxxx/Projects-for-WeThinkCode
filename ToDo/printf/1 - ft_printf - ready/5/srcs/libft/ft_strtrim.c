/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thendric <thendric@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:50:16 by thendric          #+#    #+#             */
/*   Updated: 2016/11/06 23:36:19 by thendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_iswhitespace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	char	*start;
	char	*end;

	if (!s)
		return (0);
	start = (char *)s;
	end = ft_strchr(s, 0) - 1;
	while (ft_iswhitespace(*start))
		start++;
	while (ft_iswhitespace(*end) && end > start)
		end--;
	return (ft_strsub(start, 0, 1 + end - start));
}
