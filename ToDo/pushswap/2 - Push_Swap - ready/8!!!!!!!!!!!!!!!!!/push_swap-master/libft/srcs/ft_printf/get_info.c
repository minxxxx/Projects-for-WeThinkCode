/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 20:16:05 by ljoly             #+#    #+#             */
/*   Updated: 2017/03/13 20:16:07 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_get_modifier(char *frmt, t_info *info)
{
	int		i;

	i = 0;
	while (frmt[i] && frmt[i] != SPEC)
	{
		if (frmt[i] == 'z')
			MOD = MOD_Z;
		else if (frmt[i] == 'l' && frmt[i + 1] == 'l')
			MOD = MOD_LL;
		else if (frmt[i] == 'h' && frmt[i + 1] == 'h')
			MOD = MOD_HH;
		else if (frmt[i] == 'j')
			MOD = MOD_J;
		else if (frmt[i] == 'l')
			MOD = MOD_L;
		else if (frmt[i] == 'h')
			MOD = MOD_H;
		if (MOD)
			break ;
		i++;
	}
}

void		ft_get_precision(char *frmt, t_info *info)
{
	int		i;
	char	*tmp;

	i = 0;
	while (frmt[i] && frmt[i] != SPEC && frmt[i] != '.')
		i++;
	if (frmt[i] == '.')
	{
		IS_PRECISION = 1;
		ZERO = 0;
		frmt += i + 1;
		i = 0;
		while (ft_isdigit(frmt[i]))
			i++;
		tmp = ft_strsub(frmt, 0, i);
		PRECISION = ft_atoi(tmp);
		free(tmp);
	}
}

void		ft_get_width(char *frmt, t_info *info)
{
	int		i;
	char	*tmp;

	i = 0;
	while (frmt[i] && frmt[i] != SPEC && (!(ft_isdigit(frmt[i]))
				|| frmt[i] == '0'))
		i++;
	if (ft_isdigit(frmt[i]) && frmt[i - 1] != '.')
	{
		frmt += i;
		i = 0;
		while (ft_isdigit(frmt[i]))
			i++;
		tmp = ft_strsub(frmt, 0, i);
		WIDTH = ft_atoi(tmp);
		free(tmp);
	}
}

void		ft_get_flags(char *frmt, t_info *info)
{
	int		i;

	i = 0;
	while (frmt[i] && frmt[i] != SPEC)
	{
		if (frmt[i] == '#')
			SHARP = 1;
		else if (frmt[i] == ' ')
			SPACE = 1;
		else if (frmt[i] == '0' && !ft_isdigit(frmt[i - 1]))
			ZERO = 1;
		else if (frmt[i] == '+')
		{
			PLUS = 1;
			SPACE = 0;
		}
		else if (frmt[i] == '-')
		{
			MINUS = 1;
			ZERO = 0;
		}
		i++;
	}
}

void		ft_get_specifier(char **frmt, t_info *info)
{
	int		i;
	char	*spec;

	i = 0;
	spec = "sSpdDioOuUxXcCb";
	if (!**frmt)
		return ;
	while (**frmt && !SPEC)
	{
		if (**frmt == spec[i])
			SPEC = spec[i];
		else if (**frmt == '%')
			SPEC = '%';
		if (i == 14)
		{
			i = -1;
			(*frmt)++;
		}
		i++;
	}
}
