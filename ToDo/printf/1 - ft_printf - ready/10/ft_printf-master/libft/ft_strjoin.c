/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 12:29:58 by tfleming          #+#    #+#             */
/*   Updated: 2014/11/08 17:50:35 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoin(char const *first, char const *second)
{
	char	*both;
	size_t	first_len;
	size_t	second_len;

	first_len = ft_strlen(first);
	second_len = ft_strlen(second);
	both = malloc(sizeof(char) * (first_len + 1 + second_len));
	if (!both)
		return (NULL);
	ft_strncpy(both, first, first_len);
	ft_strcpy(both + first_len, second);
	return (both);
}
