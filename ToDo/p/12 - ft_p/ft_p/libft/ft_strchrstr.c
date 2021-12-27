/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:15:57 by wide-aze          #+#    #+#             */
/*   Updated: 2015/06/14 10:06:30 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strchrstr(const char *s, char *tosearch)
{
	int		i;
	size_t	lentosearch;

	if (!(lentosearch = ft_strlen(tosearch)))
		return ((char*)&s[(int)ft_strlen(s)]);
	i = 0;
	while (s[i] && ft_strlen(&s[i]) >= lentosearch)
	{
		if (!ft_strncmp(&s[i], tosearch, lentosearch))
			return ((char*)&s[i]);
		i++;
	}
	return (NULL);
}
