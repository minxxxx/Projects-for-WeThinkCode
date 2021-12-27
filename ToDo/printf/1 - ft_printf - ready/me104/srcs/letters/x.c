/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:18:40 by juspende          #+#    #+#             */
/*   Updated: 2017/12/05 18:33:17 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int		x(va_list argp, const char *arg, int *index, t_flag *flag)
{
	uintmax_t		tmp;
	char			*fnl;
	int				b;

	b = 0;
	(void)index;
	length_modif_uox(argp, flag, &tmp);
	if ((char)arg[0] == 'X')
		fnl = ft_getnbr_base_ui(tmp, "0123456789ABCDEF");
	else
		fnl = ft_getnbr_base_ui(tmp, "0123456789abcdef");
	if (flag->comma && !flag->point && fnl[0] == '0')
		b = -1;
	flag->tilt = ft_strlen(fnl);
	flag->larg -= ft_strlen(fnl);
	flag->point -= ft_strlen(fnl);
	flag->point < 0 ? (flag->point = 0) : flag->point;
	flag->larg -= flag->point;
	flag->diez ? flag->larg = flag->larg - 2 : flag->larg;
	b == -1 ? flag->larg += 1 : flag->larg;
	return (x2(b, fnl, arg, flag));
}

int		x2(int b, char *fnl, const char *arg, t_flag *flag)
{
	int		i;

	i = -1;
	if (!flag->zero)
		larg_flag_before(flag);
	if (flag->diez != 0 && fnl[0] != '0')
	{
		ft_putchar('0', flag);
		ft_putchar(arg[0], flag);
	}
	if (flag->zero)
		larg_flag_before(flag);
	while (flag->point-- > 0)
		ft_putchar('0', flag);
	if (b != -1)
		ft_putnstr(fnl, flag, &i);
	larg_flag_after(flag);
	free(fnl);
	return (0);
}
