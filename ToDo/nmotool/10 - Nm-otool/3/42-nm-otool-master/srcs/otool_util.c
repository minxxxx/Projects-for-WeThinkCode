/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtranchi <jtranchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 15:07:30 by jtranchi          #+#    #+#             */
/*   Updated: 2018/02/26 22:55:58 by jtranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/otool.h"

void				print_byte_to_hex(char byte)
{
	char			str[2];
	short			count;
	short			char_hex;
	unsigned char	cast;

	cast = (unsigned char)byte;
	count = -1;
	while (++count != 2)
	{
		char_hex = cast % 16;
		cast /= 16;
		if (char_hex < 10)
			str[count] = char_hex + '0';
		else
			str[count] = (char_hex % 10) + 'a';
	}
	ft_putchar(str[1]);
	ft_putchar(str[0]);
}

static size_t		nbrlen(unsigned long long n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

void				print_addr(unsigned long long n, int boo)
{
	char				str[nbrlen(n) + 1];
	size_t				len;

	len = nbrlen(n) - 1;
	if (n == 0)
	{
		(boo) ? (ft_putstr("0000000000000000")) : ft_putstr("00000000");
		return ;
	}
	str[len + 1] = '\0';
	while (n)
	{
		str[len] = (16 > 10 && n % 16 > 9) ?
			(n % 16) + ('a' - 10) : (n % 16) + 48;
		n /= 16;
		len--;
	}
	len = -1;
	if (boo)
		while (++len + ft_strlen(str) < 16)
			ft_putchar('0');
	else
		while (++len + ft_strlen(str) < 8)
			ft_putchar('0');
	ft_putstr(str);
}

int					error(char *file, char *str)
{
	ft_putstr("./ft_otool: ");
	ft_putstr(file);
	ft_putstr(": ");
	ft_putendl(str);
	return (EXIT_FAILURE);
}

int					print_usage(char **argv)
{
	ft_putstr_fd("usage : ", 2);
	ft_putstr_fd(argv[0], 2);
	ft_putendl_fd(" [file]", 2);
	return (EXIT_FAILURE);
}
