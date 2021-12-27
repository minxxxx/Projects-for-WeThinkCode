/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 12:44:26 by juspende          #+#    #+#             */
/*   Updated: 2017/12/05 16:32:51 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	larg_flag_before_s(t_flag *flag)
{
	int		i;
	char	c;

	i = 0;
	c = ' ';
	if (flag->neg != 0)
		return ;
	if (flag->zero != 0)
		c = '0';
	while (i < flag->larg)
	{
		++i;
		flag->charn += 1;
		ft_printwchar(c, flag);
	}
}

void	larg_flag_after_s(t_flag *flag)
{
	int		i;
	char	c;

	i = 0;
	c = ' ';
	if (flag->neg == 0)
		return ;
	while (i < flag->larg)
	{
		flag->charn += 1;
		++i;
		ft_printwchar(c, flag);
	}
}

void	larg_flag_before(t_flag *flag)
{
	int		i;
	char	c;

	i = 0;
	c = ' ';
	if (flag->neg != 0)
		return ;
	if (flag->zero != 0)
		c = '0';
	while (i < flag->larg)
	{
		++i;
		ft_putchar(c, flag);
	}
}

void	larg_flag_after(t_flag *flag)
{
	int		i;
	char	c;

	i = 0;
	c = ' ';
	if (flag->neg == 0)
		return ;
	while (i < flag->larg)
	{
		++i;
		ft_putchar(c, flag);
	}
}
