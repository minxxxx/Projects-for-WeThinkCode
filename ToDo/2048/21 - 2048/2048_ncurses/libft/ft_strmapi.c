/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/16 11:13:06 by glarivie          #+#    #+#             */
/*   Updated: 2015/12/29 14:53:54 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*ret;
	unsigned int		index;

	index = -1;
	if (s == NULL || f == NULL)
		return (NULL);
	if (!(ret = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[++index])
		ret[index] = (*f)(index, s[index]);
	ret[index] = '\0';
	return (ret);
}
