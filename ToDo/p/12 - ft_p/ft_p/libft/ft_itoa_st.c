/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_st.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 15:03:51 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/09 15:05:14 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include <string.h>

static int	ft_nb_digit(size_t n)
{
	int		i;

	if (n == 0)
		return (1);
	i = 0;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa_st(size_t n)
{
	int		nb_digit;
	char	*str;

	nb_digit = ft_nb_digit(n);
	str = ft_strnew(nb_digit);
	if (str == NULL)
		return (NULL);
	nb_digit--;
	while (nb_digit >= 0)
	{
		if (str[nb_digit] == '-')
			return (str);
		str[nb_digit] = (n % 10) + 48;
		n = n / 10;
		nb_digit--;
	}
	return (str);
}
