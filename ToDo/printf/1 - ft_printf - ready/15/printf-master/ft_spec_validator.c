/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_validator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuhn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 19:18:29 by fkuhn             #+#    #+#             */
/*   Updated: 2019/01/08 20:14:30 by fkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

void	flag_undefined(char flag, char spec)
{
	ft_putstr("warning: flag '");
	ft_putchar(flag);
	ft_putstr("' results in undefined behavior with '");
	ft_putchar(spec);
	ft_putstr("'\n");
}

void	handle_error(int code, t_specifier **sp)
{
	if (code == 0)
	{
		ft_putstr("");
		if (sp)
		spec_del(sp);
		exit(0);
	}
	else if (code == 1)
	{
		ft_putstr("warning: invalid conversion specifier '");
		ft_putchar((*sp)->specifier);
		ft_putstr("'\n");
	}
	else if (code == 2 || code == 3)
		flag_undefined(code == 2 ? '#' : '0', (*sp)->specifier);
	else if (code == 4)
		ft_putstr("warning: flag '0' is ignored when flag '-' is present\n");
	else if (code == 5)
		ft_putstr("warning: flag ' ' is ignored when flag '+' is present\n");
}

int		is_valid_spec(t_specifier **sp, int *done)
{
	if (!*sp)
		handle_error(0, NULL);
	if (!(*sp)->specifier)
		return (0);
	if (!ft_strchr("dDioOuUxXscCpfFbrkge", (*sp)->specifier))
	{
		print_specifier(*sp, done);
		return (0);
	}
	return (1);
}

void	normalize_spec(t_specifier **spec)
{
	if (ft_strchr("dixX", (*spec)->specifier) && (*spec)->precition >= 0)
		(*spec)->flags->zero = 0;
	if ((*spec)->specifier == 'p' && (*spec)->flags->plus)
		(*spec)->flags->plus = 0;
	if ((*spec)->specifier == 'p' && (*spec)->flags->space)
		(*spec)->flags->space = 0;
}
