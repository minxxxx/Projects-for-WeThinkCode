/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:21:47 by juspende          #+#    #+#             */
/*   Updated: 2017/12/06 08:59:45 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../../include/ft_printf.h"

void	ft_printchar(char c, t_flag *flag)
{
	size_t			i;
	char			*tmp;

	i = flag->charn;
	if ((tmp = malloc(sizeof(char) * (i + 2))) == NULL)
		return ;
	tmp[0] = '\0';
	ft_strcat(tmp, flag->printed);
	free(flag->printed);
	i = flag->charn;
	tmp[i] = c;
	tmp[i + 1] = '\0';
	flag->printed = ft_strdup(tmp);
	free(tmp);
	flag->charn += 1;
}

void	ft_putnstr(void *str, t_flag *flag, int *c)
{
	size_t	i;
	size_t	n;
	char	*tmp;

	i = ft_strlen(flag->printed);
	n = ft_strchr(str, 37);
	if ((tmp = malloc(sizeof(char) * (i + n + 2))) == NULL)
		return ;
	tmp[0] = '\0';
	ft_strcat(tmp, flag->printed);
	ft_strncat(tmp, str, n);
	free(flag->printed);
	flag->printed = ft_strdup(tmp);
	free(tmp);
	flag->charn += n;
	if (*c != -1)
		*c += (n - 1);
	return ;
}

void	ft_printwchar(char c, t_flag *flag)
{
	empty_buffer(flag);
	write(1, &c, 1);
}

void	ft_putchar(wchar_t c, t_flag *flag)
{
	if (c <= 0x7F)
		ft_printchar(c, flag);
	else if (c <= 0x7FF)
	{
		ft_printwchar((c >> 6) | 0xC0, flag);
		ft_printwchar((c & 0x3F) | 0x80, flag);
	}
	else if (c <= 0xFFFF)
	{
		ft_printwchar((c >> 12) | 0xE0, flag);
		ft_printwchar(((c >> 6) & 0x3F) | 0x80, flag);
		ft_printwchar((c & 0x3F) | 0x80, flag);
	}
	else if (c <= 0x10FFFF)
	{
		ft_printwchar((c >> 18) | 0xF0, flag);
		ft_printwchar(((c >> 12) & 0x3F) | 0x80, flag);
		ft_printwchar(((c >> 6) & 0x3F) | 0x80, flag);
		ft_printwchar((c & 0x3F) | 0x80, flag);
	}
}

void	ft_putchar_s(wchar_t c, t_flag *flag)
{
	if (c <= 0x7F)
		ft_printwchar(c, flag);
	else if (c <= 0x7FF)
	{
		ft_printwchar((c >> 6) + 0xC0, flag);
		ft_printwchar((c & 0x3F) + 0x80, flag);
	}
	else if (c <= 0xFFFF)
	{
		ft_printwchar((c >> 12) + 0xE0, flag);
		ft_printwchar(((c >> 6) & 0x3F) + 0x80, flag);
		ft_printwchar((c & 0x3F) + 0x80, flag);
	}
	else if (c <= 0x10FFFF)
	{
		ft_printwchar((c >> 18) + 0xF0, flag);
		ft_printwchar(((c >> 12) & 0x3F) + 0x80, flag);
		ft_printwchar(((c >> 6) & 0x3F) + 0x80, flag);
		ft_printwchar((c & 0x3F) + 0x80, flag);
	}
}
