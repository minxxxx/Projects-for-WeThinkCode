/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 13:05:02 by apakhomo          #+#    #+#             */
/*   Updated: 2017/11/11 13:05:03 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char	*new;
	size_t	x;
	size_t	a;

	a = 0;
	x = 0;
	while (s1[a] != '\0')
		a++;
	new = (char*)malloc(sizeof(char) * (a + 1));
	if (new == NULL)
		return (NULL);
	while (s1[x] != '\0')
	{
		new[x] = s1[x];
		x++;
	}
	new[x] = '\0';
	return (new);
}
