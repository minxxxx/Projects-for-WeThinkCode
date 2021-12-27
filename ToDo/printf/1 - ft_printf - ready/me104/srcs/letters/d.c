/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:18:40 by juspende          #+#    #+#             */
/*   Updated: 2017/12/05 20:23:53 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void		larg_flag_before_d(t_flag *flag)
{
	char	*str;
	int		i;

	i = -1;
	flag->nbr < 0 ? flag->larg -= 1 : flag->larg;
	flag->comma ? flag->zero = 0 : flag->zero;
	flag->pos ? flag->larg -= 1 : flag->larg;
	flag->space && flag->nbr >= 0 && !flag->pos ? flag->larg -= 1 : flag->larg;
	flag->space && flag->nbr >= 0 && flag->zero ? ft_putchar(' ', flag) : i;
	flag->pos && flag->nbr < 0 ? flag->larg += 1 : flag->larg;
	flag->point -= flag->tilt;
	flag->point < 0 ? flag->point = 0 : flag->point;
	flag->larg -= flag->point;
	if ((str = ft_strnew(flag->larg + flag->tilt + flag->point + 30)) == NULL)
		return ;
	flag->zero && !flag->neg ? (flag->c = '0') :
		(flag->c = ' ');
	flag->space && flag->nbr > 0 && !flag->pos ? (str[++i] = ' ') : flag->larg;
	flag->nbr < 0 && flag->c == '0' ? str[++i] = '-' : flag->c;
	flag->nbr >= 0 && flag->pos && flag->c != ' ' ? str[++i] = '+' : flag->c;
	while (flag->larg-- > 0 && !flag->neg)
		str[++i] = flag->c;
	str[++i] = '\0';
	larg_flag_before_d2(flag, str, i - 1);
}

void		larg_flag_before_d2(t_flag *flag, char *str, int i)
{
	int		c;

	c = -1;
	if (flag->neg)
	{
		if (flag->nbr < 0)
			str[++i] = '-';
		flag->nbr >= 0 && flag->pos ? str[++i] = '+' : flag->c;
		while (flag->point-- > 0)
			str[++i] = '0';
		str[++i] = '\0';
		ft_putnstr(str, flag, &c);
		flag->larg += flag->tilt;
		free(str);
		return ;
	}
	while (flag->larg-- > 0)
		str[++i] = flag->c;
	flag->nbr < 0 && flag->c == ' ' ? str[++i] = '-' : flag->larg;
	flag->nbr >= 0 && flag->pos && flag->c == ' ' ? str[++i] = '+' : flag->larg;
	while (flag->point-- > 0)
		str[++i] = '0';
	str[++i] = '\0';
	ft_putnstr(str, flag, &c);
	free(str);
}

void		larg_flag_after_d(t_flag *flag)
{
	char	*str;
	int		i;
	int		c;

	i = -1;
	c = -1;
	if (!flag->neg)
		return ;
	if ((str = malloc(sizeof(char) * (flag->larg + 1))) == NULL)
		return ;
	while (flag->larg-- >= (flag->tilt > flag->point ? flag->tilt :
				flag->point))
		str[++i] = flag->c;
	str[++i] = '\0';
	ft_putnstr(str, flag, &c);
	free(str);
}

int			d(va_list argp, const char *arg, int *index, t_flag *flag)
{
	intmax_t		tmp;
	int				c;
	uintmax_t		ptr;
	int				b;

	b = 0;
	arg[0] == 'D' ? flag->l = 1 : flag->l;
	(void)index;
	c = -1;
	length_modif_di(argp, flag, &tmp);
	flag->tilt = int_len(tmp);
	flag->larg -= int_len(tmp);
	flag->nbr = tmp;
	if (flag->comma && !flag->point && !flag->nbr && (b = 1))
		flag->larg += 1;
	larg_flag_before_d(flag);
	if (tmp < 0)
		ptr = -tmp;
	else
		ptr = tmp;
	if (b != 1)
		ft_putnstr_free(ft_itoa(ptr, 10), flag, &c);
	larg_flag_after_d(flag);
	return (0);
}
