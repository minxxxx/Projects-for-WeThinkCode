/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 19:18:50 by jcamhi            #+#    #+#             */
/*   Updated: 2016/01/18 12:29:32 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_alloc_str(const char *str)
{
	char	*truc;

	if (str == NULL)
		return (ft_alloc_str("(null)"));
	truc = (char*)mallocp(ft_strlen(str) + 1);
	ft_strcpy(truc, str);
	return (truc);
}
