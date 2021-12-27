/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_large_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 16:00:48 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/31 16:00:52 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putnbr_large_fd(intmax_t number, int file_descriptor)
{
	char	*string;

	string = ft_itoa_large(number);
	ft_putstr_fd(string, file_descriptor);
	free(string);
}
