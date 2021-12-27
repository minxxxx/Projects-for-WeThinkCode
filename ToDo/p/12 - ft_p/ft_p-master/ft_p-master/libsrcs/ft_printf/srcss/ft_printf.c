/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 18:51:46 by jcamhi            #+#    #+#             */
/*   Updated: 2016/02/01 09:43:57 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <stdio.h>

static void	ft_flat(t_arg *arg)
{
	if (arg->conv == 'D' && ft_strequ(arg->lm, "hh"))
	{
		(arg->lm)[1] = '\0';
		arg->conv = 'd';
	}
	else if (arg->conv == 'O' && ft_strequ(arg->lm, "hh"))
	{
		(arg->lm)[1] = '\0';
		arg->conv = 'o';
	}
	else if (arg->conv == 'U' && ft_strequ(arg->lm, "hh"))
	{
		(arg->lm)[1] = '\0';
		arg->conv = 'u';
	}
	else if ((arg->lm[0] == 'h') && (arg->conv == 'C' || arg->conv == 'S' ||
				arg->conv == 'c' || arg->conv == 's'))
		(arg->lm)[0] = '\0';
	else if ((arg->lm[0] == 'h' || arg->lm[0] == 'l') && arg->conv == 'p')
		(arg->lm)[0] = '\0';
}

static void	find_things(t_arg *arg, char *str, int i, va_list list)
{
	find_flag(str, i, arg);
	find_width(str, i, arg, list);
	find_prec(str, i, arg);
	find_lm(str, i, arg);
}

static char	*init_things(t_arg *arg, char *ret, int *nbr)
{
	ret = handle_flag_2(arg, ret);
	ret = handle_prec(*arg, ret);
	ret = handle_flag(arg, ret);
	ret = handle_width(*arg, ret, nbr);
	return (ret);
}

static int	handle_arg(const char *str, int i, va_list list, int *o)
{
	t_arg	arg;
	char	*ret;
	int		nb;
	int		nbr;

	nb = 0;
	arg.debut = i;
	if (!find_fin(str, i + 1, &arg))
	{
		*o = arg.fin;
		return (0);
	}
	find_things(&arg, (char*)str, i, list);
	ft_flat(&arg);
	ret = init_ret(arg, list);
	ret = init_things(&arg, ret, &nbr);
	ft_putstr(ret);
	if (nbr == 1)
		ft_putchar('\0');
	*o = arg.fin;
	nb = (int)ft_strlen(ret) + nbr;
	free(ret);
	free(arg.flag);
	return (nb == 0 && arg.conv == 'c' ? 1 : nb);
}

int			ft_printf(const char *str, ...)
{
	va_list	list;
	int		i;
	int		nbcar;

	va_start(list, str);
	i = 0;
	nbcar = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '%')
		{
			ft_putchar(str[i]);
			nbcar++;
		}
		else
			nbcar += handle_arg(str, i, list, &i);
		i++;
	}
	va_end(list);
	return (nbcar);
}
