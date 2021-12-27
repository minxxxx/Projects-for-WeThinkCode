/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadenho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 02:07:18 by jbadenho          #+#    #+#             */
/*   Updated: 2017/11/24 02:09:49 by jbadenho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char const		*ft_getenv(t_sub key)
{
	int							i;
	extern char const *const	*environ;

	i = -1;
	while (environ[++i] != NULL)
		if (ft_memcmp(environ[i], key.str, key.length) == 0
				&& environ[i][key.length] == '=')
			return (environ[i] + key.length + 1);
	return (NULL);
}
