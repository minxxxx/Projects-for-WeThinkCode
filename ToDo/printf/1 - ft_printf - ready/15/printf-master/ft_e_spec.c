/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_e_spec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemiy <artemiy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 14:47:16 by artemiy           #+#    #+#             */
/*   Updated: 2019/01/05 18:28:15 by artemiy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

int		ft_get_exponent(char *str)
{
	int	exponent;
	int	sign;

	exponent = 0;
	sign = *str == '0';
	if (sign)
	{
		while (*str == '0' || *str == '.' || *str == '-')
		{
			if (*str != '.')
				exponent++;
			str++;
		}
	}
	else
	{
		while (*str != '.')
			if (ft_isdigit(*(str++)))
				exponent++;
		exponent--;
	}
	if (sign)
		exponent *= -1;
	return (exponent);
}

char	*ft_add_exponent(char *num, int exponent, char e_char)
{
	char	*exp_str;
	char	*exp_itoa;
	char	*str;

	if (!(exp_str = ft_fillstr(4, '0')) || !(exp_itoa = ft_itoa(exponent)))
		return (NULL);
	exp_str[0] = e_char;
	if (exponent >= 0)
	{
		exp_str[1] = '+';
		ft_strcpy(exp_str + (2 + 2 - ft_strlen(exp_itoa)), exp_itoa);
	}
	else
	{
		exp_str[1] = '-';
		ft_strcpy(exp_str + (2 + 3 - ft_strlen(exp_itoa)), exp_itoa + 1);
	}
	free(exp_itoa);
	str = ft_strjoin(num, exp_str);
	free(num);
	free(exp_str);
	return (str);
}

char	*ft_double_to_exp(long double num, int precition, char specifier)
{
	char	*fstr;
	char	*str;
	int		exponent;

	precition = precition >= 0 ? precition : 6;
	if (!(fstr = ft_ftoa(num, 18)))
		return (NULL);
	exponent = num == 0.0 ? 0 : ft_get_exponent(fstr);
	free(fstr);
	if (exponent > 0)
		num /= ft_pow(10, exponent);
	if (exponent < 0)
		num *= ft_pow(10, -exponent);
	fstr = ft_ftoa(num, precition);
	str = ft_add_exponent(fstr, exponent, specifier);
	return(str);
}

char	*ft_dispatch_e(t_specifier *spec, va_list *ap)
{
	char	*str;

	if (ft_strcmp(spec->length, "") == 0)
		str = ft_double_to_exp(va_arg(*ap, double), spec->precition, spec->specifier);
	else if (ft_strcmp(spec->length, "l") == 0)
		str = ft_double_to_exp(va_arg(*ap, double), spec->precition, spec->specifier);
	else
		str = ft_double_to_exp(va_arg(*ap, long double), spec->precition, spec->specifier);
	return (str);
}
