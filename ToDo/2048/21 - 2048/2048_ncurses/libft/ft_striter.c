/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/14 10:12:33 by glarivie          #+#    #+#             */
/*   Updated: 2015/11/25 16:59:06 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	int		index;

	index = -1;
	if (s == NULL || f == NULL)
		return ;
	while (s[++index])
		(*f)(&s[index]);
}
