/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <dgalide@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 15:46:10 by dgalide           #+#    #+#             */
/*   Updated: 2018/03/20 15:44:48 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char			**ft_tab_join(char **t1, char **t2, int b1, int b2)
{
	char		**output;
	size_t		i;
	size_t		j;

	if (!t1 || !t2)
		return (NULL);
	if (!(output = (char **)malloc(sizeof(char *) *
		(ft_tablen(t1) + ft_tablen(t2) + 1))))
		return (NULL);
	i = -1;
	j = -1;
	while (++j < ft_tablen(t1))
		output[j] = ft_strdup(t1[j]);
	while (++i < ft_tablen(t2))
		output[j++] = ft_strdup(t2[i]);
	output[j] = NULL;
	if (b1)
		ft_tab_del(t1);
	if (b2)
		ft_tab_del(t2);
	return (output);
}
