/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_strsub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 08:25:41 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/31 08:30:28 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*v_strsub(char *str, unsigned int start, size_t len)
{
	char	*new;

	if (!str)
		return (NULL);
	new = v_strnew(len);
	return (ft_strncat(new, str + start, len));
}
