/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrn_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 17:28:28 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/31 15:58:23 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putstrn_fd(char const *source, size_t max_length
								, int file_descriptor)
{
	size_t		length;

	length = ft_strlen(source);
	if (max_length < length)
		length = max_length;
	write(file_descriptor, source, length);
}
