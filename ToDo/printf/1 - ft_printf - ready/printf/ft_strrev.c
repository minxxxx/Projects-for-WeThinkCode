/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 07:58:06 by sasiedu           #+#    #+#             */
/*   Updated: 2016/05/24 08:14:44 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrev(char **s)
{
	int		i;
	int		j;
	char	*temp;

	temp = ft_strnew(ft_strlen(*s));
	ft_strncpy(temp, *s, ft_strlen(*s));
	i = 0;
	j = ft_strlen(temp) - 1;
	while (j >= 0)
	{
		(*s)[i] = temp[j];
		j--;
		i++;
	}
	(*s)[i] = '\0';
	return (*s);
}
