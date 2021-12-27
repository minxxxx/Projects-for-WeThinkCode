/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 16:56:55 by thou              #+#    #+#             */
/*   Updated: 2017/03/30 18:20:44 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree2(char const *s1, char const *s2)
{
	char	*a;
	char	*b;
	char	*dst;

	a = (char*)s1;
	b = (char*)s2;
	if (!s1 || !s2)
		return (a);
	dst = ft_strjoin(s1, s2);
	free(a);
	free(b);
	return (dst);
}
