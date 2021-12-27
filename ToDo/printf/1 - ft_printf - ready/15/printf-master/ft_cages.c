/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemiy <artemiy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 00:32:15 by artemiy           #+#    #+#             */
/*   Updated: 2019/01/04 00:44:10 by artemiy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

char	*ft_cage_x(size_t slen, char *str)
{
	char	*new;

	if (!(new = ft_strnew(slen + 2)))
			return (NULL);
	new[0] = '0';
	new[1] = 'x';
	ft_strlcat(new + 2, str, slen + 1);
	free(str);
	return (new);
}

char	*ft_cage_X(size_t slen, char *str)
{
	char	*new;

	if (!(new = ft_strnew(slen + 2)))
			return (NULL);
	new[0] = '0';
	new[1] = 'X';
	ft_strlcat(new + 2, str, slen + 1);
	free(str);
	return (new);
}

char	*ft_cage_o(size_t slen, char *str)
{
	char	*new;

	if (!(new = ft_strnew(slen + 1)))
			return (NULL);
	new[0] = '0';
	ft_strlcat(new + 1, str, slen + 1);
	free(str);
	return (new);
}
