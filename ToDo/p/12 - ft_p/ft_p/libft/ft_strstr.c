/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 08:45:20 by wide-aze          #+#    #+#             */
/*   Updated: 2014/11/07 11:03:56 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	int		len_s2;

	len_s2 = ft_strlen(s2);
	if (len_s2 == 0)
		return ((char*)s1);
	while (*s1)
	{
		if (ft_strncmp (s1, s2, len_s2) == 0)
			return ((char*)s1);
		else
			s1++;
	}
	return (NULL);
}
