/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:38:23 by opodolia          #+#    #+#             */
/*   Updated: 2016/12/10 12:55:51 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;

	if (s)
	{
		i = 0;
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
		if (ft_strlen(s) == i)
			return (ft_strnew(0));
		j = ft_strlen(s) - 1;
		while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
			j--;
		return (ft_strsub(s, i, j - i + 1));
	}
	return (0);
}
