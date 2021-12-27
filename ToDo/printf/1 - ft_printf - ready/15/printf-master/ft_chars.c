/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemiy <artemiy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 18:58:24 by artemiy           #+#    #+#             */
/*   Updated: 2019/01/05 19:44:26 by artemiy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

char    *ft_get_char(t_specifier *spec, va_list *ap)
{
	char *c;

	(void)spec;
	c = ft_make_str(spec);
	if (!c)
		return (NULL);
	if (spec->flags->minus || !spec->width)
		c[0] = (unsigned char)va_arg(*ap, int);
	else
		c[spec->width - 1] = (unsigned char)va_arg(*ap, int);
	return (c);
}

char    *ft_get_str(t_specifier *spec, va_list *ap)
{
	char    *str;
	char    *dst;

	str = va_arg(*ap, char *);
	if (str == NULL)
	{
		dst = ft_strnew(6);
		if (spec->precition >= 6 || spec->precition < 0)
			dst = ft_strcpy(dst, "(null)");
		return (dst);
	}
	dst = ft_strnew(ft_strlen(str));
	if (!dst)
		return (NULL);
	if (spec->precition < (int)ft_strlen(str) && spec->precition >= 0)
	{
		dst = ft_strncpy(dst, str, spec->precition);
		return (dst);
	}
	else
		dst = ft_strcpy(dst, str);
	return (dst);
}

char    *ft_strreplace(char *source, char *replace, char *str)
{
	char                *ssub;
	char                *left;
	unsigned long       len;

	ssub = ft_strstr(source, replace);
	len = ssub - source;
	left = ft_strnew(len + ft_strlen(str) + ft_strlen(ssub + ft_strlen(replace)));
	left = ft_strncpy(left, source, len);
	left = ft_strcat(left, str);
	left = ft_strcat(left, ssub + ft_strlen(replace));
	return (left);
}

char    *ft_get_nonstr(char **str, char c)
{
	char    *nstr;
	char    *ch;
	char    *newch;
	char    *code;

	if (!(ch = ft_strnew(1)))
		return (NULL);
	ch[0] = c;
	code = ft_ullitoa_base((unsigned long long)c, "0123456789", 10);
	newch = ft_strjoin("\\", code);
	free(code);
	nstr = ft_strreplace(*str, ch, newch);
	free(*str);
	*str = nstr;
	free(ch);
	free(newch);
	return (*str);
}

char    *ft_get_nstr(t_specifier *spec, va_list *ap)
{
	char    *str;
	char    *start;
	char    *tmp;

	str = ft_get_str(spec, ap);
	if (!(tmp = ft_strnew(ft_strlen(str))))
	{
		free(str);
		return (NULL);
	}
	tmp = ft_strcpy(tmp, str);
	start = tmp;
	while (*tmp)
	{
		if ((*tmp >= 0 && *tmp <= 31) || *tmp == 127)
			str = ft_get_nonstr(&str, *tmp);
		tmp++;
	}
	free(start);
	return (str);
}
