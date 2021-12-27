/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillstruct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfavero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 11:24:25 by cfavero           #+#    #+#             */
/*   Updated: 2018/03/13 18:09:41 by cfavero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_check_precision(const char *format, t_flag *flag)
{
	char	*cpy;
	char	*c;
	int		i;

	if ((c = (ft_strchr((char *)format, '.'))))
	{
		flag->prec = 1;
		i = 0;
		c++;
		while (*c >= '0' && *c <= '9')
		{
			c++;
			i++;
		}
		cpy = ft_strnew(i);
		ft_strncpy(cpy, c - i, i);
		flag->val_prec = ft_atoi(cpy);
		free(cpy);
		if (i == 0)
			flag->val_prec = 0;
	}
}

static void	ft_check_size(char *format, t_flag *arg)
{
	if (ft_strchr(format, 'z'))
		arg->val_size = 7;
	else if (ft_strchr(format, 'l'))
	{
		format++;
		if (*format == 'l')
			arg->val_size = 6;
		else
			arg->val_size = 5;
	}
	else if (ft_strchr(format, 'j'))
		arg->val_size = 4;
	else if (ft_strchr(format, 'h'))
	{
		format++;
		if (*format == 'h')
			arg->val_size = 2;
		else
			arg->val_size = 3;
	}
}

static void	ft_check_width(const char *format, t_flag *flag)
{
	char	*cpy;
	int		i;

	(*format == '%') ? format-- : 0;
	while (*format != '%')
	{
		i = 0;
		if (ft_isdigit(*format) == 0)
			format--;
		while (ft_isdigit(*format) == 1)
		{
			format--;
			i++;
		}
		if (*format != '.' && i > 0)
		{
			cpy = ft_strnew(i);
			ft_strncpy(cpy, format + 1, i);
			flag->numb = ft_atoi(cpy);
			free(cpy);
			if (flag->numb != 0)
				break ;
		}
	}
}

static void	ft_check_zero(const char *format, t_flag *flag)
{
	if (*format == '+')
		flag->plus = 1;
	else if (*format == '-')
		flag->meno = 1;
	else if (*format == '0')
	{
		format--;
		if (!((*format >= '0' && *format <= '9') && *format != '.'))
			flag->zero = 1;
	}
	else if (*format == ' ')
		flag->space = 1;
	else if (*format == '#')
		flag->hash = 1;
}

char		*ft_fillstruct(const char *format, t_flag *flag)
{
	char	*cpy;
	char	*prova;
	int		i;

	if (format == NULL)
		return (0);
	cpy = (char*)format;
	i = 0;
	while (ft_strchr("+- #.\'0123456789jhzl", *format) && *format)
	{
		ft_check_zero(format, flag);
		i++;
		format++;
	}
	*format != '\0' ? flag->conv = 1 : 0;
	*format != '\0' ? flag->val_conv = *format : 0;
	if (*format == '\0')
		return ((char*)format);
	prova = ft_strnew(i);
	ft_strncpy(prova, cpy, i);
	ft_check_precision(prova, flag);
	ft_check_size(prova, flag);
	ft_check_width(format, flag);
	free(prova);
	return ((char*)format);
}
