/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_verify.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 09:58:26 by apakhomo          #+#    #+#             */
/*   Updated: 2018/01/27 09:58:26 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			flag(const char c)
{
	return ((int)ft_strchr("# 0'+-", c));
}

int			modfc(const char c)
{
	return ((int)ft_strchr("zjlh", c));
}

int			conver(const char c)
{
	return ((int)ft_strchr("niDdOoUuXxEeFfGgAaCcSsp%", c));
}

static int	prec(const char c)
{
	return ((int)ft_strchr("$.*", c));
}

int			validsymb(const char c)
{
	return (conver(c) || modfc(c) || flag(c) || ft_isdigit(c) || prec(c));
}
