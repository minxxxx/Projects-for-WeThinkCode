/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 12:44:26 by juspende          #+#    #+#             */
/*   Updated: 2017/12/06 08:28:27 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_printf(const char *restrict list, ...)
{
	int			i;
	va_list		argp;
	t_flag		*flag;

	i = -1;
	va_start(argp, list);
	if ((flag = malloc(sizeof(t_flag))) == NULL ||
			((flag->printed = ft_strdup("")) == NULL))
		return (0);
	flag->color = 0;
	flag->charn = 0;
	while (list[++i] != '\0')
	{
		init_struct(flag);
		if (list[i] == '%' && list[i + 1] != '\0')
			arg_parser(argp, &list[i + 1], &i, flag);
		else if (list[i] != '%')
			ft_putnstr((char *)&list[i], flag, &i);
		if (flag->instantquit != 0)
			return (free_main(flag, -1));
	}
	va_end(argp);
	write(1, flag->printed, ft_strlen(flag->printed));
	return (free_main(flag, flag->charn));
}

int		init_struct(t_flag *flag)
{
	flag->neg = 0;
	flag->pos = 0;
	flag->space = 0;
	flag->zero = 0;
	flag->comma = 0;
	flag->diez = 0;
	flag->point = 0;
	flag->larg = 0;
	flag->h = 0;
	flag->l = 0;
	flag->ll = 0;
	flag->hh = 0;
	flag->h = 0;
	flag->j = 0;
	flag->z = 0;
	flag->tilt = 0;
	flag->nbr = 0;
	flag->cpy = -1;
	flag->instantquit = 0;
	return (1);
}

int		(*g_letter_parser[26])(va_list, const char*, int*, t_flag*) =
{a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z};

int		arg_parser(va_list argp, const char *arg, int *index, t_flag *flag)
{
	int		ret;
	int		(*pointer)(va_list, const char*, int*, t_flag*);

	ret = 0;
	if ((char)arg[0] == '\0')
		return (-1);
	if ((char)arg[0] >= 'A' && (char)arg[0] <= 'Z')
		pointer = g_letter_parser[(int)(arg[0] + 32) - 97];
	else if ((char)arg[0] >= 'a' && (char)arg[0] <= 'z')
		pointer = g_letter_parser[(int)arg[0] - 97];
	else if (((char)arg[0] >= '1' && (char)arg[0] <= '9') ||
	((char)arg[0] == '.') || ((char)arg[0] == '*'))
	{
		if ((ret = precision_pars(argp, arg, index, flag)) == -1)
			return (-1);
	}
	else
		return (ret = flag_parser(argp, arg, index, flag));
	if (((char)arg[0] >= 'a' && (char)arg[0] <= 'z') || ((char)arg[0] >= 'A' &&
				(char)arg[0] <= 'Z'))
		ret = (*pointer)(argp, arg, index, flag);
	*index = *index + 1;
	return (ret);
}

int		precision_pars(va_list argp, const char *arg, int *index, t_flag *flag)
{
	int		c;

	if (arg[0] == '.' && (flag->comma = 1) == 1)
	{
		if (arg[(c = 1)] == '*')
			flag->point = va_arg(argp, int);
		else if ((flag->point = ft_atoi(&arg[c])) == -1)
			return (0);
		arg[c] == '*' && flag->point < 0 ? (flag->comma = 0) : flag->comma;
		arg[c] == '*' && flag->point < 0 ? (flag->point = 0) : flag->point;
	}
	else
	{
		if (arg[(c = 0)] == '*')
			(flag->larg = va_arg(argp, int)) < 0 ?
				(flag->neg = 1) : flag->neg;
		arg[c] != '*' ? (flag->larg = ft_atoi(&arg[c])) : flag->larg;
		arg[c] == '*' && flag->larg < 0 ? flag->larg *= -1 : flag->larg;
	}
	while (arg[c] >= '0' && arg[c] <= '9')
		++c;
	if ((c == 0 && arg[c] == '*') || (arg[0] == '.' && arg[1] == '*'))
		++c;
	*index = (*index + c) - 1;
	return (arg_parser(argp, &arg[c], index, flag));
}

int		flag_parser(va_list argp, const char *arg, int *index, t_flag *flag)
{
	if (arg[0] == '-')
		flag->neg = 1;
	else if (arg[0] == '+')
		flag->pos = 1;
	else if (arg[0] == ' ')
		flag->space = 1;
	else if (arg[0] == '0')
		flag->zero = 1;
	else if (arg[0] == '#')
		flag->diez = 1;
	else if (arg[0] == '%' && (flag->larg -= 1))
	{
		larg_flag_before(flag);
		empty_buffer(flag);
		ft_printwchar('%', flag);
		flag->charn += 1;
		larg_flag_after_s(flag);
		*index = *index + 1;
		return (0);
	}
	else
		return (-2);
	*index = *index + 1;
	return (arg_parser(argp, &arg[1], index, flag));
}
