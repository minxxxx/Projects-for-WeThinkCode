/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <dgalide@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 15:46:10 by dgalide           #+#    #+#             */
/*   Updated: 2018/03/20 15:44:12 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void			ft_tab_del(char **tab)
{
	size_t		i;

	if (!tab)
		return ;
	i = -1;
	while (++i < ft_strlen(*tab))
		ft_strdel(&(tab[i]));
	free(tab);
}
