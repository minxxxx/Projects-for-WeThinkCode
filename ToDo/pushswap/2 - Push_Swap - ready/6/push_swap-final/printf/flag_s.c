/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfavero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 16:13:45 by cfavero           #+#    #+#             */
/*   Updated: 2018/03/13 14:42:43 by cfavero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void	ft_with(t_flag *flag, char *c)
{
	while (flag->meno == 0 && flag->numb > 0 && flag->zero == 0)
	{
		ft_putchar(' ');
		flag->numb--;
	}
	while (flag->numb > 0 && flag->zero == 1 && flag->meno == 0)
	{
		ft_putchar('0');
		flag->numb--;
	}
	if ((ft_strlen(c) > (size_t)flag->val_prec) && flag->prec == 1)
		c = ft_strsub(c, 0, flag->val_prec);
	ft_putstr(c);
	while (flag->numb > 0)
	{
		ft_putchar(' ');
		flag->numb--;
	}
}

static char	*ft_wchar(char *s, va_list *ap)
{
	wchar_t		*k;
	char		*c;
	char		*m;

	if (!(k = va_arg(*ap, wchar_t*)))
		s = ft_strdup("(null)");
	if (k && *k == 0)
		s = ft_strdup("");
	while (k && *k)
	{
		c = ft_unicode(*k);
		m = s;
		s = ft_strjoin(s, c);
		k++;
		free(m);
		free(c);
	}
	return (s);
}

static int	ft_boh(t_flag *flag, int i, char *s)
{
	while ((s[flag->val_prec] & 0xC0) == 0x80)
		flag->val_prec--;
	flag->numb = flag->numb - flag->val_prec;
	i = flag->val_prec;
	return (i);
}

static int	ft_boh2(t_flag *flag, int i, int k, char *s)
{
	if (flag->numb > 0)
	{
		i = k;
		ft_with(flag, s);
	}
	else if (flag->prec == 1)
	{
		if ((ft_strlen(s) > (size_t)flag->val_prec) && flag->prec == 1)
			s = ft_strsub(s, 0, flag->val_prec);
		ft_putstr(s);
	}
	else
		ft_putstr(s);
	return (i);
}

int			ft_flag_s(va_list *ap, t_flag *flag)
{
	int			i;
	int			k;
	int			m;
	char		*s;

	i = 0;
	s = NULL;
	k = flag->numb;
	m = 0;
	if (flag->val_size == 5 || flag->val_conv == 'S')
		m = 1;
	if (flag->val_size == 5 || flag->val_conv == 'S')
		s = ft_wchar(s, ap);
	else
		(!(s = (va_arg(*ap, char*)))) ? \
			(s = "(null)") : 0;
	i = ft_strlen(s);
	if (i > flag->val_prec && flag->prec == 1)
		i = ft_boh(flag, i, s);
	else
		flag->numb = flag->numb - i;
	i = ft_boh2(flag, i, k, s);
	if (s && m == 1)
		free(s);
	return (i);
}
