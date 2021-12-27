/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_modifiers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 16:37:06 by fkoehler          #+#    #+#             */
/*   Updated: 2016/02/12 12:32:14 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_l_modifier(char *argument, t_arg *arg, int i)
{
	if ((ft_strchr_count(argument, 'l') == 1) &&
		(argument[i] == 'l'))
	{
		arg->l = 1;
		i++;
	}
	else if ((ft_strchr_count(argument, 'l') == 2) &&
			(argument[i] == 'l') && (argument[i + 1] == 'l'))
	{
		arg->ll = 1;
		i += 2;
	}
	else if (ft_strchr_count(argument, 'l') > 0)
		return (-1);
	return (i);
}

int	check_h_modifier(char *argument, t_arg *arg, int i)
{
	if ((ft_strchr_count(argument, 'h') == 1) &&
		(argument[i] == 'h'))
	{
		arg->h = 1;
		i++;
	}
	else if ((ft_strchr_count(argument, 'h') == 2) &&
			(argument[i] == 'h') && (argument[i + 1] == 'h'))
	{
		arg->hh = 1;
		i += 2;
	}
	else if (ft_strchr_count(argument, 'h') > 0)
		return (-1);
	return (i);
}

int	check_j_modifier(char *argument, t_arg *arg, int i)
{
	if ((ft_strchr_count(argument, 'j') == 1) &&
		(argument[i] == 'j'))
	{
		arg->j = 1;
		i++;
	}
	else if (ft_strchr_count(argument, 'j') > 0)
		return (-1);
	return (i);
}

int	check_z_modifier(char *argument, t_arg *arg, int i)
{
	if ((ft_strchr_count(argument, 'z') == 1) &&
		(argument[i] == 'z'))
	{
		arg->z = 1;
		i++;
	}
	else if (ft_strchr_count(argument, 'z') > 0)
		return (-1);
	return (i);
}
