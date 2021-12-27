/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_strtabnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 17:50:33 by wide-aze          #+#    #+#             */
/*   Updated: 2015/02/21 17:53:26 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	**v_strtabnew(size_t size)
{
	char	**new;
	int		i;

	if (size == (size_t)-1)
		ft_exit("Malloc error");
	new = v_malloc(size + 1);
	i = -1;
	while (++i < (int)size)
		new[i] = NULL;
	return (new);
}
