/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 20:52:43 by sasiedu           #+#    #+#             */
/*   Updated: 2016/07/25 12:21:28 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_num(int nbr, int base)
{
	size_t		count;
	long int	num;

	count = 0;
	num = nbr;
	if (nbr == 0)
		return (0);
	if (num < 0 && base == 10)
		count++;
	while (num != 0)
	{
		count++;
		num = num / base;
	}
	return (count);
}

char			*ft_itoa_base(int nbr, int base)
{
	static char		*str = "0123456789abcdefghijklmnopqrstuvwxyz";
	size_t			count;
	long int		num;
	char			*hold;

	if (nbr == 0 || base < 2)
		return ("0");
	num = nbr;
	count = ft_count_num(num, base);
	if ((hold = (char *)malloc(sizeof(char) * (count + 1))) == NULL)
		return (NULL);
	hold[count] = '\0';
	if (num < 0 && base == 10)
		hold[0] = '-';
	if (num < 0)
		num = num * -1;
	while (num != 0)
	{
		hold[count - 1] = str[ft_abs(num % base)];
		num = num / base;
		count--;
	}
	return (hold);
}
