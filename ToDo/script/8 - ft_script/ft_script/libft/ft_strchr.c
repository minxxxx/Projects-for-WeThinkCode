/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:15:57 by wide-aze          #+#    #+#             */
/*   Updated: 2014/11/07 16:48:02 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if ((char)c == '\0')
		return ((char*)&s[(int)ft_strlen(s)]);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char*)&s[i]);
		i++;
	}
	return (NULL);
}
