/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 16:34:01 by wide-aze          #+#    #+#             */
/*   Updated: 2014/11/10 14:52:16 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int		ft_start(char const *s)
{
	int		i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	return (i);
}

static size_t	ft_end(char const *s)
{
	size_t		i;

	i = 0;
	while (s[i])
		i++;
	i--;
	while (i && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		i--;
	return (i + 1);
}

char			*ft_strtrim(char const *s)
{
	int		start;
	size_t	end;

	if (!s)
		return (NULL);
	start = ft_start(s);
	if ((unsigned int)start == ft_strlen(s))
		return (ft_strnew(0));
	end = ft_end(s);
	return (ft_strsub(s, (unsigned int)start, end - (unsigned int)start));
}
