/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_col.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/14 13:16:29 by wide-aze          #+#    #+#             */
/*   Updated: 2015/06/08 15:49:50 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putnbr_col(int n, int color)
{
	char	*tmp;

	tmp = ft_itoa(n);
	ft_putstr_col(tmp, color);
	ft_free(tmp);
}
