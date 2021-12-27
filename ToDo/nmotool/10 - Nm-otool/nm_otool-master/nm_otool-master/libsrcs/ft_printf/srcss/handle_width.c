/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 19:10:07 by jcamhi            #+#    #+#             */
/*   Updated: 2016/01/18 22:34:10 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static char	*init_tab(int nb, char c)
{
	int		i;
	char	*tab;

	i = 0;
	tab = (char*)malloc(nb + 1);
	while (i < nb)
	{
		tab[i] = c;
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

static char	*ret_is_zero(char *ret, int *n, int nb, const t_arg arg)
{
	char	*tab;

	nb++;
	*n = 1;
	if (nb < arg.width)
	{
		if (ft_strchr(arg.flag, '0') && !ft_strchr(arg.flag, '-'))
			tab = init_tab(arg.width - nb, '0');
		else
			tab = init_tab(arg.width - nb, ' ');
		if (ft_strchr(arg.flag, '-'))
			ft_putchar('\0');
		free(ret);
		return (tab);
	}
	return (ret);
}

static char	*ft_exchange_minus(char *ret, t_arg arg)
{
	char	*ptr;
	char	tmp;

	if (!ft_strchr(arg.flag, '0'))
		return (ret);
	ptr = ft_strchr(ret, '-');
	if (!ptr)
		ptr = ft_strchr(ret, '+');
	if (!ptr && !ft_strchr(arg.flag, '-'))
		ptr = ft_strchr(ret, ' ');
	if (ptr)
	{
		tmp = *ptr;
		*ptr = ret[0];
		ret[0] = tmp;
	}
	return (ret);
}

static char	*ft_handle_with_p(char *ret, char *tab, const t_arg arg)
{
	char *temp;

	temp = ft_alloc_str(ret + 2);
	if (ft_strchr(arg.flag, '-'))
		temp = ft_strjoinaf12(temp, tab);
	else if (tab[0] == '0')
		temp = ft_strjoinaf12(tab, temp);
	free(ret);
	temp = ft_strjoinaf2("0x", temp);
	if (tab[0] == ' ')
		temp = ft_strjoinaf12(tab, temp);
	return (temp);
}

char		*handle_width(const t_arg arg, char *ret, int *n)
{
	char	*tab;
	int		nb;

	nb = (int)ft_strlen(ret);
	if (ret[0] == '\0' && (arg.conv == 'c' || arg.conv == 'C'))
		return (ret_is_zero(ret, n, nb, arg));
	else
		*n = 0;
	if (nb < arg.width)
	{
		if (arg.prec <= 0 && ft_strchr(arg.flag, '0')
				&& !ft_strchr(arg.flag, '-'))
			tab = init_tab(arg.width - nb, '0');
		else
			tab = init_tab(arg.width - nb, ' ');
		if (arg.conv == 'p')
			ret = ft_handle_with_p(ret, tab, arg);
		else if (ft_strchr(arg.flag, '-'))
			ret = ft_strjoinaf12(ret, tab);
		else
			ret = ft_strjoinaf12(tab, ret);
	}
	if (arg.conv == 'd' || arg.conv == 'D' || arg.conv == 'D')
		ret = ft_exchange_minus(ret, arg);
	return (ret);
}
