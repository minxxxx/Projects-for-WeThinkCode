/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemiy <artemiy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 18:34:12 by artemiy           #+#    #+#             */
/*   Updated: 2019/01/04 22:13:03 by artemiy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

char		*ft_fillstr(int len, char ch)
{
	char	*ret;
	int		i;

	ret = ft_strnew(len);
	i = 0;
	while (i < len)
		ret[i++] = ch;
	return (ret);
}

long long	ft_pow(long long base, long long power)
{
	long long	i;
	long long	ret;
	long long	tmp;

	i = 0;
	ret = 1;
	while (i < power && i < 19)
	{
		tmp = ret;
		ret *= base;
		if (tmp > ret)
			return (tmp);
		i++;
	}
	return (ret);
}

char	*ft_add_fract(char *int_str, long long fract, int precition)
{
	char	*str;
	char	*tmp;
	int		fract_len;

	if (!int_str)
		return (NULL);
	str = ft_strnew(ft_strlen(int_str) + precition + 1);
	ft_strcat(str, int_str);
	ft_strcat(str, ".");
	free(int_str);
	int_str = str;
	tmp = ft_ullitoa(fract);
	fract_len = ft_strlen(tmp);
	if (precition > fract_len)
	{
		int_str = ft_fillstr(precition - fract_len, '0');
		ft_strcat(str, int_str);
		free(int_str);
	}
	ft_strcat(str, tmp);
	free(tmp);
	return (str);
}

char		*ft_ftoa(long double num, int precition)
{
	long long	integer ;
	char		*str;
	char		*tmp;

	integer = (long long)num;
	tmp = ft_llitoa(integer);
	if (num < 0)
	{
		num = -num;
		integer = -integer;
	}
	num = (long double)(num - integer);
	num *= ft_pow(10, precition);
	integer = (long long)num + (((num - (long long)num) >= 0.5) ? 1 : 0);
	if (precition > 0)
		str = ft_add_fract(tmp, integer, precition);
	else
		str = tmp;
	return (str);
}
