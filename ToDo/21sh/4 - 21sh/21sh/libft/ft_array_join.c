/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_join.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 17:21:38 by sasiedu           #+#    #+#             */
/*   Updated: 2016/08/04 17:41:42 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_array_join(char **tab, char *line)
{
	size_t	size;
	size_t	i;
	char	**new;

	size = ft_array_size(tab);
	if ((new = (char **)malloc(sizeof(char *) * size + 2)) == NULL)
		return (NULL);
	i = 0;
	while (tab != NULL && tab[i] != NULL)
	{
		new[i] = ft_strnew(ft_strlen(tab[i]));
		ft_memcpy(new[i], tab[i], ft_strlen(tab[i]));
		i++;
	}
	new[i] = ft_strnew(ft_strlen(line));
	ft_memcpy(new[i], line, ft_strlen(line));
	new[i + 1] = NULL;
	return (new);
}
