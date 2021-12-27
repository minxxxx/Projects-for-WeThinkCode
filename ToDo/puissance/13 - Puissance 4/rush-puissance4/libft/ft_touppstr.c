/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_touppstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 15:54:04 by pmartine          #+#    #+#             */
/*   Updated: 2015/12/03 15:54:08 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_touppstr(char *str)
{
	char	*tmp;
	int		i;

	tmp = (char *)malloc(sizeof(char) * ft_strlen(str));
	i = 0;
	while (str[i] != '\0')
	{
		tmp[i] = ft_toupper(str[i]);
		i++;
	}
	return (tmp);
}
