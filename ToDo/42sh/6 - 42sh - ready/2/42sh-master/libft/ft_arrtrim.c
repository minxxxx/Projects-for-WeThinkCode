/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadenho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 02:04:32 by jbadenho          #+#    #+#             */
/*   Updated: 2017/11/24 02:04:36 by jbadenho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arrtrim(char **arr)
{
	char	**trimmed;
	int		i;
	char	*tmp;

	i = ft_arraylen(arr);
	trimmed = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (arr[i])
	{
		tmp = ft_strtrim(arr[i]);
		trimmed[i] = ft_strdup(tmp);
		ft_strdel(&tmp);
		i++;
	}
	trimmed[i] = NULL;
	ft_delarray(arr);
	return (trimmed);
}
