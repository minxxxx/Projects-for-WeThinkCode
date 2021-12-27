/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 15:47:44 by dgalide           #+#    #+#             */
/*   Updated: 2016/03/04 21:52:21 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	int		i;
	int		j;

	str = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	return (str);
}

char		*ft_strjoin_free(char **s1, char **s2, int bool_s1, int bool_s2)
{
	char	*str;
	int		i;
	int		j;

	str = ft_strnew(ft_strlen(*s1) + ft_strlen(*s2));
	i = 0;
	j = 0;
	while ((*s1) && (*s1)[i])
	{
		str[i] = (*s1)[i];
		i++;
	}
	if ((*s1) && bool_s1)
		ft_memdel((void **)s1);
	while ((*s2) && (*s2)[j])
	{
		str[i] = (*s2)[j];
		j++;
		i++;
	}
	if ((*s2) && bool_s2)
		ft_memdel((void **)s2);
	return (str);
}
