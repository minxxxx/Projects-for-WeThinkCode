/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_nolimit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 20:11:34 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/21 20:13:07 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_shift(char *s, char *trimmers, int *length)
{
	int		end;
	int		i;

	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'
				|| ft_strchr(trimmers, s[i])))
		i++;
	if (ft_strlen(&s[i]) == 0)
	{
		*length = 0;
		return (0);
	}
	end = ft_strlen(s) - 1;
	while (end > 0 && (s[end] == ' ' || s[end] == '\t'
				|| s[end] == '\n' || ft_strchr(trimmers, s[end])))
		end--;
	*length = end - i;
	return (i);
}

char			*ft_strtrim_nolimit(char *s, ...)
{
	int		i;
	char	*new;
	char	*trimmers;
	va_list	args;
	char	new_arg;

	va_start(args, s);
	trimmers = ft_strnew(1);
	i = 0;
	while ((new_arg = va_arg(args, int)))
	{
		trimmers[i++] = new_arg;
		trimmers = ft_str_realloc(trimmers, ft_strlen(trimmers) + 1);
	}
	s = s + get_shift(s, trimmers, &i);
	if (i == 0)
		return (new = ft_strnew(0));
	new = ft_strnew(i + 1);
	while (i >= 0)
	{
		new[i] = s[i];
		i--;
	}
	va_end(args);
	return (new);
}
