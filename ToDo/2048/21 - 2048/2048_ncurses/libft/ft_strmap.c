/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/16 11:13:06 by glarivie          #+#    #+#             */
/*   Updated: 2015/12/29 14:55:38 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ret;
	int		index;

	index = -1;
	if (s == NULL || f == NULL)
		return (NULL);
	if (!(ret = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[++index])
		ret[index] = (*f)(s[index]);
	ret[index] = '\0';
	return (ret);
}
