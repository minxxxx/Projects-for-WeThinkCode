/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_cpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <dgalide@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 15:46:10 by dgalide           #+#    #+#             */
/*   Updated: 2018/03/20 15:44:18 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char			**ft_tab_cpy(char **src, char **dst)
{
	int			i;
	int			length;

	if (!*src)
		return (NULL);
	i = -1;
	length = ft_tablen(src);
	dst = (char **)malloc(sizeof(char *) * length + 1);
	while (++i < length)
		dst[i] = ft_strdup(src[i]);
	dst[i] = NULL;
	return (dst);
}
