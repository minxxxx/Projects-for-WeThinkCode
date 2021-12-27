/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flagops.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thendric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 14:39:18 by thendric          #+#    #+#             */
/*   Updated: 2017/01/19 12:43:09 by thendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_flagspace(char *str)
{
	char	*new;

	if (ft_strcmp(str, ""))
		new = ft_strjoin(" ", str);
	else
		new = ft_strdup(str);
	ft_strdel(&str);
	return (new);
}

char	*ft_flagpound(t_input *input, char *str)
{
	char	*prefix;
	char	*new;

	prefix = ft_strnew(2);
	if (ft_getconversion(input->form) == 'x' && input->precision != 0)
		prefix = ft_strdup("0x");
	else if (ft_getconversion(input->form) == 'X' && input->precision != 0)
		prefix = ft_strdup("0X");
	else if (ft_getconversion(input->form) == 'o')
		prefix = ft_strdup("0");
	else if (ft_getconversion(input->form) == 'O')
		prefix = ft_strdup("0");
	new = ft_strjoin(prefix, str);
	if (new && ft_isupper(input->c))
		ft_touppercase(new);
	ft_strdel(&prefix);
	ft_strdel(&str);
	return (new);
}

char	*ft_flagplus(t_input *input, char *str)
{
	char	*new;

	new = ft_strjoin("+", str);
	input->flagplus = 0;
	ft_strdel(&str);
	return (new);
}

int		ft_widthoffset(t_input *input, char *str)
{
	int		offset;

	offset = ft_strlen(str);
	if (input->c == 'c' && !*str)
		offset += 1;
	if ((input->flagplus || input->negative) && str[0] != '-')
		offset += 1;
	if (input->flagpound && ft_tolower(input->c) == 'x'
		&& (input->flagminus || input->flagzero))
		offset += 2;
	if (input->flagpound && ft_tolower(input->c) == 'o'
		&& (input->flagminus || input->flagzero))
		offset += 1;
	return (offset);
}

char	*ft_flagwidth(t_input *input, char *str, int left)
{
	int		offset;
	char	fill;
	char	*addon;
	char	*new;

	fill = ' ';
	if (!input->flagminus && input->flagzero)
		fill = '0';
	if (input->precision != -1 && input->flagzero
		&& input->precision < input->width)
		fill = ' ';
	offset = ft_widthoffset(input, str);
	addon = ft_memalloc(input->width);
	if (input->width - offset > 0)
		ft_memset(addon, fill, input->width - offset);
	if (left)
		new = ft_strjoin(str, addon);
	else
		new = ft_strjoin(addon, str);
	ft_strdel(&addon);
	return (new);
}
