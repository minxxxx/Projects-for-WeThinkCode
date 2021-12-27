/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thendric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 11:47:45 by thendric          #+#    #+#             */
/*   Updated: 2017/01/19 12:48:31 by thendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_wctos(wint_t c)
{
	char	*str;

	str = ft_strnew(4);
	if (c <= 0x7F)
		str[0] = c;
	else if (c <= 0x7FF)
	{
		str[0] = (c >> 6) + 0xc0;
		str[1] = (c & 0x3f) + 0x80;
	}
	else if (c <= 0xFFFF)
	{
		str[0] = (c >> 12) + 0xe0;
		str[1] = ((c >> 6) & 0x3f) + 0x80;
		str[2] = (c & 0x3f) + 0x80;
	}
	else if (c <= 0x10FFFF)
	{
		str[0] = (c >> 18) + 0xf0;
		str[1] = (c >> 12 & 0x3f) + 0x80;
		str[2] = (c >> 6 & 0x3f) + 0x80;
		str[3] = (c & 0x3f) + 0xc80;
	}
	return (str);
}

int		ft_convers_wc(t_input *input)
{
	int		flag;
	char	*str;
	wint_t	c;

	flag = 1;
	str = NULL;
	c = (wint_t)input->var;
	str = ft_wctos(c);
	flag += ft_getflags(input);
	ft_checkflags(input, str);
	input->form += flag;
	//ft_strdel(&str);
	return (0);
}

int		ft_convers_ws(t_input *input)
{
	int		flag;
	char	*str;
	wchar_t	*instr;
	wint_t	c;
	int		i;

	flag = 1;
	i = -1;
	str = ft_strnew(1);
	instr = (wchar_t *)input->var;
	if (!instr)
		str = ft_strdup("(null)");
	else
	{
		while (instr[++i])
		{
			c = (wint_t)instr[i];
			str = ft_strjoin(str, ft_wctos(c));
		}
	}
	flag += ft_getflags(input);
	ft_checkflags(input, str);
	input->form += flag;
	ft_strdel(&str);
	return (0);
}
