/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 15:20:34 by jtranchi          #+#    #+#             */
/*   Updated: 2015/12/03 15:20:35 by jtranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strtrim(char const *s)
{
	char			*result;
	unsigned int	i;
	unsigned int	len;

	if (s)
	{
		len = ft_len_nospace(s);
		if (len > 0)
		{
			i = 0;
			result = ft_strnew(len);
			if (!result)
				return (NULL);
			while (s[i] && ft_isspace(s[i]))
				i++;
			if (!s[i])
				return (ft_strnew(0));
			ft_strncpy(result, &s[i], len);
			result[len] = '\0';
			return (result);
		}
		else
			return (ft_strnew(0));
	}
	return (NULL);
}
