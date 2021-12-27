/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 10:17:09 by sasiedu           #+#    #+#             */
/*   Updated: 2016/05/11 10:39:33 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t		a;
	size_t		b;
	size_t		i;
	char		*str;

	b = ft_strlen(s) - 1;
	if (s[0] != ' ' && s[0] != ',' && s[0] != '\n' && s[0] != '\t')
	{
		if (s[b] != ' ' && s[b] != ',' && s[b] != '\n' && s[b] != '\t')
			return (ft_strcpy(str = ft_strnew(ft_strlen(s)), s));
	}
	a = 0;
	while (s[a] == ' ' || s[a] == ',' || s[a] == '\n' || s[a] == '\t')
		a++;
	while (s[b] == ' ' || s[b] == ',' || s[b] == '\n' || s[b] == '\t')
		b--;
	str = ft_strnew((b - a) + 1);
	i = 0;
	while (a <= b)
	{
		str[i] = s[a];
		a++;
		i++;
	}
	return (str);
}
