/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:14 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 17:34:19 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

char	*insert_char(char *str, int index, char c)
{
	char *ret;

	ret = (char*)mallocp(sizeof(char) * (ft_strlen(str) + 2));
	ft_strncpy(ret, str, index);
	ret[index] = c;
	ft_strcpy(ret + index + 1, str + index);
	free(str);
	return (ret);
}

char	*delete_char(char *str, int index)
{
	char *ret;

	ret = (char*)mallocp(sizeof(char) * ft_strlen(str));
	ft_strncpy(ret, str, index - 1);
	ft_strcpy(ret + index - 1, str + index);
	free(str);
	return (ret);
}
