/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 12:25:19 by tfleming          #+#    #+#             */
/*   Updated: 2014/11/09 18:59:44 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_strcmp(const char *first, const char *second)
{
	while (*first && *second && *first == *second)
	{
		first++;
		second++;
	}
	return ((unsigned char)*first - (unsigned char)*second);
}
