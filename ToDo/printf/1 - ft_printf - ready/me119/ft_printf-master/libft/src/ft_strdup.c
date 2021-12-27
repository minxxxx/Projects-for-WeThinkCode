/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 19:35:55 by opodolia          #+#    #+#             */
/*   Updated: 2016/11/30 19:57:39 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *str;

	str = (char *)malloc(sizeof(*str) * ft_strlen(s1) + 1);
	if (str != 0)
		str = ft_strcpy(str, s1);
	return (str);
}
