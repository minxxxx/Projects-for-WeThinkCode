/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 16:33:37 by tfleming          #+#    #+#             */
/*   Updated: 2014/11/08 11:46:18 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strmap(char const *string, char (*func)(char))
{
	char	*new;
	size_t	i;

	new = malloc(sizeof(char) * ft_strlen(string));
	i = 0;
	while (string[i])
	{
		new[i] = func(string[i]);
		i++;
	}
	return (new);
}
