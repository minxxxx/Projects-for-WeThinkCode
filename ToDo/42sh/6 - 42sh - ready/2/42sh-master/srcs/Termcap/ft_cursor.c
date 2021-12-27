/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cursor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadenho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 04:05:16 by jbadenho          #+#    #+#             */
/*   Updated: 2017/11/24 03:47:25 by jbadenho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"
#define BS a->i--;ft_putstr_fd("\b \b", 0);a->c[(ft_strlen(a->c) - 1)] = '\0'
#define MR "\033[1C"
#define ML "\033[1D"

void		ft_right(t_all *a)
{
	int	n;
	int	t;

	t = ft_get_dir();
	n = (int)ft_strlen(a->c) + t;
	if (a->i < n)
	{
		ft_putstr_fd(MR, 0);
		a->i++;
	}
}

void		ft_left(t_all *a)
{
	int	n;

	n = ft_get_dir();
	if (a->i > n)
	{
		ft_putstr_fd(ML, 0);
		a->i--;
	}
}

void		ft_backspace(t_all *a)
{
	int	n;
	int	t;

	t = ft_get_dir();
	n = (int)ft_strlen(a->c) + t;
	if (a->i < n)
		return ;
	else
	{
		if (a->i > t)
		{
			BS;
		}
	}
}
