/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadenho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 02:24:40 by jbadenho          #+#    #+#             */
/*   Updated: 2017/11/24 02:24:42 by jbadenho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*set;

	if (!(set = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_memset(set, '\0', size + 1);
	return (set);
}
