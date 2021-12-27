/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 19:18:50 by jcamhi            #+#    #+#             */
/*   Updated: 2016/01/19 15:26:34 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_alloc_str(const char *str)
{
	char	*truc;

	if (str == NULL)
		return (ft_alloc_str("(null)"));
	truc = (char*)malloc(ft_strlen(str) + 1);
	ft_strcpy(truc, str);
	return (truc);
}
