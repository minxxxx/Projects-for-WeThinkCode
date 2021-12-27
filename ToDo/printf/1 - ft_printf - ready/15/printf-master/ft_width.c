/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemiy <artemiy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 15:28:25 by artemiy           #+#    #+#             */
/*   Updated: 2019/01/04 00:44:07 by artemiy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

char	*ft_strchrjoin(char *str, char c)
{
	char	*new;

	if (!(new = ft_strnew(ft_strlen(str) + 1)))
		return (NULL);
	new[0] = c;
	ft_strcat(new, str);
	return (new);
}

char	*ft_manage_pw(char *str, int pw, int len)
{
	char	*zeros;
	char	*new;
	char	*tmp;

	zeros = ft_fillstr(pw - len, '0');
	tmp = zeros;
	if (ft_strchr("-+ ", *str))
	{
		tmp = ft_strchrjoin(zeros, *str);
		free(zeros);
		new = ft_strjoin(tmp, str + 1);
	}
	else
		new = ft_strjoin(tmp, str);
	free(str);
	free(tmp);
	return (new);
}

char	*ft_str_add_zeros(char *str, int n, t_specifier *spec)
{
	char	*zeros;
	char	*new;

	if (ft_strchr("dif", spec->specifier) && ft_strchr("-+ ", *str))
		new = ft_manage_pw(str, spec->width, ft_strlen(str));
	else
	{
		if (!(zeros = ft_fillstr(n, '0')))
			return (NULL);
		if (!(new = ft_strjoin(zeros, str)))
			return (NULL);
		free(str);
		free(zeros);
	}
	return (new);
}

char	*ft_str_add_spaces(char *str, int n)
{
	char	*spaces;
	char	*new;

	if (!(spaces = ft_fillstr(n, ' ')))
		return (NULL);
	if (!(new = ft_strjoin(str, spaces)))
		return (NULL);
	free(str);
	free(spaces);
	return (new);
}

char	*ft_str_add_left_spaces(char *str, int n)
{
	char	*spaces;
	char	*new;

	if (!(spaces = ft_fillstr(n, ' ')))
		return (NULL);
	if (!(new = ft_strjoin(spaces, str)))
		return (NULL);
	free(str);
	free(spaces);
	return (new);
}
