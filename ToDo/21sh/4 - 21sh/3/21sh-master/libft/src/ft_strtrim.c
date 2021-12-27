/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 15:28:24 by fkoehler          #+#    #+#             */
/*   Updated: 2015/11/30 18:49:23 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*dst;

	i = 0;
	if (!s)
		return (NULL);
	j = ft_strlen(s) - 1;
	while (i <= j && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	while (j >= i && (s[j] == ' ' || s[j] == '\n' || s[j] == '\t'))
		j--;
	len = j - i + 1;
	dst = ft_strsub(s, i, len);
	return (dst);
}
