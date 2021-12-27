/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 15:07:53 by apakhomo          #+#    #+#             */
/*   Updated: 2017/11/11 15:07:53 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	size_t a;
	size_t b;
	size_t c;
	size_t t;

	if (!s)
		return (NULL);
	a = ft_strlen(s);
	b = 0;
	c = 0;
	while ((s[b] == ' ' || s[b] == '\n' || s[b] == '\t'))
		b++;
	if (a == b)
		return (ft_strsub(s, a, 1));
	t = a - 1;
	while ((s[t - c] == ' ' || s[t - c] == '\n' || s[t - c] == '\t'))
		c++;
	return (ft_strsub(s, b, a - b - c));
}
