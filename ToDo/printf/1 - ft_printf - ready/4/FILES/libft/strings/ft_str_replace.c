/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_replace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 15:00:52 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/27 16:31:16 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_replace(char *origin, char *rep, char *with)
{
	char	*start;
	size_t	size_rep;
	char	*new;

	if (!(start = ft_strstr(origin, rep)))
		return (origin);
	size_rep = ft_strlen(rep);
	new = ft_strnew(ft_strlen(origin) - ft_strlen(rep) + ft_strlen(with));
	ft_strncpy(new, origin, start - origin);
	ft_strcat(new, with);
	ft_strcat(new, start + size_rep);
	return (new);
}
