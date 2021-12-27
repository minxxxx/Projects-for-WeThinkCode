/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multi_strjoin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 06:18:04 by fkoehler          #+#    #+#             */
/*   Updated: 2016/08/26 23:35:30 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_str(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

static int		ft_str_cpy(char *dst, char *src, int i)
{
	int	j;

	j = 0;
	while (src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	return (i);
}

char			*ft_multi_strjoin(char **array, char *delimiter)
{
	int		i;
	int		j;
	size_t	len;
	char	*sjoin;

	i = 0;
	j = 0;
	len = ft_multi_strlen(array) +
	((ft_count_str(array) - 1) * ft_strlen(delimiter));
	if (!(sjoin = ft_strnew(len)))
		return (NULL);
	len = ft_count_str(array) - 1;
	while (array[i])
	{
		j = ft_str_cpy(sjoin, array[i], j);
		if (len--)
			j = ft_str_cpy(sjoin, delimiter, j);
		i++;
	}
	sjoin[j] = 0;
	return (sjoin);
}
