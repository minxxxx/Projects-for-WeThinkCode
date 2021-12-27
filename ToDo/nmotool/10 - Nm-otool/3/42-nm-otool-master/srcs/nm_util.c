/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtranchi <jtranchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 15:44:40 by jtranchi          #+#    #+#             */
/*   Updated: 2018/02/26 22:54:57 by jtranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/nm.h"

int					reverse_endian(int x)
{
	x = ((x << 8) & 0xFF00FF00) | ((x >> 8) & 0xFF00FF);
	return (x << 16) | (x >> 16);
}

int					error(char *file, char *str)
{
	ft_putstr_fd("./ft_otool: ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(str, 2);
	return (EXIT_FAILURE);
}

static	size_t		nbrlen(unsigned long long n)
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
		(boo) ? (ft_putstr("                ")) : ft_putstr("        ");
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

int					print_usage(char **argv)
{
	ft_putstr_fd("usage : ", 2);
	ft_putstr_fd(argv[0], 2);
	ft_putendl_fd(" [file]", 2);
	return (EXIT_FAILURE);
}
