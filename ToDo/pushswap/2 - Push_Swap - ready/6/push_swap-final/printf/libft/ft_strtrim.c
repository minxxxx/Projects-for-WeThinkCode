/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfavero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 14:33:40 by cfavero           #+#    #+#             */
/*   Updated: 2017/11/22 18:40:14 by cfavero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int			i;
	int			k;
	size_t		len;
	char		*str;

	i = 0;
	if (s == NULL)
		return (NULL);
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && (s[i]))
		i++;
	k = ft_strlen(s) - 1;
	while ((s[k] == ' ' || s[k] == '\n' || s[k] == '\t') && (i < k))
		k--;
	len = k - i + 1;
	str = ft_strsub(s, i, len);
	return (str);
}
