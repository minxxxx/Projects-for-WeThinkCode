/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 18:56:43 by tfleming          #+#    #+#             */
/*   Updated: 2014/11/07 15:01:38 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strdup(const char *source)
{
	char	*new;

	new = malloc(ft_strlen(source) + 1);
	if (new == NULL)
		return (NULL);
	ft_strcpy(new, source);
	return (new);
}
