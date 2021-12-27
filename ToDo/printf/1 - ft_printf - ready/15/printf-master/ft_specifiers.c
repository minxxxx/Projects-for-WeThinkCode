/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifiers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuhn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 17:36:38 by artemiy           #+#    #+#             */
/*   Updated: 2019/01/08 20:09:41 by fkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

t_flags	*get_flags(char **spec)
{
	t_flags *flags;

	flags = init_flags();
	if (!flags)
		return (NULL);
	while ((**spec == ' ' || **spec == '-' || **spec == '0'
			|| **spec == '+' || **spec == '#') && **spec)
	{
		if (**spec == ' ')
			flags->space = 1;
		else if (**spec == '-')
			flags->minus = 1;
		else if (**spec == '+')
			flags->plus = 1;
		else if (**spec == '0')
			flags->zero = 1;
		else if (**spec == '#')
			flags->cage = 1;
		(*spec)++;
	}
	if (flags->minus)
		flags->zero = 0;
	if (flags->plus)
		flags->space = 0;
	return (flags);
}

int		get_width(char **fmt)
{
	int	width;

	width = ft_atoi(*fmt);
	while (ft_isdigit(**fmt) && **fmt)
		(*fmt)++;
	return (width);
}

int		get_precition(char **fmt)
{
	int	precition;

	if (**fmt == '.')
	{
		(*fmt)++;
		precition = ft_atoi(*fmt);
		while (ft_isdigit(**fmt))
			(*fmt)++;
		return (precition);
	}
	return (-1);
}

char	*get_length(char **fmt)
{
	char	*length;
	int 	l_len;

	l_len = get_length_len(*fmt);
	if (!(length = ft_strsub(*fmt, 0, l_len)))
		return (NULL);
	*fmt += l_len;
	return (length);
} 

t_specifier	*create_specifier(char **fmt)
{
	t_specifier	*sp;

	if (!(sp = (t_specifier *)malloc(sizeof(t_specifier))))
		handle_error(0, NULL);
	if (!(sp->flags = get_flags(fmt)))
		handle_error(0, &sp);
	sp->width = get_width(fmt);
	sp->precition = get_precition(fmt);
	if (!(sp->length = get_length(fmt)))
		handle_error(0, &sp);
	if (!(**fmt))
	{
		sp->specifier = '\0';
		return (sp);
	}
	sp->specifier = **fmt;
	(*fmt)++;
	normalize_spec(&sp);
	if (!sp->flags || !sp->length)
		handle_error(0, &sp);
	return (sp);
}
