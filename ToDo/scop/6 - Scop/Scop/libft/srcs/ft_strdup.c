/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 10:38:39 by ggroener          #+#    #+#             */
/*   Updated: 2016/05/21 11:43:06 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		i;

	i = 0;
	dup = ft_strnew(ft_strlen((char *)s1));
	while (s1[i] != '\0')
	{
		dup[i] = s1[i];
		i++;
	}
	return (dup);
}
