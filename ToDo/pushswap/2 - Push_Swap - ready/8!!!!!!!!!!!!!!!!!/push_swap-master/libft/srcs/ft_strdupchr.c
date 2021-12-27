/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 16:24:29 by ljoly             #+#    #+#             */
/*   Updated: 2017/02/24 16:24:31 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdupchr(const char *s1, char c)
{
	size_t	i;
	char	*ret;

	i = 0;
	ret = (char*)malloc(sizeof(char) * (ft_strlenchr(s1, c) + 1));
	if (!ret)
		return (NULL);
	while (s1[i] && s1[i] != c)
	{
		ret[i] = s1[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
