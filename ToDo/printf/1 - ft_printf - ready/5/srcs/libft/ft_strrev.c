/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thendric <thendric@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:37:19 by thendric          #+#    #+#             */
/*   Updated: 2016/11/06 23:37:10 by thendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	long	i;
	long	size;
	char	*rev;

	i = 0;
	size = (ft_strlen(str));
	rev = ft_strnew(size);
	while (--size >= 0)
	{
		rev[i] = str[size];
		i++;
	}
	return (rev);
}
