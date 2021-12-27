/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_strjoin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 08:25:19 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/31 08:30:07 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*v_strjoin(char *s1, char *s2)
{
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	new = v_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	new = ft_strcpy(new, s1);
	return (ft_strcat(new, s2));
}
