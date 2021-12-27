/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sstrnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadenho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 02:25:37 by jbadenho          #+#    #+#             */
/*   Updated: 2017/11/24 02:25:52 by jbadenho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
** The ft_sstrnew() allocate with malloc(3) a new char *s of size size_t size
**
** RETURN VALUES:
**  SUCCESS: char ** of size size_t size
**  FAILURE: NULL
*/

char	**ft_sstrnew(size_t size)
{
	char	**s;
	size_t	i;

	i = 0;
	if (!(s = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	while (i < (size))
		s[i++] = NULL;
	s[i] = NULL;
	return (s);
}
