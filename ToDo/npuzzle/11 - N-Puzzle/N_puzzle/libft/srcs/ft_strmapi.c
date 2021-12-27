/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 07:23:32 by ggroener          #+#    #+#             */
/*   Updated: 2016/05/22 12:19:29 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_ptr;
	size_t	i;

	i = 0;
	new_ptr = NULL;
	if (s && f && (new_ptr = (char*)malloc((ft_strlen(s) + 1) * sizeof(char))))
	{
		while (i < ft_strlen(s))
		{
			new_ptr[i] = f(i, s[i]);
			i++;
		}
		new_ptr[i] = '\0';
	}
	return (new_ptr);
}
