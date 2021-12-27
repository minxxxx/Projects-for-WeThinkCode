/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 16:33:25 by telain            #+#    #+#             */
/*   Updated: 2015/12/17 17:39:18 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*new;

	i = 0;
	if (!(new = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[i])
	{
		new[i] = f(s[i]);
		i++;
	}
	return (new);
}
