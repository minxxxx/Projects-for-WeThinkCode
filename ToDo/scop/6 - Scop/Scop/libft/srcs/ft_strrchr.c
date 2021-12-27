/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 13:21:21 by ggroener          #+#    #+#             */
/*   Updated: 2016/05/14 08:17:12 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		count;
	char	*last;

	count = 0;
	last = NULL;
	if ((char)c == '\0')
		return ((char *)(s + ft_strlen(s)));
	while (*(s + count) != '\0')
	{
		if (*(s + count) == (char)c)
			last = (char *)(s + count);
		count++;
	}
	return (last);
}
