/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:18:40 by juspende          #+#    #+#             */
/*   Updated: 2017/12/05 20:29:02 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

static void	cap_s_parser(t_flag *flag)
{
	if (flag->comma && !flag->point)
		flag->tilt = 0;
	flag->charn += flag->tilt;
	flag->larg -= flag->tilt;
}

void		empty_buffer(t_flag *flag)
{
	write(1, flag->printed, ft_strlen(flag->printed));
	free(flag->printed);
	flag->printed = ft_strnew(2);
	return ;
}

static int	big_s(va_list argp, const char *arg, int *index, t_flag *flag)
{
	wint_t		*tmp;
	int			i;
	int			b;
	int			size;

	i = -1;
	b = 0;
	size = 0;
	(void)index;
	(void)arg;
	tmp = va_arg(argp, wint_t*);
	while (tmp && b != -1 && tmp[++i])
		ft_wstrlen(tmp[i]) == -1 ? b = -1 : (size += ft_wstrlen(tmp[i]));
	if (b == -1 && (flag->instantquit = LEAVE))
		return (0);
	flag->point > 0 ? (flag->nbr = flag->point) :
		(flag->nbr = size);
	flag->comma && !flag->point ? (flag->tilt = 0) :
		(flag->tilt = flag->nbr);
	cap_s_parser(flag);
	flag->comma && !flag->nbr ? (b = -1) : b;
	flag->point <= 0 ? (flag->point = flag->tilt) : flag->point;
	larg_flag_before_s(flag);
	return (big_s2(argp, tmp, b, flag));
}

int			big_s2(va_list argp, wint_t *tmp, int b, t_flag *flag)
{
	int		i;
	int		size;

	size = 0;
	i = -1;
	(void)argp;
	while (tmp && (size += ft_wstrlen(tmp[++i])) && size <= flag->nbr &&
			tmp[i] && b >= 0 && flag->tilt != 0)
		;
	if (flag->larg > flag->point && size - ft_wstrlen(tmp[i]) < flag->tilt)
		while (size++ - ft_wstrlen(tmp[i]) < flag->tilt && (flag->charn += 1))
			ft_printwchar(' ', flag);
	i = -1;
	size = 0;
	while (tmp && (size += ft_wstrlen(tmp[++i])) && size <= flag->nbr &&
			tmp[i] && b >= 0 && flag->tilt != 0)
		ft_putchar_s(tmp[i], flag);
	if (tmp && flag->tilt != 0 && b >= 0 && size -
			ft_wstrlen(tmp[i]) < flag->tilt)
		flag->charn -= (flag->nbr - (size - ft_wstrlen(tmp[i])));
	!tmp ? ft_puts("(null)", flag) : flag;
	larg_flag_after_s(flag);
	empty_buffer(flag);
	return (0);
}

int			s(va_list argp, const char *arg, int *index, t_flag *flag)
{
	char	*tmp;
	int		i;
	int		b;

	i = -1;
	b = 0;
	if (arg[0] == 'S' || flag->l)
		return (big_s(argp, arg, index, flag));
	tmp = va_arg(argp, char*);
	!tmp && !flag->comma ? (tmp = ft_strdup("(null)")) :
		(tmp = ft_strdup(tmp));
	if (flag->comma && (int)ft_strlen(tmp) > flag->point && flag->point > 0)
		tmp[flag->point] = '\0';
	if (flag->comma && flag->point <= 0 && (b = -1))
		;
	b == -1 ? (flag->larg += ft_strlen(tmp)) : flag->larg;
	flag->larg = flag->larg - ft_strlen(tmp);
	larg_flag_before(flag);
	if (b != -1)
		ft_putnstr(tmp, flag, &i);
	larg_flag_after(flag);
	free(tmp);
	return (0);
}
