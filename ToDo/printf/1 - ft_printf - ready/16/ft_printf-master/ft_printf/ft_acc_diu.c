/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_acc_diu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 13:31:23 by dkotenko          #+#    #+#             */
/*   Updated: 2018/01/12 13:31:24 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_acc_diu(char *str, int acc)
{
	int		len;
	char	*acc_str;
	char	*ptr;

	if (str[0] == '-')
		len = ft_strlen(str) - 1;
	else
		len = ft_strlen(str);
	if (acc == 0 && ft_strcmp(str, "0") == 0)
		return (ft_strdup("\0"));
	if (len < acc)
	{
		ptr = str;
		acc = acc - len;
		acc_str = (char*)malloc(sizeof(char) * (acc + 1));
		acc_str[acc] = '\0';
		while (acc > 0)
			acc_str[--acc] = '0';
		str = ft_strjoin(acc_str, str);
		if (ft_strchr(str, '-') != NULL)
			ft_swap_char(&str[0], ft_strchr(str, '-'));
		ft_strdel(&acc_str);
		ft_strdel(&ptr);
	}
	return (str);
}
