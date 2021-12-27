/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 17:06:22 by wide-aze          #+#    #+#             */
/*   Updated: 2014/11/09 17:01:46 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnew(size_t size)
{
	char	*s;

	if (size == (size_t)-1)
		return (NULL);
	s = (char*)ft_memalloc(size + 1);
	if (s == NULL)
		return (NULL);
	return (s);
}
