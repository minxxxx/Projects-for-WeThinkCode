/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wstring_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 14:14:58 by dgalide           #+#    #+#             */
/*   Updated: 2016/04/11 14:14:59 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		null_handler(t_data *data)
{
	char *str;

	str = ft_strdup("(null)");
	data->final_len += ft_strlen(str);
	write(1, str, ft_strlen(str));
	ft_memdel((void **)&str);
}

static void		wide_to_char(wchar_t **tmp, char **s1, char **s2, int i)
{
	while ((*tmp) && (*tmp)[++i])
	{
		*s1 = ft_memset(ft_strnew(5), '\0', 5);
		if ((*tmp)[i] <= 0x7F)
			(*s1)[0] = (*tmp)[i];
		else if ((*tmp)[i] <= 0x7FF)
		{
			(*s1)[0] = (((*tmp)[i] >> 6) + 0xC0);
			(*s1)[1] = (((*tmp)[i] & 0x3F) + 0x80);
		}
		else if ((*tmp)[i] <= 0xFFFF)
		{
			(*s1)[0] = (((*tmp)[i] >> 12) + 0xE0);
			(*s1)[1] = ((((*tmp)[i] >> 6) & 0x3F) + 0x80);
			(*s1)[2] = (((*tmp)[i] & 0x3F) + 0x80);
		}
		else if ((*tmp)[i] <= 0x10FFFF)
		{
			(*s1)[0] = (((*tmp)[i] >> 18) + 0xF0);
			(*s1)[1] = ((((*tmp)[i] >> 12) & 0x3F) + 0x80);
			(*s1)[2] = ((((*tmp)[i] >> 6) & 0x3F) + 0x80);
			(*s1)[3] = (((*tmp)[i] & 0x3F) + 0x80);
		}
		*s2 = ft_strjoin_free(s2, s1, 1, 1);
	}
}

void			wstring_range_handler(t_data *data, char **str)
{
	char	*tmp;
	int		n;

	tmp = NULL;
	n = data->minimal_range - (int)ft_strlen((*str));
	if (n > 0)
	{
		tmp = ft_memset(ft_strnew(n), ' ', n);
		(*str) = (data->flag.minus) ? ft_strjoin_free(str, &tmp, 1, 1) :
									ft_strjoin_free(&tmp, str, 1, 1);
	}
}

void			wstring_handler(t_data *data, va_list arg)
{
	wchar_t *wstr;
	char	*s1;
	char	*s2;

	s1 = NULL;
	s2 = NULL;
	wstr = (wchar_t *)va_arg(arg, void *);
	if (!wstr || wstr == NULL)
		null_handler(data);
	wide_to_char(&wstr, &s1, &s2, -1);
	wstring_range_handler(data, &s2);
	data->final_len += ft_strlen(s2);
	write(1, s2, ft_strlen(s2));
	ft_memdel((void **)&s2);
}
