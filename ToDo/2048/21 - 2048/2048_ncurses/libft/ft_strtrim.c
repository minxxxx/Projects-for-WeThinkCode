/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/18 18:28:06 by glarivie          #+#    #+#             */
/*   Updated: 2015/11/25 17:01:41 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	char			*ret;
	unsigned int	i;
	int				b;
	int				c;

	b = 0;
	i = 0;
	if (s == NULL)
		return (NULL);
	c = ft_strlen(s) - 1;
	if (!(ret = (char*)malloc(ft_strlen(s) + 1)))
		return (NULL);
	while (ft_isspace(s[i]))
		i++;
	if (s[i] == '\0')
		return (ft_strnew(1));
	while (s[b])
	{
		if (ft_isspace(s[c]) == 1)
			c--;
		b++;
	}
	c = c - i + 1;
	ret = ft_strsub(s, i, c);
	return (ret);
}
