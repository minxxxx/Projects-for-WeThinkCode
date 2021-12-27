/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 13:28:50 by dkotenko          #+#    #+#             */
/*   Updated: 2018/01/12 13:28:51 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*w_flg(char *str, char *str_width, int len)
{
	while (str_width[len] != '\0')
		str_width[len++] = '0';
	str = ft_strjoin(str_width, str);
	if (ft_strchr(str, '-') != NULL)
		ft_swap_char(&str[0], ft_strchr(str, '-'));
	else if (ft_strchr(str, '+') != NULL)
		ft_swap_char(&str[0], ft_strchr(str, '+'));
	else if (ft_strchr(str, ' ') != NULL)
		ft_swap_char(&str[0], ft_strchr(str, ' '));
	return (str);
}

char	*ft_width(char *str, char flg, int width, int acc)
{
	int		len;
	char	*str_width;
	char	*buff_ptr;

	if (ft_strlen(str) < (size_t)width)
	{
		buff_ptr = str;
		len = width - ft_strlen(str);
		str_width = (char*)malloc(sizeof(char) * (len + 1));
		str_width[len] = '\0';
		while (len > 0)
			str_width[--len] = ' ';
		if (flg & 1)
			str = ft_strjoin(str, str_width);
		else if (((flg >> 4) & 1) && acc == -1)
			str = w_flg(str, str_width, len);
		else
			str = ft_strjoin(str_width, str);
		ft_strdel(&buff_ptr);
		ft_strdel(&str_width);
	}
	return (str);
}

char	*ft_width_c(char *str, char flg, int width)
{
	int		len;
	char	*str_width;
	char	*buff_ptr;

	if (ft_strlen(str) < (size_t)width)
	{
		buff_ptr = str;
		len = width - ft_strlen(str);
		str_width = (char*)malloc(sizeof(char) * (len + 1));
		str_width[len] = '\0';
		while (len > 0)
		{
			if ((flg >> 4) & 1)
				str_width[--len] = '0';
			else
				str_width[--len] = ' ';
		}
		if (flg & 1)
			str = ft_strjoin(str, str_width);
		else
			str = ft_strjoin(str_width, str);
		ft_strdel(&buff_ptr);
		ft_strdel(&str_width);
	}
	return (str);
}
