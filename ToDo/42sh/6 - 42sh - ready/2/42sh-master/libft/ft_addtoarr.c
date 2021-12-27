/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addtoarr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadenho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 02:01:30 by jbadenho          #+#    #+#             */
/*   Updated: 2017/11/24 02:02:01 by jbadenho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 ** Add's given string to the end of the given array. and returns the new arr
*/

char	**ft_add_to_array(char **arr, char *str)
{
	int				len;
	int				i;
	char			**temp;

	i = 0;
	len = 0;
	len = ft_arraylen(arr);
	temp = (char **)ft_strnew(sizeof(char *) * (len + 1));
	while (arr[i] != NULL)
	{
		temp[i] = ft_strdup(arr[i]);
		i++;
	}
	temp[len] = ft_strdup(str);
	temp[len + 1] = NULL;
	ft_delarray(arr);
	return (temp);
}
