/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 16:16:52 by dkotenko          #+#    #+#             */
/*   Updated: 2017/11/12 17:03:53 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *str, int ch)
{
	char		*temp;

	temp = (char*)str;
	while (*temp)
	{
		if (*temp == ch)
			return (temp);
		temp++;
	}
	if (ch == '\0')
		return (temp);
	return (NULL);
}
