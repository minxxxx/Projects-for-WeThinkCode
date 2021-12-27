/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 09:44:22 by wide-aze          #+#    #+#             */
/*   Updated: 2015/08/13 22:23:37 by dw31             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char	*ft_strjoin_free(char *s1, char const *s2)
{
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	if (!(str = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	str = ft_strcpy(str, s1);
	str = ft_strcat(str, s2);
	free(s1);
	return (str);
}
