/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolowstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 15:53:38 by pmartine          #+#    #+#             */
/*   Updated: 2015/12/03 15:53:40 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_tolowstr(char *str)
{
	char	*tmp;
	int		i;

	tmp = (char *)malloc(sizeof(char) * ft_strlen(str));
	i = 0;
	while (str[i] != '\0')
	{
		tmp[i] = ft_tolower(str[i]);
		i++;
	}
	return (tmp);
}
