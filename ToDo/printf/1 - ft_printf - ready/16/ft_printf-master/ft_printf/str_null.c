/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_null.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 13:01:04 by dkotenko          #+#    #+#             */
/*   Updated: 2018/01/17 13:01:06 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*str_null(char **p)
{
	char			modifier;
	char			*str;

	modifier = 0;
	modif(*p, &modifier);
	str = NULL;
	if (modifier == 2 || modifier == 8)
		(*p) += 2;
	else if (modifier != 0)
		(*p)++;
	str = (char*)malloc(sizeof(char) * 2);
	str[0] = **p;
	str[1] = '\0';
	return (str);
}
