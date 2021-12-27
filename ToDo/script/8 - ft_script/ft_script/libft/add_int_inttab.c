/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_int_inttab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 08:18:35 by wide-aze          #+#    #+#             */
/*   Updated: 2015/06/18 14:02:02 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		*add_int_inttab(int *tab, int toadd, int size)
{
	int	*newtab;
	int	i;

	newtab = (int*)v_malloc(sizeof(int) * (size + 1));
	i = 0;
	while (i < size)
	{
		newtab[i] = tab[i];
		i++;
	}
	newtab[i] = toadd;
	ft_free(tab);
	return (newtab);
}
