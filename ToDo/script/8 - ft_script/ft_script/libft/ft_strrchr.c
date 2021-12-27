/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 11:52:24 by wide-aze          #+#    #+#             */
/*   Updated: 2014/11/09 08:59:32 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		last_position;

	i = 0;
	last_position = -1;
	while (s[i])
	{
		if (s[i] == (char)c)
			last_position = i;
		i++;
	}
	if (s[i] == (char)c)
		last_position = i;
	if (last_position != -1)
		return ((char*)&s[last_position]);
	return (NULL);
}
