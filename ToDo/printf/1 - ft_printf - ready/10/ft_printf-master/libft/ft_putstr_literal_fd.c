/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_literal_fd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 15:26:08 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/31 16:02:46 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			print_literal(char c, int fd)
{
	if (c == '\n')
		ft_putstr_fd("\\n", fd);
	else if (c == '\t')
		ft_putstr_fd("\\t", fd);
	else
		ft_putchar_fd(c, fd);
}

void				ft_putstr_literal_fd(char const *source
											, int file_descriptor)
{
	while (*source)
	{
		print_literal(*source, file_descriptor);
		source++;
	}
}
