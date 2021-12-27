/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_col_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:34:28 by wide-aze          #+#    #+#             */
/*   Updated: 2015/06/07 17:19:34 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putstr_col_fd(char const *s, int color, int fd)
{
	ft_putstr_fd("\033[", fd);
	ft_putnbr_fd(color, fd);
	ft_putchar_fd('m', fd);
	ft_putstr_fd(s, fd);
	ft_putstr_fd("\033[0m", fd);
}
