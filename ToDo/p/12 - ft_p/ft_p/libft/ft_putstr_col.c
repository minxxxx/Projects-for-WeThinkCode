/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_col.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:34:28 by wide-aze          #+#    #+#             */
/*   Updated: 2015/06/05 22:49:38 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putstr_col(char const *s, int color)
{
	ft_putstr("\033[");
	ft_putnbr(color);
	ft_putchar('m');
	ft_putstr(s);
	ft_putstr("\033[0m");
}
