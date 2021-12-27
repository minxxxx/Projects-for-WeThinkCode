/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 21:27:11 by sasiedu           #+#    #+#             */
/*   Updated: 2016/07/23 22:15:47 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base_fd(int fd, int nbr, int base)
{
	static char		*str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	long int		num;

	num = nbr;
	if (num < 0 && base == 10)
		ft_putchar_fd('-', fd);
	if (num < 0)
		num = num * -1;
	if (num >= base)
		ft_putnbr_base_fd(fd, num / base, base);
	write(fd, &str[num % base], 1);
}

void	ft_putnbr_base(int nbr, int base)
{
	ft_putnbr_base_fd(1, nbr, base);
}
