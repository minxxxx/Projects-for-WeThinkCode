/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfavero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 13:30:34 by cfavero           #+#    #+#             */
/*   Updated: 2017/11/20 17:49:43 by cfavero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*s2;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (!(s2 = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[i])
	{
		s2[i] = f(s[i]);
		i++;
	}
	return (s2);
}
