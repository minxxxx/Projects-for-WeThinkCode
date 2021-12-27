/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 12:33:27 by tfleming          #+#    #+#             */
/*   Updated: 2014/11/09 19:00:30 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_strncmp(const char *first, const char *second, size_t max)
{
	size_t		i;

	i = 0;
	while (i < max && first[i] && second[i] && first[i] == second[i])
		i++;
	if (i == max)
		return (0);
	return ((unsigned char)first[i] - (unsigned char)second[i]);
}
