/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_conv_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 11:29:46 by jcamhi            #+#    #+#             */
/*   Updated: 2016/01/18 23:08:53 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char		*ft_with_z(const t_arg arg, va_list list)
{
	char	*ret;

	if (arg.conv == 'd' || arg.conv == 'D' || arg.conv == 'i')
		ret = ft_itoa_base_ll((long long)va_arg(list, ssize_t), 10);
	else if (arg.conv == 'o' || arg.conv == 'O')
		ret = ft_itoa_base_ull((unsigned long long)
				va_arg(list, size_t), 8);
	else if (arg.conv == 'u' || arg.conv == 'U')
		ret = ft_itoa_base_ull((unsigned long long)
				va_arg(list, size_t), 10);
	else if (arg.conv == 'x')
		ret = ft_itoa_base_ull((unsigned long long)
				va_arg(list, size_t), 16);
	else if (arg.conv == 'X')
		ret = ft_strtoupper(ft_itoa_base_ull((unsigned long long)
					va_arg(list, size_t), 16));
	else
		ret = ft_alloc_str("Error");
	return (ret);
}

static char	*ft_seconde_partie(int c, char *ret)
{
	if (c < 0x010000)
	{
		ret[0] = ((c >> 12 & 0x0F) | 0xE0);
		ret[1] = ((c >> 6 & 0x3F) | 0x80);
		ret[2] = ((c >> 0 & 0x3F) | 0x80);
		ret[3] = 0;
	}
	else if (c < 0x110000)
	{
		ret[0] = ((c >> 18 & 0x07) | 0xF0);
		ret[1] = ((c >> 12 & 0x3F) | 0x80);
		ret[2] = ((c >> 6 & 0x3F) | 0x80);
		ret[3] = ((c >> 0 & 0x3F) | 0x80);
	}
	return (ret);
}

char		*ft_wchart_to_char(wchar_t c)
{
	char	*ret;

	ret = (char*)malloc(5 * sizeof(char));
	if (c < 0x80)
	{
		ret[0] = ((c >> 0 & 0x7F) | 0x00);
		ret[1] = 0;
		ret[2] = 0;
		ret[3] = 0;
	}
	else if (c < 0x0800)
	{
		ret[0] = ((c >> 6 & 0x1F) | 0xC0);
		ret[1] = ((c >> 0 & 0x3F) | 0x80);
		ret[2] = 0;
		ret[3] = 0;
	}
	else
		ret = ft_seconde_partie(c, ret);
	ret[4] = '\0';
	return (ret);
}

char		*ft_wchart_to_str(wchar_t *ws)
{
	char	*s;
	int		i;
	int		n;

	n = 0;
	i = 0;
	if (ws == NULL)
		return (ft_alloc_str("(null)"));
	if (ws[0] == L'\0')
		return (ft_alloc_str(""));
	while (ws[n] != L'\0')
	{
		if (ws[n] <= 127)
			s = (i == 1 ?
					ft_strjoinaf12(s, ft_alloc_str_with_char((char)ws[n])) :
					ft_strjoinaf2("\0", ft_alloc_str_with_char((char)ws[n])));
		else
			s = (i == 1 ? ft_strjoinaf12(s, ft_wchart_to_char((wchar_t)ws[n])) :
					ft_strjoinaf2("\0", ft_wchart_to_char((wchar_t)ws[n])));
		i = 1;
		n++;
	}
	return (s);
}
