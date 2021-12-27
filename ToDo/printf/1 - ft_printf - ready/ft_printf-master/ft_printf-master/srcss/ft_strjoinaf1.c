/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinaf1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 09:47:16 by jcamhi            #+#    #+#             */
/*   Updated: 2016/02/01 09:47:33 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ft_printf.h>

char	*ft_strjoinaf1(char *s1, const char *s2)
{
	int		i;
	size_t	len;
	char	*res;

	if (!s1 && s2)
		return (ft_strdup(s2));
	if (!s2 && s1)
		return (ft_strdup(s1));
	if (!s1 && !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = (char*)malloc(len * sizeof(char));
	if (!res)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		res[i] = s1[i];
	len = i;
	i = -1;
	while (s2[++i] != '\0')
		res[len + i] = s2[i];
	res[len + i] = '\0';
	free(s1);
	return (res);
}
