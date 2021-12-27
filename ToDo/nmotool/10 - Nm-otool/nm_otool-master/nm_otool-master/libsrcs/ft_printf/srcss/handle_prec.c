/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_prec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 18:39:06 by jcamhi            #+#    #+#             */
/*   Updated: 2016/01/18 22:48:39 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static char	*init_zero_tab(int nb)
{
	int		i;
	char	*tab;

	i = 0;
	tab = (char*)malloc(nb + 1);
	while (i < nb)
	{
		tab[i] = '0';
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

static char	*prec_with_p(const t_arg arg, char *ret)
{
	char	*tmp;
	char	*tab;

	tmp = ft_strdup(ret + 2);
	free(ret);
	if (tmp[0] == '0' && arg.prec == 0)
	{
		free(tmp);
		tmp = ft_alloc_str("0x");
	}
	else if ((int)ft_strlen(tmp) < arg.prec)
	{
		tab = init_zero_tab(arg.prec - ft_strlen(tmp));
		tmp = ft_strjoinaf12(tab, tmp);
		tmp = ft_strjoinaf2("0x", tmp);
	}
	else
		tmp = ft_strjoinaf2("0x", tmp);
	return (tmp);
}

static char	*fill_with_zeros(const t_arg arg, char *ret, char *tab)
{
	if ((int)ft_strlen(ret) < arg.prec)
	{
		tab = init_zero_tab(arg.prec - ft_strlen(ret));
		ret = ft_strjoinaf12(tab, ret);
	}
	return (ret);
}

static char	*prec_with_num(const t_arg arg, char *ret, char *tab, char *tmp)
{
	if (ret[0] == '-')
	{
		tmp = ft_strdup(ret + 1);
		if ((int)ft_strlen(tmp) < arg.prec)
		{
			tab = init_zero_tab(arg.prec - ft_strlen(tmp));
			tmp = ft_strjoinaf12(tab, tmp);
			tmp = ft_strjoinaf2("-", tmp);
			free(ret);
			ret = tmp;
		}
	}
	else if ((ret[0] == '0' || ft_strequ(ret, "0x0")) && arg.prec == 0)
	{
		if (!(ft_strchr(arg.flag, '#') &&
					(arg.conv == 'o' || arg.conv == 'O')))
		{
			tmp = ft_alloc_str("");
			free(ret);
			ret = tmp;
		}
	}
	ret = fill_with_zeros(arg, ret, tab);
	return (ret);
}

char		*handle_prec(const t_arg arg, char *ret)
{
	char	*tab;
	char	*tmp;

	tmp = NULL;
	tab = NULL;
	if (arg.conv == 'd' || arg.conv == 'D' || arg.conv == 'i'
			|| arg.conv == 'x' || arg.conv == 'X' || arg.conv == 'u'
			|| arg.conv == 'U' || arg.conv == 'o' || arg.conv == 'O')
		ret = prec_with_num(arg, ret, tab, tmp);
	else if (arg.conv == 's' || arg.conv == 'S')
	{
		if (ft_strlen(ret) > (size_t)arg.prec)
		{
			tmp = ft_strsub((const char*)ret, 0, arg.prec);
			free(ret);
			ret = tmp;
		}
	}
	else if (arg.conv == 'p')
		ret = prec_with_p(arg, ret);
	return (ret);
}
