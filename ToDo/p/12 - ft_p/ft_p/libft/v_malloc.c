/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_malloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 08:24:49 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/31 08:28:45 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*v_malloc(size_t size)
{
	void	*new;

	new = ft_malloc(size);
	if (!new || size == 0)
		ft_exit("Malloc error");
	return (new);
}
