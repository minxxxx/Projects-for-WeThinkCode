/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfavero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 13:59:34 by cfavero           #+#    #+#             */
/*   Updated: 2017/11/27 16:34:47 by cfavero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	if (!(s1 && s2))
		return (0);
	i = 0;
	if (n == 0)
		return (1);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < (n - 1))
		i++;
	if (s1[i] == s2[i])
		return (1);
	else
		return (0);
}
