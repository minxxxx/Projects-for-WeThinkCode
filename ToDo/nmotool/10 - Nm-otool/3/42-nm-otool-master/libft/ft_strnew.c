/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 15:18:08 by jtranchi          #+#    #+#             */
/*   Updated: 2016/01/28 18:31:48 by jtranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnew(size_t size)
{
	char	*s;
	int		i;

	s = (char *)malloc(sizeof(*s) * (size + 1));
	if (s == NULL)
		return (NULL);
	i = 0;
	while ((size_t)i <= size)
		s[i++] = 0;
	return (s);
}
