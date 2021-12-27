/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 12:07:58 by opodolia          #+#    #+#             */
/*   Updated: 2017/03/16 14:03:13 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_reg_mbstr(char *new_str)
{
	int		i;
	int		j;

	i = 0;
	while (new_str[i])
	{
		if ((j = ft_is_mb(&new_str[i])))
			i += j;
		else
		{
			new_str[i] = '\0';
			break ;
		}
	}
	return (new_str);
}

static char	*ft_reg_str(t_mods *mods, char *str)
{
	int		i;
	char	*new_str;

	if (mods->precision > -1)
	{
		i = -1;
		new_str = (char *)malloc(sizeof(char) * (mods->precision + 1));
		while (++i < mods->precision)
			new_str[i] = str[i];
		new_str[i] = '\0';
		new_str = ft_reg_mbstr(new_str);
		mods->precision = -1;
		free(str);
		return (new_str);
	}
	else
		return (str);
}

static char	*ft_get_unprint_str(va_list ap)
{
	char	*s;
	char	*str;
	int		i;

	s = va_arg(ap, char *);
	if (!s[0] && !s[1])
		str = ft_strdup("\\0");
	else
	{
		i = -1;
		str = (char *)malloc(sizeof(char));
		while (s[++i] || (s[i] == '\0' && s[i + 1]))
		{
			if (ft_strchr("\a\b\t\n\v\f\r\"\\", s[i]))
				str = ft_strjoin_free(str, ft_unprint(s, i));
			else
				str = ft_strjoin_free(str, ft_memset(ft_memalloc(2), s[i], 1));
		}
	}
	return (str);
}

static char	*ft_get_str(va_list ap, t_mods *mods)
{
	wchar_t	*old_wstr;
	char	*old_str;
	char	*str;

	if (mods->length == l)
	{
		if ((old_wstr = va_arg(ap, wchar_t *)) == NULL)
			str = ft_strdup("(null)");
		else
		{
			str = (char *)malloc(sizeof(char) * (ft_wcslen(old_wstr) + 1));
			ft_wcstombs(str, old_wstr, ft_wcslen(old_wstr) + 1);
		}
	}
	else
	{
		if ((old_str = va_arg(ap, char *)) == NULL)
			str = ft_strdup("(null)");
		else
			str = ft_strdup(old_str);
	}
	if (!(str = ft_reg_str(mods, str)))
		return (NULL);
	return (str);
}

int			ft_str(va_list ap, t_mods *mods)
{
	int		size;
	char	*str;
	char	*mas;

	if (mods->flags.unread == 1)
		str = ft_get_unprint_str(ap);
	else
		str = ft_get_str(ap, mods);
	mods->flags.plus = 0;
	mods->flags.space = 0;
	mods->flags.hash = 0;
	mods->length = 0;
	size = (mods->width < (int)ft_strlen(str)) ? (int)ft_strlen(str) :
		mods->width;
	mas = (char *)malloc(sizeof(char) * (size + 1));
	mods->flags.left ? ft_push_left(mods, &mas, size, str) :
		ft_push_right(mods, &mas, size, str);
	ft_putstr(mas);
	free(str);
	free(mas);
	return (size);
}
