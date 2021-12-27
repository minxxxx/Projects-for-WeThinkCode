/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 19:28:15 by sasiedu           #+#    #+#             */
/*   Updated: 2016/07/25 19:38:32 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_build_path(char *full_path, char *ext_path)
{
	size_t	i;
	char	*new_path;

	i = ft_strlen(full_path) - 1;
	if (full_path[i] == '/' && ext_path[0] == '/')
		new_path = ft_strjoin(full_path, &ext_path[1]);
	else if (full_path[i] != '/' && ext_path[0] != '/')
		new_path = ft_strjoin(ft_strjoin(full_path, "/"), ext_path);
	else
		new_path = ft_strjoin(full_path, ext_path);
	return (new_path);
}
