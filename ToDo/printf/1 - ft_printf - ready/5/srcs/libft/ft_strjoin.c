/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thendric <thendric@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:46:09 by thendric          #+#    #+#             */
/*   Updated: 2016/11/06 23:30:49 by thendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (!s1 || !s2)
		return (0);
	str = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str)
	{
		ft_strcpy(str, s1);
		ft_strcpy(str + ft_strlen(s1), s2);
	}
	return (str);
}
