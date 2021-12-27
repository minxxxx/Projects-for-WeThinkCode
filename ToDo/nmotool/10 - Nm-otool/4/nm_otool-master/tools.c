/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 14:56:32 by sasiedu           #+#    #+#             */
/*   Updated: 2017/06/26 11:18:37 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

void		ft_print_nbr_base(long int nbr, int base)
{
	static	char	*str = "0123456789abcdefg";

	if (nbr < 0 && base == 10)
		write(1, "-", 1);
	if (nbr < 0)
		nbr *= -1;
	if (nbr >= base)
		ft_print_nbr_base(nbr / base, base);
	write(1, &str[nbr % base], 1);
}

void		my_print_hex(unsigned int num, int size)
{
	static char		*str = "0123456789abcdefg";

	if (size > 1)
		my_print_hex(num >> 4, size - 1);
	write(1, &str[num % 16], 1);
}

void		my_print_memory(void *src, size_t size)
{
	size_t			i;
	unsigned char	*buf;

	buf = (unsigned char *)src;
	i = 0;
	while (i < size)
	{
		if (i > 0 && i % 8 == 0)
			write(1, " ", 1);
		if (i > 0 && i % 16 == 0)
			write(1, "\n", 1);
		my_print_hex((unsigned int)buf[i], 2);
		write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
}
