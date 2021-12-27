/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 10:08:33 by sasiedu           #+#    #+#             */
/*   Updated: 2016/05/23 09:50:13 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	str = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	ft_strncpy(str, s1, ft_strlen(s1));
	ft_strncat(str, s2, ft_strlen(s2));
	return (str);
}
