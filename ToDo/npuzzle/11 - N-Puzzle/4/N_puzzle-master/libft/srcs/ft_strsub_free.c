/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 13:51:06 by ggroener          #+#    #+#             */
/*   Updated: 2016/06/24 13:53:26 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub_free(char const *s, unsigned int start, size_t len)
{
	char	*result;

	result = ft_strsub(s, start, len);
	free((void*)s);
	return (result);
}
