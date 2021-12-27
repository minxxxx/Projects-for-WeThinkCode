/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 15:35:02 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/12 12:51:28 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** old implementation: return (ft_memalloc(size + 1));
*/

char			*ft_strnew(size_t size)
{
	char		*string;

	string = malloc((size + 1) * sizeof(char));
	string[size] = '\0';
	return (string);
}
