/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:33:00 by dkotenko          #+#    #+#             */
/*   Updated: 2018/01/13 15:33:02 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strdup_acc(char *src, int acc)
{
	int		index;
	char	*line;

	line = (char*)malloc(sizeof(char) * acc + 1);
	if (line == NULL)
		return (NULL);
	index = 0;
	while (index < acc)
	{
		line[index] = src[index];
		index++;
	}
	line[index] = '\0';
	return (line);
}

char	*str_s(char **p, int acc, va_list ap)
{
	char	modifier;
	char	*str;

	modifier = 0;
	modif(*p, &modifier);
	str = NULL;
	if (modifier == 2 || modifier == 8)
		(*p) += 2;
	else if (modifier != 0)
		(*p)++;
	if (**p == 's')
	{
		str = ft_strdup(va_arg(ap, char*));
		if (acc == -1 && str == NULL)
			return (ft_strdup("(null)"));
		else if (str == NULL)
			return (ft_strdup(""));
		if (str != NULL && ft_strlen(str) > (size_t)acc && acc != -1)
			str = ft_strdup_acc(str, acc);
	}
	else if (modifier == 2 || modifier == 8)
		(*p) -= 2;
	else if (modifier != 0)
		(*p)--;
	return (str);
}
