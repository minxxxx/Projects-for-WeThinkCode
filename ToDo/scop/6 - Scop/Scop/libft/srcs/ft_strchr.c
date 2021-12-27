/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 12:57:08 by ggroener          #+#    #+#             */
/*   Updated: 2016/05/14 08:16:17 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		count;

	count = 0;
	while (*(s + count) != '\0' || (char)c == '\0')
	{
		if (*(s + count) == (char)c)
			return ((char *)&s[count]);
		count++;
	}
	return (NULL);
}
