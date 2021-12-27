/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 15:16:29 by pmartine          #+#    #+#             */
/*   Updated: 2015/12/01 14:27:42 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t a;
	size_t to_keep;
	size_t i;

	a = 0;
	while (s[a] == ' ' || s[a] == '\n' || s[a] == '\t')
		a++;
	to_keep = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
		{
			i++;
			to_keep = i;
		}
		else
			i++;
	}
	if (s && to_keep == 0)
		return (ft_strdup(""));
	return (ft_strsub(s, a, (to_keep - a)));
}
