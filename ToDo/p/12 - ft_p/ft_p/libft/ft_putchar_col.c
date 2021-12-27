/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_col.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 11:45:00 by wide-aze          #+#    #+#             */
/*   Updated: 2015/06/05 22:49:25 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>

void	ft_putchar_col(char c, int color)
{
	write(1, "\033[", 7);
	ft_putnbr(color);
	write(1, "m", 1);
	write(1, &c, 1);
	write(1, "\033[0m", 7);
}
