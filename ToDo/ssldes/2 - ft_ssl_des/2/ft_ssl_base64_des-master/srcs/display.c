/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 11:41:30 by jtranchi          #+#    #+#             */
/*   Updated: 2018/09/06 11:41:31 by jtranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

void	write_file_error(char *file, t_opt *opt)
{
	ft_putstr("ft_ssl: ");
	ft_putstr(HASH[opt->hash]);
	ft_putstr(": ");
	ft_putstr(file);
	ft_putendl(": No such file or directory");
}

void	write_prefix(t_opt *opt, t_arg *arg)
{
	if (ft_strequ(HASH[opt->hash], "md5") == 1)
		ft_putstr("MD5 (");
	if (ft_strequ(HASH[opt->hash], "sha256") == 1)
		ft_putstr("SHA256 (");
	(arg->is_string) ? (ft_putchar('"')) : 0;
	ft_putstr(arg->str);
	(arg->is_string) ? (ft_putchar('"')) : 0;
	ft_putstr(") = ");
}

void	write_suffix(t_arg *arg)
{
	ft_putchar(' ');
	(arg->is_string) ? (ft_putchar('"')) : 0;
	ft_putstr(arg->str);
	(arg->is_string) ? (ft_putchar('"')) : 0;
}
