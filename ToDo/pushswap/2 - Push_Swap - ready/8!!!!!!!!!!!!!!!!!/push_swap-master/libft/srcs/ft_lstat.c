/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 16:18:12 by ljoly             #+#    #+#             */
/*   Updated: 2017/02/24 16:18:13 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstat(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;
	t_list			*tmp;

	tmp = begin_list;
	i = 0;
	while (tmp->next && i != nbr)
	{
		tmp = tmp->next;
		i++;
	}
	return (tmp);
}
