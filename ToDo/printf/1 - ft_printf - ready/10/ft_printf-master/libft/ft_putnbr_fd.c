/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 12:16:36 by tfleming          #+#    #+#             */
/*   Updated: 2014/11/08 19:28:40 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putnbr_fd(int number, int file_descriptor)
{
	char	*string;

	string = ft_itoa(number);
	ft_putstr_fd(string, file_descriptor);
	free(string);
}
