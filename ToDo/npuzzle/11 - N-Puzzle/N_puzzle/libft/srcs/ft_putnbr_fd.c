/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 10:53:25 by ggroener          #+#    #+#             */
/*   Updated: 2016/05/13 17:11:57 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		backward_nb;

	backward_nb = 0;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	while (n > 10)
	{
		backward_nb *= 10;
		backward_nb += n % 10;
		n /= 10;
	}
	while (backward_nb > 0)
	{
		ft_putchar_fd('0' + (backward_nb % 10), fd);
		backward_nb /= 10;
	}
}
