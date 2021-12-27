/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 15:25:44 by apakhomo          #+#    #+#             */
/*   Updated: 2017/11/11 15:25:45 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_sqrt(int nb)
{
	int temp;

	if (nb < 1)
		return (0);
	else
	{
		temp = 1;
		while (temp * temp < nb)
			temp++;
		if (temp * temp == nb)
			return (temp);
		else
			return (0);
	}
}
