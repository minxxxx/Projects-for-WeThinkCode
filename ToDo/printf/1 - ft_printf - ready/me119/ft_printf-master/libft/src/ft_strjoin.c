/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 14:48:08 by opodolia          #+#    #+#             */
/*   Updated: 2016/12/10 12:07:18 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *str;

	if (s1 && s2)
		if ((str = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		{
			ft_strcat(str, s1);
			ft_strcat(&str[ft_strlen(s1)], s2);
			return (str);
		}
	return (0);
}
