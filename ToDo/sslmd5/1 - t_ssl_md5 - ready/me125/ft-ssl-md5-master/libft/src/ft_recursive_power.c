/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 16:01:05 by apakhomo          #+#    #+#             */
/*   Updated: 2017/11/11 16:01:06 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_power(int nb, int power)
{
	int a;

	a = 1;
	if (power < 0)
		return (0);
	if (power > 0)
		a = nb * ft_recursive_power(nb, power - 1);
	return (a);
}
