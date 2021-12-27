/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addequal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadenho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 01:59:49 by jbadenho          #+#    #+#             */
/*   Updated: 2017/11/24 02:00:16 by jbadenho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_addequal(char *s)
{
	int		len;
	int		i;
	char	*tmp;

	len = ft_strlen(s) + 1;
	tmp = (char *)malloc(sizeof(char) * len + 1);
	i = 0;
	while (s[i])
	{
		tmp[i] = s[i];
		i++;
	}
	tmp[i] = '=';
	tmp[i + 1] = '\0';
	ft_strdel(&s);
	s = ft_strdup(tmp);
	ft_strdel(&tmp);
	return (s);
}
