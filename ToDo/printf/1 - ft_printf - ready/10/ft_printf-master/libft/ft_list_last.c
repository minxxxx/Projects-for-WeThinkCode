/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/10 16:25:11 by tfleming          #+#    #+#             */
/*   Updated: 2014/09/10 16:40:15 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_list_last(t_list *begin_list)
{
	if (begin_list->next == NULL)
		return (begin_list);
	return (ft_list_last(begin_list->next));
}
