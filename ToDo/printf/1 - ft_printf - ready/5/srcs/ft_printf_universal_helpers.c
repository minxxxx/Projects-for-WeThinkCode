/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_universal_helpers.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thendric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 11:51:30 by thendric          #+#    #+#             */
/*   Updated: 2017/01/19 12:46:56 by thendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long 	ft_vartype_u(t_input *input)
{
	int				i;
	unsigned int	num_ui;
	unsigned long	num_ul;
	int				is_l;
	int				is_h;
	int				is_z;

	i = 0;
	is_l = 0;
	is_h = 0;
	is_z = 0;
	while (input->flags[i])
	{
		if (input->flags[i] == 'l' || input->flags[i] == 'j')
			is_l++;
		if (input->flags[i] == 'h')
			is_h++;
		if (input->flags[i] == 'z')
			is_z++;
		i++;
	}
	if (is_l || is_h || is_z || input->c == 'U')
	{
		num_ul = (unsigned long)input->var;
		return (num_ul);
	}
	else
		num_ui = (unsigned int)input->var;
	return (num_ui);
}

long	ft_vartype(t_input *input)
{
	int				i;
	int				num;
	long			num_long;
	short			num_short;
	signed char		char_signed;
	ssize_t			num_sizet;
	int				is_l;
	int				is_h;
	int				is_z;

	i = 0;
	is_l = 0;
	is_h = 0;
	is_z = 0;
	while (input->flags[i])
	{
		if (input->flags[i] == 'l' || input->flags[i] == 'j' || input->flags[i] == 'z')
			input->islong++;
		if (input->flags[i] == 'l' || input->flags[i] == 'j')
			is_l++;
		if (input->flags[i] == 'h')
			is_h++;
		if (input->flags[i] == 'z')
			is_z++;
		i++;
	}
	if (is_l || input->c == 'D')
	{
		num_long = (long)input->var;
		return (num_long);
	}
	if (is_h == 1)
	{
		num_short = (short)input->var;
		return (num_short);
	}
	else if (is_h == 2)
	{
		char_signed = (signed char)input->var;
		return (char_signed);
	}
	else if (is_z)
	{
		num_sizet = (size_t)input->var;
		return (num_sizet);
	}
	else
		num = (int)input->var;
	return (num);
}

char	ft_getconversion(char *str)
{
	int		i;

	i = 1;
	while (str[i])
	{
		if (ft_isconversion(str[i]))
			return (str[i]);
		i++;
	}
	return (' ');
}

int		ft_isflag(char c)
{
	if (c == '#' || c == '-' || c == '0')
	{
		return (1);
	}
	return (0);
}

int		ft_isconversion(char c)
{
	if (c == 'd' || c == 'i' || c == 's' || c == 'c'
			|| c == '%' || c == 'f' || c == 'o' || c == 'x'
			|| c == 'u' || c == 'O' || c == 'X' || c == 'p'
			|| c == 'U' || c == 'D' || c == 'C' || c == 'S')
	{
		return (1);
	}
	return (0);
}
