/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_printing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:31:40 by jcamhi            #+#    #+#             */
/*   Updated: 2018/11/12 17:31:40 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

int	print_str_and_ret(char *str1, char c)
{
	ft_putstr_fd(str1, 2);
	write(2, &c, 1);
	ft_putstr_fd("\n", 2);
	return (0);
}

int	print_error_and_help(char *wrong_opt)
{
	ft_putstr_fd("Unknown algorithm: ", 2);
	ft_putstr_fd(wrong_opt, 2);
	ft_putstr_fd("\n", 2);
	print_help();
	return (0);
}
