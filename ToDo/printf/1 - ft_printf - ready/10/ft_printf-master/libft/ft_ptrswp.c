/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrswp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/04 17:58:03 by tfleming          #+#    #+#             */
/*   Updated: 2014/12/04 17:58:20 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_ptrswp(void **first, void **second)
{
	void		*temporary;

	temporary = *second;
	*second = *first;
	*first = temporary;
}
