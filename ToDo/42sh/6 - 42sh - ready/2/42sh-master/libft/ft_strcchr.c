/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadenho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 02:26:33 by jbadenho          #+#    #+#             */
/*   Updated: 2017/11/24 02:26:35 by jbadenho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcchr(const char *s, char c)
{
	char *ptr;

	ptr = (char*)s;
	while (*ptr && *ptr != c)
		ptr++;
	if (*ptr == c)
		return (ptr);
	else
		return (NULL);
}
